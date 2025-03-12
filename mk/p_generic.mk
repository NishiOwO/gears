# Generic build

CC = gcc
CFLAGS = -g -std=c99 `pkg-config --cflags tcl` `pkg-config --cflags tk`
LDFLAGS =
LIBS = `pkg-config --libs tcl` `pkg-config --libs tk`
