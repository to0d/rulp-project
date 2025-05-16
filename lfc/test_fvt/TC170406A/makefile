#TEST: lfc base Compile_ - test is_dir/mkdirs/rm_dir

FCX	= ../../../build/fcx
LCF = ../../config.sh
CPPFLAGS= `$(LCF) --includedir` -g -std=c++17
LDFLAGS	= -llfc -lstdc++ -L../../../build

a.out: TC170406A.o
	$(FCX) $(LDFLAGS) -o $@ $^
..c.o:
	$(FCX) $(CPPFLAGS) -c $<

clean:
	rm -f *.o
	rm -f a.out