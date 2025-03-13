engine_log "Hello from Tcl/Tk"
wm title . "GearsEngine Tcl/Tk Window"
wm geometry . 640x480

menu .menu
. configure -menu .menu

.menu add cascade -label File -menu .menu.file

menu .menu.file -tearoff no
.menu.file add cascade -label Test

ttk::frame .frame

ttk::button .frame.test -text "test"
pack .frame -fill both -expand 1
pack .frame.test -fill y -expand 1
tkwait window .