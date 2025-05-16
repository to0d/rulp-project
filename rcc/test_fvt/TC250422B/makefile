#TEST: Level 0, Optimize rulp, only function in module

RCC = ../../../bin/rcc

main.ll: main.rulp
	/bin/bash -c "$(RCC) -o $@ -c $^ -S -emit-llvm -t 1> trace.txt 2>&1"

clean:
	rm -rf *.expand.*
	rm -rf output.c
	rm -rf trace.txt

