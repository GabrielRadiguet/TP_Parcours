CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
LDFLAGS_WIN = -lgdi32 -luser32 # Flags pour les bibliothèques graphiques sur Windows
LDFLAGS_LINUX = -lX11 # Flag pour la bibliothèque graphiques X11 sur Linux
SRC = src/*.cpp src/shapes/*.cpp test/*.cpp main.cpp

LDFLAGS :=

ifeq ($(OS),Windows_NT) # Detection de l'OS
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