include ../config.mk

RAYLIB_VERSION = 5.5

.PHONY: all clean build-raylib build-tcl install-raylib install-tcl

all: install-raylib install-tcl

### RAYLIB ###

install-raylib: ./raylib.timestamp

./raylib.timestamp: build-raylib
	-cp raylib-$(RAYLIB_VERSION)/src/libraylibdll.a lib/libraylib.a
	-cp raylib-$(RAYLIB_VERSION)/src/raylib.dll lib/
	cp raylib-$(RAYLIB_VERSION)/src/r*.h include/
	date > $@

build-raylib: ./raylib-$(RAYLIB_VERSION).tar.gz
	cd raylib-$(RAYLIB_VERSION)/src && $(MAKE) CC=$(CC) RAYLIB_LIBTYPE=SHARED $(RAYLIB_BUILD)

### TCL ###

install-tcl: ./tcl.timestamp

./tcl.timestamp: build-tcl
	-mkdir -p lib/tcl$(TCLTK_VERSION)
	-cp ./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM)/*.dll lib/
	-cp ./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM)/*.dll.a lib/
	-cp -rf ./tcl$(TCLTK_VERSION_FULL)/library/init.tcl lib/tcl$(TCLTK_VERSION)/
	-cp -rf ./tcl$(TCLTK_VERSION_FULL)/library/clock.tcl lib/tcl$(TCLTK_VERSION)/
	-cp ./tcl$(TCLTK_VERSION_FULL)/generic/*.h include/
	date > $@

build-tcl: ./tcl$(TCLTK_VERSION_FULL)-src.tar.gz
	if [ ! -f "./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM)/Makefile" ] ; then cd tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && ./configure --prefix=`cd ../.. && pwd` --enable-threads CC=$(CC) RC=$(RC) ; fi
	cd ./tcl$(TCLTK_VERSION_FULL)/$(TCLTK_PLATFORM) && $(MAKE)

### TARBALL ###

./raylib-$(RAYLIB_VERSION).tar.gz:
	wget https://github.com/raysan5/raylib/archive/refs/tags/$(RAYLIB_VERSION).tar.gz -O $@
	tar xzvf $@

./tcl$(TCLTK_VERSION_FULL)-src.tar.gz:
	wget http://prdownloads.sourceforge.net/tcl/tcl$(TCLTK_VERSION_FULL)-src.tar.gz -O $@
	tar xzvf $@

clean:
	rm -rf include lib bin raylib-* tcl* *.timestamp
