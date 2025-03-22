CXX = g++
CXXFLAGS = -I -Wall -Wextra -std=c++17 
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

SRC = main.cpp \
	$(wildcard Engine/*.cpp) \
	$(wildcard Engine/Core/*.cpp) \
	$(wildcard Engine/DataTypes/*.cpp) \
	$(wildcard Engine/Graphic/*.cpp) \
	$(wildcard Engine/Widgets/*.cpp) \
	$(wildcard Engine/Event/*.cpp) 
	
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
run: $(TARGET)
	./$(TARGET)

play: clean all run
