CC=g++
CFLAGS=-I src/include
LDFLAGS=-L src/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
DEBUG_FLAGS=-g
RELEASE_FLAGS=-O3

SRC=main.cpp player.cpp spike.cpp
OBJ=$(SRC:.cpp=.o)

DEBUG_TARGET=debug
RELEASE_TARGET=release

all: $(DEBUG_TARGET) $(RELEASE_TARGET)

$(DEBUG_TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^ $(LDFLAGS)

$(RELEASE_TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c -o $@ $<

clean:
	del /Q $(OBJ) $(DEBUG_TARGET) $(RELEASE_TARGET)

