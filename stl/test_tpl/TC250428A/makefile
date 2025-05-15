#TEST: template, Compile_ CPP, test class template

SCF 			= ../../build/scf
FCC 			= `$(SCF) --fcc`
CXXFLAGS 	= `$(SCF) --cxxflags`
LDFLAGS 	= `$(SCF) --ldflags`

a.out: main.cpp
	$(FCC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.out

