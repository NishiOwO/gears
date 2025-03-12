engine_log "Hello from Tcl/Tk"
ttk::button .test -text "test" -command {destroy .}
pack .test
tkwait window .
