// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/LoadUtil.h"
#include "rulp/utils/RObjectHandler.h"
#include "../class/XRNoClass.h"
#include "../namespace/XRNameSpaceClass.h"
#include "lfc/base/file.h"
#include "lfc/base/string.h"
#include "lfc/base/system.h"
#include <iostream>

using namespace lfc;
using namespace lfc;
namespace lfc {

static boolean _contain(IRList* lsList, StrConstRef name) {

  auto it = lsList->iterator();
  while (it->hasNext()) {
    auto obj = it->next();
    if (TYPE_INDEX_OF(obj) == E_STRING && AS_STR(obj)->asString() == name) {
      return true;
    }
  }

  return false;
}

#define A_USER_HOME             "?user.home"
#define A_USER_NAME             "?user.name"
#define A_USER_DIR              "?user.dir"
#define A_FILE_SEP              "?file.separator"
#define A_PATH_SEP              "?path.separator"
#define A_OS_NAME               "?os.name"
#define A_OS_VERSION            "?os.version"

static std::map<std::string, std::string> jvmVarMap;

static void _mappingJvmVar(IRFrame* frame, StrConstRef varName, StrConstRef jvmVarName) {

  std::string varVal;

  // synchronized (jvmVarMap) {
  //   varVal = jvmVarMap.get(varName);
  //   if (varVal == null) {
  //     varVal = System.getProperty(jvmVarName);
  //     jvmVarMap.put(varName, varVal);
  //   }
  // }

  RuntimeUtil::addFrameObject(frame, RulpFactory::createVar(varName, RulpFactory::createString(varVal)));
}


void LoadUtil::initSystemVars(IRInterpreter* interpreter, IRFrame* frame) {

  _mappingJvmVar(frame, "?user.home", "user.home");
  _mappingJvmVar(frame, "?user.name", "user.name");
  _mappingJvmVar(frame, "?user.dir", "user.dir");
  _mappingJvmVar(frame, "?os.name", "os.name");
  _mappingJvmVar(frame, "?os.version", "os.version");


  RulpUtil::setLocalVar(frame, A_TRACE, O_False);
  RulpUtil::setLocalVar(frame, A_FILE_SEP, RulpFactory::createString("/"));
  RulpUtil::setLocalVar(frame, A_PATH_SEP, RulpFactory::createString(":"));
  RulpUtil::setLocalVar(frame, A_LOADER_LIST, RulpFactory::createVaryList());
}

const std::string base_script = 
";****************************************************;  \n"\
"; Alias                                                 \n"\
";****************************************************;  \n"\
"(alias int INTEGER)                                     \n"\
"(alias float FLOAT)                                     \n"\
"(alias bool BOOL)                                       \n"\
"(alias string STRING)                                   \n"\
"(alias list LIST)                                       \n"\
"(alias expr EXPRESSION)                                 \n"\
"(alias random-double random)                            \n"\
";(alias new def)                                        \n"\
"                                                        \n"\
";****************************************************;  \n"\
"; Optimize attribute                                    \n"\
";****************************************************;  \n"\
"(add-attribute !=                atom)                  \n"\
"(add-attribute %                 atom)                  \n"\
"(add-attribute &                 atom)                  \n"\
"(add-attribute *                 atom)                  \n"\
"(add-attribute +                 atom)                  \n"\
"(add-attribute -                 atom)                  \n"\
"(add-attribute /                 atom)                  \n"\
"(add-attribute <                 atom)                  \n"\
"(add-attribute <=                atom)                  \n"\
"(add-attribute =                 atom)                  \n"\
"(add-attribute >                 atom)                  \n"\
"(add-attribute >=                atom)                  \n"\
"(add-attribute ^                 atom)                  \n"\
"(add-attribute |                 atom)                  \n"\
"(add-attribute ~                 atom)                  \n"\
"(add-attribute and               atom)                  \n"\
"(add-attribute not               atom)                  \n"\
"(add-attribute or                atom)                  \n"\
"(add-attribute power             atom)                  \n"\
"(add-attribute str-char-at       atom)                  \n"\
"(add-attribute str-end-with      atom)                  \n"\
"(add-attribute str-equal         atom)                  \n"\
"(add-attribute str-equal-nocase  atom)                  \n"\
"(add-attribute str-format        atom)                  \n"\
"(add-attribute str-index-of      atom)                  \n"\
"(add-attribute str-last-index-of atom)                  \n"\
"(add-attribute str-length        atom)                  \n"\
"(add-attribute str-match         atom)                  \n"\
"(add-attribute str-replace       atom)                  \n"\
"(add-attribute str-split         atom)                  \n"\
"(add-attribute str-split-line    atom)                  \n"\
"(add-attribute str-start-with    atom)                  \n"\
"(add-attribute str-substr        atom)                  \n"\
"(add-attribute str-trim          atom)                  \n"\
"(add-attribute str-trim-head     atom)                  \n"\
"(add-attribute str-trim-tail     atom)                  \n"\
"(add-attribute str-upper         atom)                  \n"\
"(add-attribute strcat            atom)                  \n"\
"(add-attribute to-int            atom)                  \n"\
"                                                        \n"\
"(add-attribute !=                    stable)            \n"\
"(add-attribute %                     stable)            \n"\
"(add-attribute &                     stable)            \n"\
"(add-attribute *                     stable)            \n"\
"(add-attribute +                     stable)            \n"\
"(add-attribute -                     stable)            \n"\
"(add-attribute /                     stable)            \n"\
"(add-attribute ::                    stable)            \n"\
"(add-attribute <                     stable)            \n"\
"(add-attribute <=                    stable)            \n"\
"(add-attribute =                     stable)            \n"\
"(add-attribute >                     stable)            \n"\
"(add-attribute >=                    stable)            \n"\
"(add-attribute ^                     stable)            \n"\
"(add-attribute access                stable)            \n"\
"(add-attribute add-array-to-list     stable)            \n"\
"(add-attribute add-attribute         stable)            \n"\
"(add-attribute add-list-to-array     stable)            \n"\
"(add-attribute add-list-to-list      stable)            \n"\
"(add-attribute alias                 stable)            \n"\
"(add-attribute and                   stable)            \n"\
"(add-attribute attribute-of          stable)            \n"\
"(add-attribute blob-length           stable)            \n"\
"(add-attribute break                 stable)            \n"\
"(add-attribute can-cast              stable)            \n"\
"(add-attribute case                  stable)            \n"\
"(add-attribute class-of              stable)            \n"\
"(add-attribute cmp_def               stable)            \n"\
"(add-attribute compute               stable)            \n"\
"(add-attribute continue              stable)            \n"\
"(add-attribute defclass              stable)            \n"\
"(add-attribute defconst              stable)            \n"\
"(add-attribute deftemplate           stable)            \n"\
"(add-attribute defun                 stable)            \n"\
"(add-attribute defvar                stable)            \n"\
"(add-attribute do                    stable)            \n"\
"(add-attribute do-when-obj-deleted   stable)            \n"\
"(add-attribute do-when-var-changed   stable)            \n"\
"(add-attribute equal_def             stable)            \n"\
"(add-attribute foreach               stable)            \n"\
"(add-attribute get-of-array          stable)            \n"\
"(add-attribute get-of-list           stable)            \n"\
"(add-attribute has-member            stable)            \n"\
"(add-attribute if                    stable)            \n"\
"(add-attribute is-const              stable)            \n"\
"(add-attribute join                  stable)            \n"\
"(add-attribute lambda                stable)            \n"\
"(add-attribute let                   stable)            \n"\
"(add-attribute loop                  stable)            \n"\
"(add-attribute list-of               stable)            \n"\
"(add-attribute make-array            stable)            \n"\
"(add-attribute make-blob             stable)            \n"\
"(add-attribute make-list             stable)            \n"\
"(add-attribute make-string           stable)            \n"\
"(add-attribute name-of               stable)            \n"\
"(add-attribute new                   stable)            \n"\
"(add-attribute not                   stable)            \n"\
"(add-attribute or                    stable)            \n"\
"(add-attribute power                 stable)            \n"\
"(add-attribute property-of           stable)            \n"\
"(add-attribute ref                   stable)            \n"\
"(add-attribute remove-all-list       stable)            \n"\
"(add-attribute return                stable)            \n"\
"(add-attribute reverse               stable)            \n"\
"(add-attribute seta                  stable)            \n"\
"(add-attribute setq                  stable)            \n"\
"(add-attribute size-of-array         stable)            \n"\
"(add-attribute size-of-list          stable)            \n"\
"(add-attribute sort-list             stable)            \n"\
"(add-attribute str-char-at           stable)            \n"\
"(add-attribute str-end-with          stable)            \n"\
"(add-attribute str-equal             stable)            \n"\
"(add-attribute str-equal-nocase      stable)            \n"\
"(add-attribute str-format            stable)            \n"\
"(add-attribute str-index-of          stable)            \n"\
"(add-attribute str-last-index-of     stable)            \n"\
"(add-attribute str-length            stable)            \n"\
"(add-attribute str-match             stable)            \n"\
"(add-attribute str-replace           stable)            \n"\
"(add-attribute str-split             stable)            \n"\
"(add-attribute str-start-with        stable)            \n"\
"(add-attribute str-substr            stable)            \n"\
"(add-attribute str-trim              stable)            \n"\
"(add-attribute str-trim-head         stable)            \n"\
"(add-attribute str-trim-tail         stable)            \n"\
"(add-attribute str-upper             stable)            \n"\
"(add-attribute strcat                stable)            \n"\
"(add-attribute subject-of            stable)            \n"\
"(add-attribute to-atom               stable)            \n"\
"(add-attribute to-blob               stable)            \n"\
"(add-attribute to-expr               stable)            \n"\
"(add-attribute to-int                stable)            \n"\
"(add-attribute to-named-list         stable)            \n"\
"(add-attribute to-nonamed-list       stable)            \n"\
"(add-attribute to-string             stable)            \n"\
"(add-attribute type-of               stable)            \n"\
"(add-attribute union                 stable)            \n"\
"(add-attribute uniq                  stable)            \n"\
"(add-attribute value-of              stable)            \n"\
"(add-attribute value-type-of         stable)            \n"\
"(add-attribute when                  stable)            \n"\
"(add-attribute write-blob            stable)            \n"\
"(add-attribute |                     stable)            \n"\
"(add-attribute ~                     stable)            \n"\
"                                                        \n"\
"(add-attribute load              thread-unsafe)         \n"\
"(add-attribute print             thread-unsafe)         \n"\
"(add-attribute print-frame-tree  thread-unsafe)         \n"\
"(add-attribute print-global-info thread-unsafe)         \n"\
"(add-attribute print-subject     thread-unsafe)         \n"\
"(add-attribute print-frame-tree  thread-unsafe)         \n"\
"(add-attribute print-impl        thread-unsafe)         \n"\
"(add-attribute out-to-file       thread-unsafe)         \n"\
"(add-attribute open-txt-file     thread-unsafe)         \n"\
"(add-attribute save-txt-file     thread-unsafe)         \n"\
"                                                        \n"\
"(add-attribute and  return-type  bool)                  \n"\
"(add-attribute or   return-type  bool)                  \n"\
"(add-attribute not  return-type  bool)                  \n"\
"                                                        \n"\
"(add-attribute +                 return-type  1)        \n"\
"(add-attribute -                 return-type  1)        \n"\
"(add-attribute *                 return-type  1)        \n"\
"(add-attribute /                 return-type  1)        \n"\
"(add-attribute str-char-at       return-type  int)      \n"\
"(add-attribute str-end-with      return-type  bool)     \n"\
"(add-attribute str-equal         return-type  bool)     \n"\
"(add-attribute str-equal-nocase  return-type  bool)     \n"\
"(add-attribute str-format        return-type  string)   \n"\
"(add-attribute str-index-of      return-type  int)      \n"\
"(add-attribute str-last-index-of return-type  int)      \n"\
"(add-attribute str-length        return-type  int)      \n"\
"(add-attribute str-match         return-type  bool)     \n"\
"(add-attribute str-replace       return-type  string)   \n"\
"(add-attribute str-split         return-type  list)     \n"\
"(add-attribute str-split-line    return-type  list)     \n"\
"(add-attribute str-start-with    return-type  bool)     \n"\
"(add-attribute str-substr        return-type  string)   \n"\
"(add-attribute str-trim          return-type  string)   \n"\
"(add-attribute str-trim-head     return-type  string)   \n"\
"(add-attribute str-trim-tail     return-type  string)   \n"\
"(add-attribute str-upper         return-type  string)   \n"\
"                                                        \n"\
";****************************************************;  \n"\
"; Basic tools                                           \n"\
";****************************************************;  \n"\
"(defun length-of ((?l string)) (return (str-length ?l)))\n"\
"(defun length-of ((?l blob)) (return (blob-length ?l))) \n"\
"                                                        \n"\
"(defun equal (?l ?2) (return (equal_def ?l ?2)))        \n"\
"(defun equal ((?l string) (?2 string)) (return (str-equal ?l ?2)))  \n"\
"                                                                    \n"\
"(defun cmp (?l ?2) (return (cmp_def ?l ?2)))                        \n"\
"                                                                    \n"\
"(defun println ()                                    (print \"\\n\"\\))                                     \n"\
"(defun println (?a1)                                 (print ?a1 \"\\n\"\\))                                 \n"\
"(defun println (?a1 ?a2)                             (print ?a1 ?a2 \"\\n\"\\))                             \n"\
"(defun println (?a1 ?a2 ?a3)                         (print ?a1 ?a2 ?a3 \"\\n\"\\))                         \n"\
"(defun println (?a1 ?a2 ?a3 ?a4)                     (print ?a1 ?a2 ?a3 ?a4 \"\\n\"\\))                     \n"\
"(defun println (?a1 ?a2 ?a3 ?a4 ?a5)                 (print ?a1 ?a2 ?a3 ?a4 ?a5 \"\\n\"\\))                 \n"\
"(defun println (?a1 ?a2 ?a3 ?a4 ?a5 ?a6)             (print ?a1 ?a2 ?a3 ?a4 ?a5 ?a6 \"\\n\"\\))             \n"\
"(defun println (?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7)         (print ?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7 \"\\n\"\\))         \n"\
"(defun println (?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7 ?a8)     (print ?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7 ?a8 \"\\n\"\\))     \n"\
"(defun println (?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7 ?a8 ?a9) (print ?a1 ?a2 ?a3 ?a4 ?a5 ?a6 ?a7 ?a8 ?a9 \"\\n\"\\)) \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; Enviroment vars                                                                                      \n"\
";****************************************************;                                                 \n"\
"(defvar ?path (make-list))                                                                             \n"\
"(defvar ?load-system (make-list))                                                                      \n"\
"(defvar ?load-class (make-list))                                                                       \n"\
"(defvar ?load-jar (make-list))                                                                         \n"\
"(defvar ?load-script (make-list))                                                                      \n"\
"                                                                                                       \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; Basic tools                                                                                          \n"\
";****************************************************;                                                 \n"\
"                                                                                                       \n"\
"(defmacro -- (?v) (setq ?v (- ?v 1)))                                                                  \n"\
"(defmacro ++ (?v) (setq ?v (+ ?v 1)))                                                                  \n"\
"                                                                                                       \n"\
"(defmacro inc (?var ?value) (setq ?var (+ ?var ?value)))                                               \n"\
"(defmacro dec (?var ?value) (setq ?var (- ?var ?value)))                                               \n"\
"                                                                                                       \n"\
"(defun max (?a ?b)                                                                                     \n"\
"    (if (>= ?a ?b)                                                                                     \n"\
"        (return ?a)                                                                                    \n"\
"        (return ?b)                                                                                    \n"\
"    )                                                                                                  \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"(defun max ((?list list))                                                                              \n"\
"                                                                                                       \n"\
"    (defvar ?size (size-of-list ?list))                                                                \n"\
"    (if (= ?size 0)                                                                                    \n"\
"        (return nil)                                                                                   \n"\
"    )                                                                                                  \n"\
"                                                                                                       \n"\
"    (defvar ?_max_ (get-of-list ?list 0))                                                              \n"\
"                                                                                                       \n"\
"    (loop for ?i from 1 to (- ?size 1) do                                                              \n"\
"        (defvar ?v (get-of-list ?list ?i))                                                             \n"\
"        (if (> ?v ?_max_)                                                                              \n"\
"            (setq ?_max_ ?v)                                                                           \n"\
"        )                                                                                              \n"\
"    )                                                                                                  \n"\
"                                                                                                       \n"\
"    (return ?_max_)                                                                                    \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"                                                                                                       \n"\
"(defun min (?a ?b)                                                                                     \n"\
"    (if (<= ?a ?b)                                                                                     \n"\
"        (return ?a)                                                                                    \n"\
"        (return ?b)                                                                                    \n"\
"    )                                                                                                  \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"(defun min ((?list list))                                                                              \n"\
"                                                                                                       \n"\
"    (defvar ?size (size-of-list ?list))                                                                \n"\
"    (if (= ?size 0)                                                                                    \n"\
"        (return nil)                                                                                   \n"\
"    )                                                                                                  \n"\
"                                                                                                       \n"\
"    (defvar ?_min_ (get-of-list ?list 0))                                                              \n"\
"                                                                                                       \n"\
"    (loop for ?i from 1 to (- ?size 1) do                                                              \n"\
"        (defvar ?v (get-of-list ?list ?i))                                                             \n"\
"        (if (< ?v ?_min_)                                                                              \n"\
"            (setq ?_min_ ?v)                                                                           \n"\
"        )                                                                                              \n"\
"    )                                                                                                  \n"\
"                                                                                                       \n"\
"    (return ?_min_)                                                                                    \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; List tools                                                                                           \n"\
";****************************************************;                                                 \n"\
"(defun size-of  ((?l list)) (return (size-of-list ?l)))                                                \n"\
"(defun is-empty ((?l list)) (return (equal (size-of-list ?l) 0)))                                      \n"\
"(defun to-list  ((?l list)) (return ?l))                                                               \n"\
"(defun to-array ((?l list)) (return (add-list-to-array (make-array) ?l)))                              \n"\
"                                                                                                       \n"\
"(defun add ((?l list) ?e0) (return (add-list-to-list ?l '(?e0))))                                      \n"\
"(defun add ((?l list) ?e0 ?e1) (return (add-list-to-list ?l '(?e0 ?e1))))                              \n"\
"(defun add ((?l list) ?e0 ?e1 ?e2) (return (add-list-to-list ?l '(?e0 ?e1 ?e2))))                      \n"\
"(defun add-all ((?l1 list) (?l2 list)) (return (add-list-to-list ?l1 ?l2)))                            \n"\
"                                                                                                       \n"\
"(defun get ((?l list) (?i int)) (return (get-of-list ?l ?i)))                                          \n"\
"                                                                                                       \n"\
"(defun index-of (?obj (?list list))                                                                    \n"\
"    (defvar ?pos (- (size-of ?list) 1))                                                                \n"\
"    (loop                                                                                              \n"\
"        (if (< ?pos 0)                                                                                 \n"\
"            (break))                                                                                   \n"\
"        (defvar ?obj2 (get ?list ?pos))                                                                \n"\
"        (if (equal ?obj ?obj2)                                                                         \n"\
"            (break))                                                                                   \n"\
"        (-- ?pos)                                                                                      \n"\
"    )                                                                                                  \n"\
"    (return ?pos)                                                                                      \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"(defun remove ((?l list) ?e0) (return (remove-all-list ?l '(?e0))))                                    \n"\
"(defun remove-all ((?l1 list) (?l2 list)) (return (remove-all-list ?l1 ?l2)))                          \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; Array tools                                                                                          \n"\
";****************************************************;                                                 \n"\
"(defun size-of  ((?arr array)) (return (size-of-array ?arr)))                                          \n"\
"(defun size-of  ((?arr array) (?dim int)) (return (size-of-array ?arr ?dim)))                          \n"\
"(defun is-empty ((?arr array)) (return (equal (size-of-array ?arr) 0)))                                \n"\
"(defun to-list  ((?arr array)) (return (add-array-to-list '() ?arr)))                                  \n"\
"                                                                                                       \n"\
"(defun add ((?a array) ?e0) (return (add-list-to-array ?a '(?e0))))                                    \n"\
"(defun add ((?a array) ?e0 ?e1) (return (add-list-to-array ?a '(?e0 ?e1))))                            \n"\
"(defun add ((?a array) ?e0 ?e1 ?e2) (return (add-list-to-array ?a '(?e0 ?e1 ?e2))))                    \n"\
"                                                                                                       \n"\
"(defun get ((?arr array) (?i1 int)) (return (get-of-array ?arr ?i1)))                                  \n"\
"(defun get ((?arr array) (?i1 int) (?i2 int)) (return (get-of-array ?arr ?i1 ?i2)))                    \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; Iterator tools                                                                                       \n"\
";****************************************************;                                                 \n"\
"(defun to-list  ((?it iterator))                                                                       \n"\
"    (defvar ?arr (make-array))                                                                         \n"\
"    (loop                                                                                              \n"\
"        (if (not (has-next ?it))                                                                       \n"\
"            (break)                                                                                    \n"\
"        )                                                                                              \n"\
"        (add ?arr (next ?it))                                                                          \n"\
"    )                                                                                                  \n"\
"    (return (to-list ?arr))                                                                            \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
";****************************************************;                                                 \n"\
"; Namespace tools                                                                                      \n"\
";****************************************************;                                                 \n"\
"(deftemplate use ((namespace atom) (?ns namespace))                                                    \n"\
"    (add_search_frame parent (frame-of $(value-of ?ns)))                                               \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"(deftemplate use ((namespace atom) (?ns frame))                                                        \n"\
"    (add_search_frame parent ?ns)                                                                      \n"\
")                                                                                                      \n"\
"                                                                                                       \n"\
"(deftemplate use (namespace ?ns)                                                                       \n"\
"    (throw bad-type (strcat \"namespace not found: \" (to-string ?ns)))                                \n"\
")                                                                                                      \n"
;

void LoadUtil::initSystemScript(IRInterpreter* interpreter, IRFrame* frame) {
  LoadUtil::loadScript(interpreter, frame, base_script);
}

void LoadUtil::initSystemClass(IRInterpreter* interpreter, IRFrame* frame) {
 
  RuntimeUtil::addFrameObject(frame, new XRNoClass(A_NOCLASS, frame));
  RuntimeUtil::addFrameObject(frame, new XRNameSpaceClass(A_NAMESPACE, frame));
  RULP_INC_OBJ_CREATE_COUNT(T_CLASS);

}

void LoadUtil::initLoader(StrConstRef loaderName, IRInterpreter* interpreter, IRFrame* frame) {
  
  auto ldList = AS_LIST(AS_VAR(interpreter->getObject(A_LOADER_LIST))->getValue());

  // Script can only be loaded once
  if (_contain(ldList, loaderName)) {
    return;
  }

  if (RulpUtil::isTrace(frame)) {
    std::cout << "initializing loader: " << loaderName << "\n";
  }

  auto loader = RuntimeUtil::findLoader(loaderName);
  if(loader == null ){
    throw RException("loader not found" + loaderName);
  }

  loader->load(interpreter, frame);
  ldList->add(RulpFactory::createString(loaderName));
}

IRList* LoadUtil::loadRulp(IRInterpreter* interpreter, IRFrame* frame, StrConstRef path, StrConstRef charset) {

  if(!FS_FILE_EXIST(path)){
    throw RExceptionIO(frame, "file not found: " + path);
  }
			
  auto rstList = RulpFactory::createVaryList();

  interpreter->compute(RulpUtil::toOneLine(openTxtFile(path, charset)), [&](auto rst){
    rstList->add(rst);
  });

  return rstList;
}

void LoadUtil::loadScript(IRInterpreter* interpreter, IRFrame* frame, StrConstRef script){

  RListHandler rsultList;

  for(auto obj : interpreter->getParser()->parse(script)) {
    rsultList.addResult(obj);
    rsultList.addResult(interpreter->compute(frame, obj));
    // interpreter->compute(frame, obj);
  }

}

void LoadUtil::loadScript(IRInterpreter* interpreter, IRFrame* frame, StrConstRef path, StrConstRef charset) {

  auto absPath = LoadUtil::lookupFile(path, interpreter, frame);
  if (absPath.empty()) {
    throw RExceptionIO(frame, "file not found: " + path);
  }

  auto lsList = AS_LIST(AS_VAR(interpreter->getObject(A_LOAD_SCRIPT))->getValue());

  /*************************************************/
  // Script can only be loaded once
  /*************************************************/
  if (_contain(lsList, absPath)) {
    return;
  }

  if (RulpUtil::isTrace(frame)) {
    std::cout << "loading script: " << absPath << "\n";
  }

  ROH list = LoadUtil::loadRulp(interpreter, frame, absPath, charset);

  lsList->add(RulpFactory::createString(absPath));
}

static std::string _lookupFile(StrConstRef parent, StrConstRef path) {

  if (FS_FOLDER_EXIST(parent)) {

    auto newPath = FS_TO_VALID_PATH(parent) + path;
    if (FS_FILE_EXIST(newPath)) {
      return newPath;
    }

    if (!STR_END_WITH(path, A_RULP_SUFFIX)) {
      newPath = FS_TO_VALID_PATH(parent) + path + A_RULP_SUFFIX;
      if (FS_FILE_EXIST(newPath)) {
        return newPath;
      }
    }
  }

  return "";
}

std::string LoadUtil::lookupFile(StrConstRef path, IRInterpreter* interpreter, IRFrame* frame) {

  if (FS_FILE_EXIST(path)) {
    return path;
  }

  if (FS_IS_ABS_PATH(path)) {
    return "";
  }
  
  if (!STR_END_WITH(path, A_RULP_SUFFIX)) {
    auto newPath = path + A_RULP_SUFFIX;
    if (FS_FILE_EXIST(newPath)) {
      return newPath;
    }
  }

  /*************************************************/
  // Search in "?path"
  /*************************************************/
  auto lpList = AS_LIST(AS_VAR(interpreter->getObject(A_PATH))->getValue());

  auto it = lpList->iterator();
  while (it->hasNext()) {
    auto aPath = AS_STR(it->next())->asString();
    auto newPath = _lookupFile(aPath, path);
    if (!newPath.empty()) {
      return newPath;
    }
  }

  /*************************************************/
  // Search in System env "PATH"
  /*************************************************/
  for (auto aPath : SYS_ENV_PATHS) {
    auto newPath = _lookupFile(aPath, path);
    if(!newPath.empty()) {
      return newPath;
    }
  }

  return "";
}

} // namespace lfc