include ../config.mk

ENGINE = engine/core.o engine/log.o engine/tcl.o engine/util.o

OBJS = main.o $(ENGINE)

.PHONY: all clean
.SUFFIXES: .c .o

all: gears$(EXEC)

gears$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -DPREFIX='"$(PREFIX)"' -c -o $@ $<

clean:
	rm -f gears gears.exe *.o */*.o
