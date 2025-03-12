#include "../engine.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

char* engine_strcat(const char* str1, const char* str2) {
	char* str = malloc(strlen(str1) + strlen(str2) + 1);
	strcpy(str, str1);
	strcat(str, str2);
	return str;
}

char* engine_strcat3(const char* str1, const char* str2, const char* str3) {
	char* tmp = engine_strcat(str1, str2);
	char* str = engine_strcat(tmp, str3);
	free(tmp);
	return str;
}

char* engine_find_tcl(const char* path) {
	struct stat s;
	char*	    c_path;
	c_path = engine_strcat3(PREFIX, "/tcl/", path);
	if(stat(c_path, &s) == 0) {
		return c_path;
	}
	free(c_path);

	c_path = engine_strcat("./tcl/", path);
	if(stat(c_path, &s) == 0) {
		return c_path;
	}
	free(c_path);

	return engine_strcat("", path);
}