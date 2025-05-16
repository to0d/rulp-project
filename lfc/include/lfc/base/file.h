// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FILE_H__
#define __LFC_FILE_H__


#include <vector>
#include <string>

#define FS_CUR_DIR                              lfc::FileSystem::get_current_dir()
#define FS_HOME_DIR                             lfc::FileSystem::get_home_dir()
#define FS_DELETE_FILE(path)                    lfc::FileSystem::deleteFile(path)
#define FS_DIR_SEPARATOR                        lfc::FileSystem::get_dir_separator()
#define FS_FILE_NAME(path)                      lfc::FileSystem::get_file_name(path)
#define FS_FILE_EXIST(path)                     lfc::FileSystem::is_file_exist(path)
#define FS_FILE_PARENT(path)                    lfc::FileSystem::get_file_parent(path)
#define FS_FOLDER_EXIST(path)                   lfc::FileSystem::is_folder_exist(path)
#define FS_IS_ABS_PATH(path)                    lfc::FileSystem::is_abs_path(path)
#define FS_LIST_CHILD_FILES(path)               lfc::FileSystem::list_child_files(path)
#define FS_MKDIR(path)                          (lfc::mkdirs((path).c_str()) == 0)
#define FS_RELATIVE_PATH(base, path)            lfc::FileSystem::get_relative_path(base, path)
#define FS_TO_VALID_PATH(path)                  lfc::toValidPath(path)

#define OPEN_TXT_FILE(path)                     lfc::openTxtFile(path, "", false)
#define OPEN_TXT_FILE_IGNORE_TAIL_BLANK(path)   lfc::openTxtFile(path, "", true)
#define SAVE_TXT_FILE(path, lines)              lfc::saveTxtFile(path, lines)

namespace lfc {

class FileSystem {

public:

  static bool is_abs_path(const std::string& path);

  static bool is_file_exist(const std::string& path);

  static bool isSupportFile(const std::string& path);

  static bool is_folder_exist(const std::string& path);

  static bool deleteFile(const std::string& path);

  static std::string get_current_dir();

  static std::string get_home_dir();

  static std::string get_dir_separator();

  static std::string get_file_name(const std::string& path);

  static std::string get_file_parent(const std::string& path);

  static std::string get_relative_path(const std::string& base, const std::string& path);

  static std::vector<std::string> list_child_files(const std::string& path);

};



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
int mkdirs(const char* path);

std::vector<std::string> openTxtFile(const std::string& path, const std::string& charset = "", bool ignore_tail_blank_line = false);

int is_dir(const char* path);

int rm_dir(char * path);

int simplify_path(char* path);

bool saveTxtFile(const std::string& path, const std::vector<std::string>& lines);

std::string toValidPath(const std::string& path);

} // namespace lfc

#endif // __LFC_FILE_H__

