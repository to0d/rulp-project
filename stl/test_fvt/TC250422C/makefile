#TEST: lfc, Compile_ CPP, test lfc stl library

SCF 			= ../../build/scf
FCC 			= `$(SCF) --fcc`
CXXFLAGS 	= `$(SCF) --cxxflags`
LDFLAGS 	= `$(SCF) --ldflags`


a.out: main.cpp
	$(FCC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.out

