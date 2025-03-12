PLATFORM = generic

.PHONY: all clean ./src

all: ./src

./config.mk: mk/p_$(PLATFORM).mk
	cp mk/p_$(PLATFORM).mk $@

./src:: ./config.mk
	$(MAKE) -C $@

clean:
	$(MAKE) -C $@ clean
