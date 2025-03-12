# Win64 build

TCLTK_VERSION = 8.6
TCLTK_VERSION_NO_DOT = 86
TCLTK_VERSION_FULL = 8.6.16
TCLTK_PLATFORM = win

CC = x86_64-w64-mingw32-gcc
CFLAGS = -g -std=c99 -I../deps/include
LDFLAGS = -mwindows -L../deps/lib
LIBS = -lraylib
BUILD_DEPS = true
EXEC = .exe
RC = x86_64-w64-mingw32-windres

RAYLIB_BUILD = PLATFORM_OS=WINDOWS
