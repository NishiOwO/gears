#include "../engine.h"

#include <tcl.h>

Tcl_Interp* engine_tcl;

int engine_init(void){
    int major, minor, patchlevel;
    char buffer[512];
    engine_log("Initializing Tcl/Tk");
    engine_tcl = Tcl_CreateInterp();
    if(Tcl_Init(engine_tcl) != TCL_OK) return 1;
    Tcl_GetVersion(&major, &minor, &patchlevel, NULL);
    sprintf(buffer, "Tcl/Tk version %d.%d.%d", major, minor, patchlevel);
    engine_log(buffer);
    return 0;
}