CXX = ../build/fcx
CCF = ../build/fcf
LCF = ./config.sh

BLDDIR=../build/
CPPFLAGS =-g -gdwarf-4 -shared -fPIC `$(CCF) --cxxflags` `$(CCF) --ldflags` `$(LCF) --includedir` -Wno-unused-command-line-argument -std=c++17 -frtti -fexceptions

####################### ALL #######################
all: lfc ut fvt

.PHONY: clean

clean: clean-lfc clean-ut clean-fvt

####################### LFC #######################
lfc : base

clean-lfc: clean-base

####################### BASE #######################
BASE_SRC_DIR=src
BASE_OBJ_DIR=$(BLDDIR)/lfc/obj

BASELIB=$(BLDDIR)/liblfc.so
BASESRCS :=$(wildcard $(BASE_SRC_DIR)/*.cpp)
BASEOBJS :=$(patsubst $(BASE_SRC_DIR)/%.cpp, $(BASE_OBJ_DIR)/%.o, $(BASESRCS))
BASEDEPS :=$(patsubst $(BASE_SRC_DIR)/%.cpp, $(BASE_OBJ_DIR)/%.d, $(BASESRCS))
-include $(BASEDEPS)


base: $(BASELIB)

$(BASELIB): $(BASEOBJS) $(BASEOBJS2)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BASE_OBJ_DIR)/%.o: $(BASE_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MD -MF $(BASE_OBJ_DIR)/$*.d -MP

clean-base:
	rm -f $(BASELIB) $(BASE_OBJ_DIR)/*.o $(BASE_OBJ_DIR)/*.d


####################### UT #######################
UTDIR=test_unit
ut: lfc
	$(MAKE) -C $(UTDIR) all;

clean-ut:
	$(MAKE) -C $(UTDIR) clean;

####################### FVT #######################
TEST_FVT_DIR=test_fvt
fvt:
	$(MAKE) -C $(TEST_FVT_DIR);

clean-fvt: 
	$(MAKE) -C $(TEST_FVT_DIR) clean;

















