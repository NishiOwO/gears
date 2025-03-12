PLATFORM = generic
TOP = .

include ./config.mk

.PHONY: all clean pack ./src ./deps

all: ./src

./config.mk:
	cp mk/p_$(PLATFORM).mk $@

./src:: ./config.mk ./deps
	$(MAKE) -C $@ TOP="`pwd`"

./deps:: ./config.mk
	mkdir -p ./deps/include
	mkdir -p ./deps/lib
	if $(BUILD_DEPS); then $(MAKE) -C $@ TOP="`pwd`" ; fi

pack: all
	rm -rf packed
	mkdir -p packed/bin
	mkdir -p packed/lib
	cp src/gears$(EXEC) packed/bin/
	-cp deps/lib/*.so packed/lib/
	-cp -rf deps/lib/tcl8.6 packed/lib/tcl8.6
	-cp deps/lib/*.dll packed/bin/
	-cp deps/bin/*.dll packed/bin/

clean:
	$(MAKE) -C ./src clean TOP="`pwd`"
	$(MAKE) -C ./deps clean TOP="`pwd`"
	rm -rf packed
