CXX = ../build/fcx
CCF = ../build/fcf
RCF = ./config.sh
LCF = ../lfc/config.sh
ACF = ../lang/config.sh

BLDDIR=../build/
CPPFLAGS =-g -gdwarf-4 -shared -fPIC `$(CCF) --cxxflags` `$(CCF) --ldflags` `$(ACF) --includedir` `$(LCF) --includedir` `$(RCF) --includedir` -Wno-unused-command-line-argument -std=c++17 -frtti -fexceptions

####################### ALL #######################
all: opt ut

.PHONY: clean

clean: clean-opt clean-ut

####################### RULP #######################
RULP_SRC_DIR=src
RULP_OBJ_DIR=$(BLDDIR)/opt/obj

RULPLIB=$(BLDDIR)/librulp_opt.so
# RULPSRCS :=$(wildcard $(RULP_SRC_DIR)/**/*.cpp)
RULPSRCS := $(shell find $(RULP_SRC_DIR) -name '*.cpp')
RULPOBJS :=$(patsubst $(RULP_SRC_DIR)/%.cpp, $(RULP_OBJ_DIR)/%.o, $(RULPSRCS))
RULPDEPS :=$(patsubst $(RULP_SRC_DIR)/%.cpp, $(RULP_OBJ_DIR)/%.d, $(RULPSRCS))
-include $(RULPDEPS)

opt: $(RULPLIB)

$(RULPLIB): $(RULPOBJS) $(RULPOBJS2)
	$(CXX) $(CPPFLAGS) $^ -o $@ -lstdc++

$(RULP_OBJ_DIR)/%.o: $(RULP_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MD -MF $(RULP_OBJ_DIR)/$*.d -MP

clean-opt:
	rm -f $(RULPLIB) $(RULPOBJS) $(RULPDEPS)

####################### UT #######################
UTDIR=test_unit
ut: opt
	$(MAKE) -C $(UTDIR) all;

clean-ut:
	$(MAKE) -C $(UTDIR) clean;

















