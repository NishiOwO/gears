# Generic build

include $(TOP)/version.mk

TCLTK_PLATFORM = unix

PREFIX = /usr/gears

CC = gcc
CFLAGS = -g -std=c99 `pkg-config --cflags x11 2>/dev/null` `pkg-config --cflags tcl 2>/dev/null` `pkg-config --cflags tk 2>/dev/null` `pkg-config --cflags tcl$(TCLTK_VERSION) 2>/dev/null` `pkg-config --cflags tk$(TCLTK_VERSION) 2>/dev/null`
LDFLAGS =
LIBS = `pkg-config --libs tcl 2>/dev/null` `pkg-config --libs tk 2>/dev/null` `pkg-config --libs tcl$(TCLTK_VERSION) 2>/dev/null` `pkg-config --libs tk$(TCLTK_VERSION) 2>/dev/null` -lraylib -lm
BUILD_DEPS = false
