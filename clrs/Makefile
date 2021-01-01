TARGET ?= parking_lot

SRC_DIR ?= src
BIN_DIR ?= bin
BUILD_DIR ?= build
TEST_DIR ?= test
.DEFAULT_GOAL ?= $(TARGET)

CXX = g++
CXXFLAGS = -c -g 

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
INCS := -I $(SRC_DIR)/
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o) 
DEPS := $(OBJS:.o=.d)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@$(CXX) $(OBJS) -o $@
	@echo "[DONE] Build Successful."

$(BUILD_DIR)/%.cpp.o : %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@ $(INCS)
	@echo "[DONE] Compilation Successful."

setup: clean
	@rm -rf deps/googletest-release-1.10.0
	@bash install_gtest.sh && echo "[SUCCESS] googletest installed." 

clean:
	@rm -f $(BIN_DIR)/$(TARGET)
	@rm -rf $(BUILD_DIR)
	@echo "[SUCCESS] clean."

test : FORCE 
	make -f makefile.test test

FORCE: ;
MKDIR_P ?= mkdir -p
-include $(DEPS)
