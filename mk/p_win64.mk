# Win64 build

include $(TOP)/version.mk

TCLTK_PLATFORM = win

PREFIX = C:/Gears

CC = x86_64-w64-mingw32-gcc
CFLAGS = -g -std=c99 -I../deps/include
LDFLAGS = -mwindows -L../deps/lib
LIBS = -lraylib -ltcl$(TCLTK_VERSION_NO_DOT) -ltk$(TCLTK_VERSION_NO_DOT)
BUILD_DEPS = true
EXEC = .exe
RC = x86_64-w64-mingw32-windres

RAYLIB_BUILD = PLATFORM_OS=WINDOWS
TCL_BUILD = --host=x86_64-w64-mingw32
TK_BUILD = --host=x86_64-w64-mingw32
