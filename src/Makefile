CC = g++
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c++11

EXEC = chip8
SRC = rom.cc chip8.cc main.cc
OFILES = ${SRC:.cc=.o}

all: $(OFILES)
	$(CC) $(CXXFLAGS) $^ -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) -o $@ -c $<

