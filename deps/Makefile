include ../config.mk

RAYLIB_VERSION = 5.5

.PHONY: all clean build-raylib build-tcl build-tk install-raylib install-tcl install-tk

all: install-raylib install-tcl install-tk

### RAYLIB ###

install-raylib: ./raylib.timestamp

./raylib.timestamp: build-raylib
	-if [ ! -f "$@" ]; then cp raylib-$(RAYLIB_VERSION)/src/libraylibdll.a lib/libraylib.a ; fi
	-if [ ! -f "$@" ]; then cp raylib-$(RAYLIB_VERSION)/src/raylib.dll lib/ ; fi
	if [ ! -f "$@" ]; then cp raylib-$(RAYLIB_VERSION)/src/r*.h include/ ; fi
	date > $@

build-raylib: ./raylib-$(RAYLIB_VERSION).tar.gz
	cd raylib-$(RAYLIB_VERSION)/src && $(MAKE) CC=$(CC) RAYLIB_LIBTYPE=SHARED $(RAYLIB_BUILD)

### TCL ###

install-tcl: ./tcl.timestamp

./tcl.timestamp: build-tcl
	if [ ! -f "$@" ]; then cd tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && gmake install ; fi
	date > $@

build-tcl: ./tcl$(TCLTK_VERSION_FULL)-src.tar.gz
	if [ ! -f "./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM)/Makefile" ] ; then cd tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && ./configure --prefix=`cd ../.. && pwd` --enable-threads $(TCL_BUILD) ; fi
	cd ./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && $(MAKE)

### TK ###

install-tk: ./tk.timestamp

./tk.timestamp: build-tk
	if [ ! -f "$@" ]; then cd tk$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && gmake install ; fi
	date > $@

build-tk: ./tk$(TCLTK_VERSION_FULL)-src.tar.gz install-tcl
	if [ ! -f "./tk$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM)/Makefile" ] ; then cd tk$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && ./configure --prefix=`cd ../.. && pwd` --enable-threads $(TCL_BUILD) ; fi
	cd ./tk$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && $(MAKE)

### TARBALL ###

./raylib-$(RAYLIB_VERSION).tar.gz:
	wget https://github.com/raysan5/raylib/archive/refs/tags/$(RAYLIB_VERSION).tar.gz -O $@
	tar xzvf $@

./tcl$(TCLTK_VERSION_FULL)-src.tar.gz:
	wget http://prdownloads.sourceforge.net/tcl/tcl$(TCLTK_VERSION_FULL)-src.tar.gz -O $@
	tar xzvf $@

./tk$(TCLTK_VERSION_FULL)-src.tar.gz:
	wget http://prdownloads.sourceforge.net/tcl/tk$(TCLTK_VERSION_FULL)-src.tar.gz -O $@
	tar xzvf $@

clean:
	rm -rf include lib bin share raylib-* tcl* tk* *.timestamp
