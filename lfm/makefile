CXX = ../build/fcx
CCF = ../build/fcf
LMF = ./config.sh
LCF = ../lfc/config.sh

BLDDIR=../build/
CPPFLAGS =-g -gdwarf-4 -shared -fPIC `$(CCF) --cxxflags` `$(CCF) --ldflags` `$(LCF) --includedir` `$(LMF) --includedir` -Wno-unused-command-line-argument -std=c++17 -frtti -fexceptions

####################### ALL #######################
all: lfm ut

.PHONY: clean

clean: clean-lfm clean-ut

####################### LFM #######################
lfm : llvm

clean-lfm: clean-llvm

####################### LLVM #######################
LLVM_SRC_DIR=src
LLVM_OBJ_DIR=$(BLDDIR)/lfm/obj

LLVMLIB=$(BLDDIR)/liblfm.so
LLVMSRCS :=$(wildcard $(LLVM_SRC_DIR)/*.cpp)
LLVMOBJS :=$(patsubst $(LLVM_SRC_DIR)/%.cpp, $(LLVM_OBJ_DIR)/%.o, $(LLVMSRCS))
LLVMDEPS :=$(patsubst $(LLVM_SRC_DIR)/%.cpp, $(LLVM_OBJ_DIR)/%.d, $(LLVMSRCS))
-include $(LLVMDEPS)

llvm: $(LLVMLIB)

$(LLVMLIB): $(LLVMOBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(LLVM_OBJ_DIR)/%.o: $(LLVM_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MD -MF $(LLVM_OBJ_DIR)/$*.d -MP

clean-llvm:
	rm -f $(LLVMLIB) $(LLVM_OBJ_DIR)/*.o $(LLVM_OBJ_DIR)/*.d


####################### UT #######################
UTDIR=test_unit
ut: lfm
	$(MAKE) -C $(UTDIR) all;

clean-ut:
	$(MAKE) -C $(UTDIR) clean;
















