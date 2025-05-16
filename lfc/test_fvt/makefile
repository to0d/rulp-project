exclude_dirs:=.

SUBDIRS:=$(shell find . -maxdepth 1 -type d)
SUBDIRS:=$(filter-out $(exclude_dirs), $(SUBDIRS))

.PHONY: all $(SUBDIRS)

all: $(SUBDIRS)

.PHONY: $(dirs) clean

$(SUBDIRS):
	$(MAKE) -s -C $@ || exit 1

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -s -C $$dir clean; \
	done






