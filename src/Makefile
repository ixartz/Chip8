CC = clang++
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c++11 -O0 -g -ggdb
INCLUDE = -I /opt/local/include
LIBS = `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lglfw

EXEC = chip8
SRC = keyboard.cc rom.cc screen.cc chip8.cc main.cc
OFILES = ${SRC:.cc=.o}

all: $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $^ -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OFILES)
