include ../config.mk

RAYLIB_VERSION = 5.5

.PHONY: all clean build-raylib

all: build-raylib

build-raylib: ./raylib-$(RAYLIB_VERSION).tar.gz
	cd raylib-$(RAYLIB_VERSION)/src && $(MAKE) CC=$(CC) RAYLIB_LIBTYPE=SHARED $(RAYLIB_BUILD)
	-cp raylib-$(RAYLIB_VERSION)/src/libraylibdll.a lib/
	-cp raylib-$(RAYLIB_VERSION)/src/raylib.dll lib/
	-cp raylib-$(RAYLIB_VERSION)/src/libraylib.so lib/
	cp raylib-$(RAYLIB_VERSION)/src/r*.h include/

./raylib-$(RAYLIB_VERSION).tar.gz:
	wget https://github.com/raysan5/raylib/archive/refs/tags/$(RAYLIB_VERSION).tar.gz -O $@
	tar xzvf ./raylib-$(RAYLIB_VERSION).tar.gz

clean:
	rm -rf include lib raylib-*