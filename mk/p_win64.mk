# Win64 build

TCLTK_VERSION = 8.6

CC = x86_64-w64-mingw32-gcc
CFLAGS = -g -std=c99 -I../deps/include
LDFLAGS = -mwindows -L../deps/lib
LIBS = -lraylib
BUILD_DEPS = true
EXEC = .exe

RAYLIB_BUILD = OS=WINDOWS