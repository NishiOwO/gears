include ../config.mk

OBJS = main.o engine/core.o

.PHONY: all clean
.SUFFIXES: .c .o

all: gears$(EXEC)

gears$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f gears$(EXEC) *.o */*.o
