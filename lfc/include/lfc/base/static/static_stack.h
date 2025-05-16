// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STATIC_STACK_H__
#define __LFC_STATIC_STACK_H__

#include <assert.h>
#include <stdlib.h>


#define LFC_STATIC_STACK_NAME(name)            __stack_##name
#define LFC_STATIC_STACK_LEN(name)             __len_##name
#define LFC_STATIC_STACK(name)                 __static_##name

#define LFC_STATIC_STACK_DECLARE(name, size) \
static char  LFC_STATIC_STACK(name)[(size)]; \
static char* LFC_STATIC_STACK_NAME(name)=LFC_STATIC_STACK(name);\
static long  LFC_STATIC_STACK_LEN(name)=sizeof(LFC_STATIC_STACK(name));

#define LFC_STATIC_STACK_FREE( name )\
{if( LFC_STATIC_STACK_NAME(name) != NULL )\
{\
    if( LFC_STATIC_STACK_NAME(name)==LFC_STATIC_STACK(name))\
    {  LFC_STATIC_STACK_NAME(name)= NULL;\
    }\
    else\
    {   FREE_POINTER(LFC_STATIC_STACK_NAME(name));\
    }\
    LFC_STATIC_STACK_LEN(name) = 0;\
}}

#define LFC_STATIC_STACK_MALLOC( name, length )\
{\
if( LFC_STATIC_STACK_NAME(name)==NULL\
 && sizeof(LFC_STATIC_STACK(name))>=(length))\
{\
    LFC_STATIC_STACK_NAME(name) = LFC_STATIC_STACK(name); \
    LFC_STATIC_STACK_LEN(name) = sizeof(LFC_STATIC_STACK(name));\
}\
else if( LFC_STATIC_STACK_NAME(name)==NULL\
    || (LFC_STATIC_STACK_LEN(name)<(length)))\
{\
    LFC_STATIC_STACK_FREE(name);\
    LFC_STATIC_STACK_NAME(name) = (char*) malloc( length ); \
    assert(LFC_STATIC_STACK_NAME(name) != NULL); \
    LFC_STATIC_STACK_LEN(name) = (length);\
}\
}


#endif //__LFC_STATIC_STACK_H__