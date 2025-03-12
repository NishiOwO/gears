#include "../engine.h"

#include <stdlib.h>

#include <tk.h>

int engine_tcl_engine_log(ClientData clientData, Tcl_Interp* interp, int argc, const char** argv){
	int i;
	if(argc <= 1){
		Tcl_SetResult(interp, "Usage: engine_log msg1 [msg2...]\n", TCL_STATIC);
		return TCL_ERROR;
	}
	for(i = 1; i < argc; i++){
		printf("[GearsEngine Tcl/Tk] %s\n", argv[i]);
	}
	return TCL_OK;
}

void engine_tcl_init_commands(void){
	Tcl_CreateCommand(engine_tcl, "engine_log", engine_tcl_engine_log, NULL, NULL);
}

int engine_tcl_init(void){
	int  major, minor, patchlevel;
	char buffer[512];
	char* fn;

	engine_log("Initializing Tcl/Tk");
	engine_tcl = Tcl_CreateInterp();
	if(Tcl_Init(engine_tcl) != TCL_OK) return 1;
	if(Tk_Init(engine_tcl) != TCL_OK) return 1;
	Tcl_GetVersion(&major, &minor, &patchlevel, NULL);
	sprintf(buffer, "Tcl/Tk version %d.%d.%d", major, minor, patchlevel);
	engine_log(buffer);

	engine_tcl_init_commands();

	Tcl_SetVar(engine_tcl, "GEARS_PREFIX", PREFIX, 0);
#ifdef __MINGW32__
	Tcl_SetVar(engine_tcl, "GEARS_DYNAMIC_PREFIX", PREFIX, 0);
#else
	Tcl_SetVar(engine_tcl, "GEARS_DYNAMIC_PREFIX", PREFIX, 0);
#endif

	fn = engine_find_tcl("forest-dark.tcl");
	if(Tcl_EvalFile(engine_tcl, fn) != TCL_OK){
		engine_log("Could not initialize theme. Your installation might be broken.");
		sprintf(buffer, "Reason: %s", Tcl_GetStringResult(engine_tcl));
		engine_log(buffer);
		free(fn);
		return 1;
	}
	free(fn);

	Tcl_Eval(engine_tcl, "ttk::style theme use forest-dark");

	fn = engine_find_tcl("init.tcl");
	if(Tcl_EvalFile(engine_tcl, fn) != TCL_OK){
		engine_log("Could not execute init.tcl. Your installation might be broken.");
		sprintf(buffer, "Reason: %s", Tcl_GetStringResult(engine_tcl));
		engine_log(buffer);
		free(fn);
		return 1;
	}
	free(fn);
	return 0;
}
