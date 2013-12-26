CC = g++
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c++11 -g -ggdb
LIBS = `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lglfw

EXEC = chip8
SRC = keyboard.cc rom.cc screen.cc chip8.cc main.cc
OFILES = ${SRC:.cc=.o}

all: $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $^ -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) -o $@ -c $<
