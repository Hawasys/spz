CXX      := -g++
CXXFLAGS := -Wall -Wextra -std=c++17 -m64 -I include
LDLIBS   := -lSDL2main -lSDL2 -lSDL2_image

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps

TARGET   := rr

SRC      := $(wildcard ./src/*.cpp)
OBJECTS  := $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

run: all 
	@ln -sf $(APP_DIR)/$(TARGET) $(TARGET)
	./$(TARGET)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: $(SRC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDLIBS)

build:
	-@mkdir -p $(APP_DIR)
	-@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rf $(BUILD)/*
	-@rm -rf $(TARGET)
info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
