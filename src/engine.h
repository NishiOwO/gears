#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <tcl.h>

/* common externs: declared in core.c actually */
extern Tcl_Interp* engine_tcl;

/* core.c */
int engine_init(void);

/* log.c */
void engine_log(const char* log);

/* util.c */
char* engine_strcat(const char* str1, const char* str2);
char* engine_strcat3(const char* str1, const char* str2, const char* str3);

#endif