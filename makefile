CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
LDFLAGS_WIN = -lgdi32 -luser32
LDFLAGS_LINUX = -lX11
SRC = src/*.cpp src/shapes/*.cpp test/*.cpp main.cpp

LDFLAGS :=

ifeq ($(OS),Windows_NT)
	LDFLAGS += $(LDFLAGS_WIN)
else
	LDFLAGS += $(LDFLAGS_LINUX)
endif

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)
	

clean:
	rm -f main