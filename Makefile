PLATFORM = generic

.PHONY: all clean ./src ./deps

all: ./src

./config.mk:
	cp mk/p_$(PLATFORM).mk $@

./src:: ./config.mk ./deps
	$(MAKE) -C $@

./deps:: ./config.mk
	$(MAKE) -C $@

clean:
	$(MAKE) -C ./src clean
