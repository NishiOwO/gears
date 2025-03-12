#include "../engine.h"

#include <tcl.h>

Tcl_Interp* engine_tcl;

int engine_init(void) {
	int st;

	if((st = engine_tcl_init()) != 0) return st;

	return 0;
}
