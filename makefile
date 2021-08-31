CXX      := -g++
CXXFLAGS := -Wall -Wextra -std=c++17 -m64
LDLIBS   := -lSDL2main -lSDL2 -lSDL2_image

BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps

TARGET   := rr

SRCFILES := $(wildcard src/*.cpp)
OBJECTS  := $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRCFILES))

run: all 
	@ln -sf $(APP_DIR)/$(TARGET) $(TARGET)
	./$(TARGET)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.cpp
	-@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	-@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDLIBS)


.PHONY:build
build:
	-@mkdir -p $(APP_DIR)
	-@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

.PHONY:clean
clean:
	-@rm -rf $(BUILD)/*
	-@rm -rf $(TARGET)

.PHONY:git
git: 
	@git add ./
	@git commit -m "$m"
	@git push -u origin main

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
