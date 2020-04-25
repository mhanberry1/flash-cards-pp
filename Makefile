# User-configurable options

APP_NAME = flashcards

# Compilation targets

LIB = flashCards cli
BIN = main-cli
BIN_LINKS = $(BIN:main%=$(APP_NAME)%)

# Directories

LIB_DIR = lib
OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin

# Compiler configuration

CXX = g++
CXXFLAGS = -L$(LIB_DIR)
CLEAN = rm -rf

# Make configuration

VPATH = $(LIB_DIR):$(SRC_DIR):$(OBJ_DIR):$(BIN_DIR)

# Basic make commands

all: $(LIB:%=%.o) $(LIB:%=lib%.so) $(BIN) $(BIN_LINKS)
	
clean:
	$(CLEAN) $(LIB_DIR) $(OBJ_DIR) $(BIN_DIR) $(BIN_LINKS)

remake: clean all

# Create links in the root directory to compiled binaries

$(BIN_LINKS):
	ln -s $(BIN_DIR)/$(^:$APP_NAME%=main%) $@

# Compile binaries

$(BIN): $(BIN:%=%.cpp)
	cd $(SRC_DIR)
	$(CXX) $^ -o $@ $(CXXFLAGS)
	mv $@ $(BIN_DIR)
	cd ..

# Comile object files

$(LIB:%=%.o): $(LIB:%=%.h) $(LIB:%=%.cpp)
	cd $(SRC_DIR)
	$(CXX) $^ $(CXXFLAGS) -c -fpic
	mkdir -p $(OBJ_DIR)
	mv $@ $(OBJ_DIR)
	cd ..

# Comile shared libraries

$(LIB:%=lib%.so): $(LIB:%=%.o)
	cd $(SRC_DIR)
	$(CXX) $^ -o $@ $(CXXFLAGS) -shared
	mkdir -p $(LIB_DIR)
	mv $@ $(LIB_DIR)
	cd ..
