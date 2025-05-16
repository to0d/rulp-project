exclude_dirs:=. ./script ./profiling

dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(filter-out $(exclude_dirs), $(dirs))

all: $(dirs)

.PHONY: $(dirs) clean

$(dirs):
	$(MAKE) -s -C $@ || exit 1

clean:
	@find . -name "result.txt" -exec rm -rf {} \;
	@find . -name "*.dot" -exec rm -rf {} \;
	@find . -name "trace.txt" -exec rm -rf {} \;
	@for dir in $(dirs); do \
		$(MAKE) -s -C $$dir clean; \
	done

