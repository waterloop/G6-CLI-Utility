# Makefile
CXX := g++
PROTOC := protoc

# dirs
SRC_DIR := src
PROTO_DIR := proto
BUILD_DIR := build
GEN_DIR := $(BUILD_DIR)/gen

# proto gen settings
PROTO_FILES := $(wildcard $(PROTO_DIR)/*.proto)
PROTO_GEN_CPP := $(PROTO_FILES:$(PROTO_DIR)/%.proto=$(GEN_DIR)/%.pb.cc)
PROTO_GEN_H := $(PROTO_FILES:$(PROTO_DIR)/%.proto=$(GEN_DIR)/%.pb.h)
PROTO_GEN := $(PROTO_GEN_CPP) $(PROTO_GEN_H)

# compiler flags (recommended by google)
CPPFLAGS := -I$(GEN_DIR) -I.
LDFLAGS := -L/usr/local/lib `pkg-config --libs protobuf` -pthread

# src and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc) $(PROTO_GEN_CPP)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cc=$(BUILD_DIR)/%.o) $(PROTO_GEN_CPP:$(GEN_DIR)/%.cc=$(BUILD_DIR)/%.o)

# target exec
TARGET := $(BUILD_DIR)/my_app

# default rule
all: $(TARGET)

# create build dir
$(BUILD_DIR) $(GEN_DIR):
	mkdir -p $@

# Rule for compiling proto files
$(PROTO_GEN): $(PROTO_FILES) | $(GEN_DIR)
	$(PROTOC) --cpp_out=$(GEN_DIR) --proto_path=$(PROTO_DIR) $(PROTO_FILES)

# Rule for compiling source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) -c $(CPPFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(GEN_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) -c $(CPPFLAGS) $< -o $@

# Rule for linking object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean