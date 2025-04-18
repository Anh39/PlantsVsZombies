CXX = g++
CXXFLAGS = -g -O0 -I -Wall -Wextra -std=c++17 -IEngine
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

ENGINE_SRC = $(wildcard Engine/*.cpp) \
	$(wildcard Engine/Core/*.cpp) \
	$(wildcard Engine/DataTypes/*.cpp) \
	$(wildcard Engine/Graphic/*.cpp) \
	$(wildcard Engine/Widgets/*.cpp) \
	$(wildcard Engine/Nodes/*.cpp) 	\
	$(wildcard Engine/Event/*.cpp) 	
ENGINE_OBJ = $(ENGINE_SRC:.cpp=.o)

GAME_SRC = main.cpp \
	$(wildcard Game/*.cpp) \
	$(wildcard Game/Plants/*.cpp) \
	$(wildcard Game/Zombies/*.cpp) \
	$(wildcard Game/UI/*.cpp) \
	$(wildcard Game/UI/Landing/*.cpp) \
	$(wildcard Game/UI/TitleMenu/*.cpp) \
	$(wildcard Game/UI/AdventureMode/*.cpp) \
	$(wildcard Game/UI/OverlayMenu/*.cpp) \
	$(wildcard Game/UI/OverlayMenu/Components/*.cpp) \
	$(wildcard Game/UI/OverlayMenu/Overlays/*.cpp) \
	$(wildcard Game/UI/Components/*.cpp) \
	$(wildcard Game/UI/Widgets/*.cpp) \
	$(wildcard Game/Levels/*.cpp) \
	# $(wildcard Prototype/UI/*.cpp) \
	# $(wildcard Prototype/Plants/*.cpp) \
	# $(wildcard Prototype/Zombies/*.cpp) \


GAME_OBJ = $(GAME_SRC:.cpp=.o)

TARGET = main
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

compile_all: $(TARGET)
$(TARGET): $(ENGINE_OBJ) $(GAME_OBJ)
	$(CXX) $(ENGINE_OBJ) $(GAME_OBJ) -o $(TARGET) $(LDFLAGS)
clean_all:
	rm -f $(ENGINE_OBJ) $(GAME_OBJ) $(TARGET)
run_all: $(TARGET)
	./$(TARGET)
play_all: clean_all compile_all run_all

compile: $(GAME_OBJ)
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(GAME_OBJ) $(TARGET)
play: clean compile run
