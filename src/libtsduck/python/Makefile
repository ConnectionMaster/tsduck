# Dummy makefile for subdirectory in vpath. Actual make is under control of parent directory.

DONT_BUILD_DEPS := TRUE
include ../../../Makefile.tsduck

NORECURSE_SUBDIRS += ts
EXTRA_DISTCLEAN += ts/__pycache__ ts/*/__pycache__ ts/*/*/__pycache__

default:
	@true

.PHONY: install
install:
	install -d -m 755 $(SYSROOT)$(SYSPREFIX)/share/tsduck/python/ts
	install -m 644 ts/*.py $(SYSROOT)$(SYSPREFIX)/share/tsduck/python/ts
