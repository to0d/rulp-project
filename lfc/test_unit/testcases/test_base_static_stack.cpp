#include "unitest_base.h"
#include "lfc/base/static/static_stack.h"

TEST(base_static_stack, static_stack_1)
{
  LFC_STATIC_STACK_DECLARE(TEMP_STACK_1, 1000)
  LFC_STATIC_STACK_MALLOC(TEMP_STACK_1, 100);
  char* p = (char*) LFC_STATIC_STACK(TEMP_STACK_1);
  EXPECT_TRUE(p != NULL);
}

typedef struct {
  long int RecLen;
  long int SrcLen;
  char     Line[1];
} _MY_RECORD_T;

LFC_STATIC_STACK_DECLARE(RecordStackBuf, 1024*64)    /* 64K*/

TEST(base_static_stack, static_stack_2)
{
  _MY_RECORD_T* pRecord = NULL;
  LFC_STATIC_STACK_MALLOC(RecordStackBuf, 1024); 
  pRecord =(_MY_RECORD_T*)LFC_STATIC_STACK(RecordStackBuf);
  EXPECT_TRUE(pRecord != NULL);
}

