PLATFORM = generic

include ./mk/p_$(PLATFORM).mk

.PHONY: all

all:  ./gears$(EXEC)
