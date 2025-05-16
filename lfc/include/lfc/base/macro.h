#ifndef __LFC_MACRO_H__
#define __LFC_MACRO_H__

#define	MIN(a,b)                    ((a) < (b) ? (a) : (b))
#define	MAX(a,b)                    ((a) > (b) ? (a) : (b))
#define ROUND(a,b)                  ((a)-((a)%(b)))
#define TIMES_OF(a,b)               (((a)+((b)-1))/(b))
#define ROUND_UP(a,b)               (TIMES_OF(a,b)*(b))
#define CEIL(a,b)                   (((a)+((b)))/(b) -1)
#define ROUND_DOWN(a,b)             (CEIL(a, b)*(b))

#define JOINT_STR(a,b)              a##b
#define JOINT_STR2(a,b)             JOINT_STR(a,b)
#define AUTO_NAME(pre)              JOINT_STR2(pre,__LINE__)
#define STATIC_ASSERT(e)            typedef char AUTO_NAME(Static)[(e)? 1:-1];
#define FREE_POINTER(x)             if( (x) != NULL ){free (x);(x) = NULL;}

#endif // __LFC_MACRO_H__

