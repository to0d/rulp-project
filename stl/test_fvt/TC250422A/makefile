#TEST: std, Compile_ CPP, test std vector

SCF 			= ../../build/scf
FCC 			= `$(SCF) --fcc`
CXXFLAGS 	= `$(SCF) --cxxflags`
LDFLAGS 	= `$(SCF) --ldflags`

a.out: main.cpp
	$(FCC) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.out
	rm -rf *.o

