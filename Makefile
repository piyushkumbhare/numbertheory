# This is the parent Makefile

all:
	+$(MAKE) -C power-mod
	+$(MAKE) -C quadratic-residue

clean:
	+$(MAKE) -C power-mod clean
	+$(MAKE) -C quadratic-residue clean
