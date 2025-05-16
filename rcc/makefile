CXX = ../build/fcx
CCF = ../build/fcf
RCF = ./config.sh
LCF = ../lfc/config.sh
ACF = ../lang/config.sh

BLDDIR=../build/
LIBDIR=lib
UTILDIR=util

CPPFLAGS =-g -gdwarf-4 -shared -fPIC `$(CCF) --cxxflags` `$(CCF) --ldflags` `$(ACF) --includedir` `$(LCF) --includedir` `$(RCF) --includedir` -Wno-unused-command-line-argument -std=c++17 -frtti -fexceptions

####################### ALL #######################
all: rcc util

.PHONY: clean

clean: clean-rcc clean-util

####################### RCC #######################



####################### UTIL #######################
util : formater

clean-util: clean-formater

####################### formater #######################
RCC_CMD_FORMAT=$(LIBDIR)/cmd_format.out

formater: $(RCC_CMD_FORMAT)

$(RCC_CMD_FORMAT) : $(UTILDIR)/cmd-format.o $(BLDDIR)/lfc/obj/cmd_arg.o
	@mkdir -p $(dir $@)
	$(CXX) $(UTILDIR)/cmd-format.o $(BLDDIR)/lfc/obj/cmd_arg.o -lstdc++ -o $@

clean-formater:
	rm -f $(RCC_CMD_FORMAT)
	rm -f $(UTILDIR)/cmd-format.o
