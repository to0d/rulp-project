#include "lfc/base/file.h"
#include "lfc/base/string/util.h"
#include "lfc/base/system.h"
#include "lfc/base/trace.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>  
#include <sys/stat.h>
#include <assert.h>
#include <iostream>
#include <limits.h>


namespace lfc {

bool FileSystem::isSupportFile(const std::string& path) {
  if(is_file_exist(path))
    return true;

  if(is_folder_exist(path)){

#ifdef __linux__

    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    // 打开文件夹
    if ((dir = opendir(path.c_str())) == NULL) {
      if(LFC_TRACE_ENABLE){
        perror("opendir");
      }
      return false;
    }

    std::vector<std::string> child_paths;
    int err = 0;

    // 遍历文件夹中的每一项
    while ((entry = readdir(dir)) != NULL) {
      char fullpath[1024];
      snprintf(fullpath, sizeof(fullpath), "%s/%s", path.c_str(), entry->d_name);

      // 获取文件/文件夹信息
      if (lstat(fullpath, &statbuf) == -1) {
        if(LFC_TRACE_ENABLE){
          perror("lstat");
        }
        err++;
        break;
      }

      // 跳过当前目录（.）和上级目录（..）
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        continue;
      }

      child_paths.push_back(std::string(fullpath));

    }

    // 关闭文件夹
    closedir(dir);

    if(err > 0)
      return false;

    for(auto child : child_paths){
      if(!isSupportFile(child))
        return false;
    }

    return true;

#else
    static_assert(false && " not support file system");
    return false;  
#endif
  }

  return false;
}


static int DeleteDirectory(const char *path) {
  DIR *dir;
  struct dirent *entry;
  struct stat statbuf;

  // 打开文件夹
  if ((dir = opendir(path)) == NULL) {
    perror("opendir");
    return 1;
  }

  int err = 0;

  // 遍历文件夹中的每一项
  while ((entry = readdir(dir)) != NULL) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

    // 获取文件/文件夹信息
    if (lstat(fullpath, &statbuf) == -1) {
      if(LFC_TRACE_ENABLE){
        perror("lstat");
      }
      ++err;
      continue;
    }

    // 跳过当前目录（.）和上级目录（..）
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // 如果是文件夹，递归删除
    if (S_ISDIR(statbuf.st_mode)) {
      err += DeleteDirectory(fullpath);
    }
    // 如果是文件，直接删除
    else {
      if (unlink(path) == -1) {
        perror("unlink");
        ++err;
      } 
    }
  }

  // 关闭文件夹
  closedir(dir);

  // 删除空文件夹
  if (rmdir(path) == -1) {
    perror("rmdir");
    ++err;
  }

  return err;
}


bool FileSystem::deleteFile(const std::string& path) {

  // std::cout << "deleteFile" << path << "\n";

  if (!FileSystem::isSupportFile(path)) {
    return false;
  }

  if (FS_FILE_EXIST(path)) {
    // std::cout << "delete file" << path << "\n";
    if (unlink(path.c_str()) == -1) {
      perror("unlink");
      return false;
    }
    
    return true;
  } 

  if(FS_FOLDER_EXIST(path)) {
    // std::cout << "delete folder" << path << "\n";
    return DeleteDirectory(path.c_str()) == 0;
  }
  
  return false;
}

std::string FileSystem::get_dir_separator() {

#if (defined _WIN32) || (defined _WIN64)
  return "\\";
#endif

#ifdef __linux__
  return "/";
#endif

}

std::string FileSystem::get_relative_path(const std::string& base, const std::string& path){

  if(base.empty() || base == "/")
    return path;

  if(base[base.length()-1] != '/'){
    return get_relative_path(base+"/", path);
  }

  if(str_start_With(path, base)){
    return path.substr(base.length());
  }

  return path;
}

// 获取文件的父文件夹路径
static char* GetParentDirectory(const char *path) {
  char absolute_path[PATH_MAX];

  // 将路径转换为绝对路径
  if (realpath(path, absolute_path) == NULL) {
    perror("realpath");
    return NULL;
  }

  // 找到最后一个 '/' 的位置
  char *last_slash = strrchr(absolute_path, '/');
  if (last_slash == NULL) {
    // 如果没有 '/'，说明路径是当前目录（如 "file.txt"）
    return strdup(".");
  }

  // 如果最后一个 '/' 是根目录（如 "/file.txt"），则父文件夹是根目录 "/"
  if (last_slash == absolute_path) {
    last_slash[1] = '\0'; // 保留根目录
  } 
  else {
    *last_slash = '\0'; // 截断路径，保留父文件夹
  }

  return strdup(absolute_path);
}

std::string FileSystem::get_file_parent(const std::string& path) {
  char* parent = GetParentDirectory(path.c_str());
  std::string parent_str(parent);
  free(parent);
  return parent_str;
}

std::string FileSystem::get_current_dir() {
  char buffer[PATH_MAX]; // PATH_MAX 是系统定义的最大路径长度
  if (getcwd(buffer, sizeof(buffer)) != nullptr) {
    return std::string(buffer); // 将字符数组转换为 std::string
  } 
  else {
    perror("getcwd() 错误"); // 如果出错，打印错误信息
    return ""; // 返回空字符串表示失败
  }
}

std::string FileSystem::get_home_dir() {

  const char* homeDir = nullptr;
  
  // 在Windows上
  #ifdef _WIN32
    homeDir = getenv("USERPROFILE");
  // 或者在较新版本中也可以使用"HOME"
  
  // 在Unix/Linux/Mac上
  #else
    homeDir = getenv("HOME");
  #endif

  return toValidPath(std::string(homeDir));
}

bool FileSystem::is_file_exist(const std::string& path){
  struct stat statbuf;

  // 获取文件/文件夹信息
  if (lstat(path.c_str(), &statbuf) == -1) {
    if(LFC_TRACE_ENABLE){
      perror("lstat");
    }
    return false;
  }

  // 如果是文件，直接删除
  if (S_ISREG(statbuf.st_mode)) {
    return true;
  }

  return false;
}

bool FileSystem::is_folder_exist(const std::string& path){
  struct stat info;
  if (stat(path.c_str(), &info) != 0) {
    return false; // 无法访问路径
  }
  return (info.st_mode & S_IFDIR) != 0; // 检查是否是目录
}

bool FileSystem::is_abs_path(const std::string& path) {

  if (path.empty()) {
    return false;
  }

  std::string new_path = STR_TRIM(path);
  if (new_path.empty()) {
    return false;
  }

  assert(SYS_IS_LINUX);

  char firstChar = path.at(0);

  // if (SystemUtil.getOSType() == OSType.Win) {

  //   if (path.length() < 3) {
  //     return false;
  //   }

  //   if (!path.subSequence(1, 3).equals(":\\")) {
  //     return false;
  //   }

  //   return firstChar >= 'C' && firstChar <= 'Z' && path.length() >= 3 && path.subSequence(1, 3).equals(":\\");

  // } 
  // else {

  return firstChar == '/';
  // }
}

std::vector<std::string> FileSystem::list_child_files(const std::string& path) {

  DIR *dir;
  struct dirent *entry;
  struct stat statbuf;

  // 打开文件夹
  if ((dir = opendir(path.c_str())) == NULL) {
    if(LFC_TRACE_ENABLE){
      perror("opendir");
    }
    return {};
  }

  std::vector<std::string> childFiles;

  // 遍历文件夹中的每一项
  while ((entry = readdir(dir)) != NULL) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", path.c_str(), entry->d_name);

    // 获取文件/文件夹信息
    if (lstat(fullpath, &statbuf) == -1) {
      perror("lstat");
      continue;
    }

    // 跳过当前目录（.）和上级目录（..）
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    childFiles.push_back(std::string(fullpath));
  }

  // 关闭文件夹
  closedir(dir);

  return std::move(childFiles);
}

std::vector<std::string> openTxtFile(const std::string& path, const std::string& charset, bool ignore_tail_blank_line) {

  std::ifstream in_file(path);
  if (!in_file.is_open()){
    std::cerr << "fail to open file: " << path << "\n";
    return {};
  }

  std::vector<std::string> lines;

  std::string line;
  int count = 0;
  while (std::getline(in_file, line)) {
    auto line2 = STR_TRIM_END_NEWLINE(line);
    if(ignore_tail_blank_line && line2.empty()){
      continue;
    }
    lines.push_back(line2);
  }

  in_file.close(); 

  return lines;
}

std::string FileSystem::get_file_name(const std::string& path){
  char path_separator = '/';
#if (defined _WIN32) || (defined _WIN64)
  path_separator = '\\';
#endif
  const char* pos = ch_memrchr(path.c_str(), path_separator, path.length());
  if( pos == NULL || pos == path.c_str()){
    return path;
  }

  return std::string(pos+1);
}

/*********************************************************************/
/* return:                                                           */
/*          0:  succ                                                 */
/*          1:  path already exist                                   */
/*          2:  target path is file which already exist              */
/*          3:  Invalid path name                                    */
/*          4:  Fail to call getcwd                                  */
/*          5:  Duplicate name with a file                           */
/*          6:  No authority to mkdir                                */
/*         99:  Internal error                                       */ 
/*         -1:  Fail to create path, unknown reason                  */
/*********************************************************************/
int mkdirs(const char* path){

#define MAX_PATH_LEN    5000

  char curPath[MAX_PATH_LEN] = {'\0'};
  char tgtPath[MAX_PATH_LEN] = {'\0'};
  int pos, len, tgtLen, i;
  char c;
  struct stat info;

  if( path == NULL || (len = strlen(path)) == 0 )
  {   return 3;        
  }

  // remove header blank
  for( pos = 0; pos < len && path[pos] == ' ' ; ++pos)
    ;

  // path is an empty string 
  if( pos == len ){
    return 3;
  }

  // get and save current path
  if( getcwd(curPath, sizeof(curPath)-1) == NULL ){
    return 4;
  }

  // relative path
  if( path[pos] != '/' ){
    strcat(tgtPath, curPath);
    strcat(tgtPath, "/");
  }
  strcat(tgtPath, path+pos);

  // Simplify Path
  if( (tgtLen=simplify_path(tgtPath)) <= 0 ){
    return 99;
  }

  for( i = 1; i <= tgtLen; tgtPath[i++] = c ) {

    if( (c=tgtPath[i]) == '/' || c == '\0') {              
      tgtPath[i] = '\0';
      if ( stat(tgtPath, &info ) == 0 )   // exist
      {
          if( S_ISDIR(info.st_mode) != 0) // Is Dir
              continue;
          else 
              return 5;   // Is File      
      }

      // Mode: drwx------
      if( mkdir( tgtPath, S_IRWXU ) != 0 ) 
          return -1;
    }        
  }
  
  return 0;
}

int is_dir(const char* path)
{
  struct stat info;
  
  if( path == NULL || strlen(path) == 0 )
      return -1;
  
  if ( stat(path, &info ) != 0 ) // no exist 
  {   return -2;
  }
  
  if( S_ISDIR(info.st_mode) == 0 )  // Is file
  {   return 1;        
  }
  
  return 0;
}

int rm_dir(char * path)  
{  
    char buffer[5000];
    DIR * dir = NULL;  
    struct dirent *ptr;  
    int rc; 

    if( path == NULL || strlen(path) == 0 )
        return -1;
    
    if( (dir = opendir(path)) == NULL )  
    {   return -2;  
    }
    
    while((ptr = readdir(dir)) != NULL)  
    {   
        if( strcmp(ptr->d_name, ".") == 0 
         || strcmp(ptr->d_name, "..") == 0 )  
            continue;   

        rc = snprintf( buffer
                     , sizeof(buffer)
                     , "%s/%s"
                     , path
                     , ptr->d_name);
        if( rc < 0 )
        {   return -3;
        }
        
        rc = is_dir(buffer);        
        if( rc == 0 )   // Is Dir
        {   if( rm_dir(buffer) != 0 )
            {   return -4;                
            }            
        }
        else if( rc == 1 ) // Is File
        {   if( remove(buffer) != 0 )
            {   return -5;
            }
        }
        else // Error
        {   return -6;            
        } 
    }
    
    closedir(dir); 

    if( rmdir(path) != 0 )
    {   return -7;
    }
    return 0;  
}

int simplify_path(char* path){
  char* stack[1024];
  char c, *p1, *p2;
  int n;
  
  if( path == NULL || path[0] != '/' )
    return -1;
  
  p1 = path;
INIT:p2 = path;
  n  = 0;
STR:while(( c = *p1++ ) != '\0' ){   
  switch(c){ 
    case '/':
NEXT:   stack[n++] = p2;
        *(p2++) = '/';
SKIP:   for( ; *p1 == '/'; ++p1 );
          break;
    case '.':
        // a.b/ or a./
        if( p2 > path && *(p2-1) != '/' ){
UNTIL:    while((*(p2++) = c)){
            switch((c=*p1++)){
              case '/' :  goto NEXT;
              case '\0':  goto END;
            }
          }
        }
        
        switch(*p1){
          case '/' :  ++p1; goto SKIP;    // ignore "./"
          case '\0':  goto STR;
          case '.' :                      // pop if "../"
            if( (*(p1+1)=='/') || (*(p1+1) == '\0') ){
              p1++;
              if( --n <= 0 ) // assume the path start with "/"
                  goto INIT;
              p2 = stack[--n];
              goto NEXT;
            }
      }
default: goto UNTIL; 
    }
  }

END:
  if( p2 == path )
    *(p2++) = '/';
  else if( *(p2-1) == '/' && p2 > (path+1) )
    --p2;
  *(p2) = '\0';
  
  return p2-path;
}

std::string toValidPath(const std::string& path) {
  std::string valid_path;
  if (path.empty()) {
    valid_path = FileSystem::get_current_dir();
  }
  else {
    valid_path = path;
  }

  if (!valid_path.empty() && !STR_END_WITH(valid_path, FS_DIR_SEPARATOR)) {
    valid_path += FS_DIR_SEPARATOR;
  }

  return valid_path;
}

bool saveTxtFile(const std::string& path, const std::vector<std::string>& lines){
  std::ofstream out_file(path);
  if (!out_file.is_open()){
    std::cerr << "fail to open file: " << path << "\n";
    return false;
  }

  for(const std::string& line : lines){
     out_file << line << "\n";
  }

  out_file.close(); 
  return true;
}

} // namespace lfc