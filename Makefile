PLATFORM = generic
TOP = .

include ./config.mk

.PHONY: all clean format pack ./src ./deps

all: ./src

./config.mk:
	cp mk/p_$(PLATFORM).mk $@

./src:: ./config.mk ./deps
	$(MAKE) -C $@ TOP="`pwd`"

./deps:: ./config.mk
	mkdir -p ./deps/include
	mkdir -p ./deps/lib
	if $(BUILD_DEPS); then $(MAKE) -C $@ TOP="`pwd`" ; fi

format:
	clang-format --verbose -i `find src -name "*.c" -or -name "*.h"`

pack: all
	rm -rf packed
	mkdir -p packed/bin
	mkdir -p packed/lib
	cp src/gears$(EXEC) packed/bin/
	-cp deps/lib/*.so packed/lib/
	-cp -rf deps/lib/tcl$(TCLTK_VERSION) packed/lib/tcl$(TCLTK_VERSION)
	-cp -rf deps/lib/tk$(TCLTK_VERSION) packed/lib/tk$(TCLTK_VERSION)
	-cp deps/lib/*.dll packed/bin/
	-cp deps/bin/*.dll packed/bin/

clean:
	$(MAKE) -C ./src clean TOP="`pwd`"
	$(MAKE) -C ./deps clean TOP="`pwd`"
	rm -rf packed
