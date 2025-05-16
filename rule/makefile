CXX = ../build/fcx
CCF = ../build/fcf
RCF = ./config.sh
LCF = ../lfc/config.sh
ACF = ../lang/config.sh

BLDDIR=../build/
CPPFLAGS =-g -gdwarf-4 -shared -fPIC `$(CCF) --cxxflags` `$(CCF) --ldflags` `$(ACF) --includedir` `$(LCF) --includedir` `$(RCF) --includedir` -Wno-unused-command-line-argument -std=c++17 -frtti -fexceptions

####################### ALL #######################
all: rule ut

.PHONY: clean

clean: clean-rule clean-ut

####################### RULP #######################
RULP_SRC_DIR=src
RULP_OBJ_DIR=$(BLDDIR)/rule/obj

RULPLIB=$(BLDDIR)/librulp_rule.so
# RULPSRCS :=$(wildcard $(RULP_SRC_DIR)/**/*.cpp)
RULPSRCS := $(shell find $(RULP_SRC_DIR) -name '*.cpp')
RULPOBJS :=$(patsubst $(RULP_SRC_DIR)/%.cpp, $(RULP_OBJ_DIR)/%.o, $(RULPSRCS))
RULPDEPS :=$(patsubst $(RULP_SRC_DIR)/%.cpp, $(RULP_OBJ_DIR)/%.d, $(RULPSRCS))
-include $(RULPDEPS)

rule: $(RULPLIB)

$(RULPLIB): $(RULPOBJS) $(RULPOBJS2)
	$(CXX) $(CPPFLAGS) $^ -o $@ -lstdc++

$(RULP_OBJ_DIR)/%.o: $(RULP_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MD -MF $(RULP_OBJ_DIR)/$*.d -MP

clean-rule:
	rm -f $(RULPLIB) $(RULPOBJS) $(RULPDEPS)

####################### UT #######################
UTDIR=test_unit
ut: rule
	$(MAKE) -C $(UTDIR) all;

clean-ut:
	$(MAKE) -C $(UTDIR) clean;

















