CC = clang++
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c++11 -O0 -g -ggdb
INCLUDE = -I /opt/local/include
LIBS = `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lglfw3

EXEC = chip8
SRC = keyboard.cc rom.cc screen.cc chip8.cc main.cc
OFILES = ${SRC:.cc=.o}

all: .depend $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $(OFILES) -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f .depend
	rm -f $(OFILES)

depend: .depend

.depend: $(SRC)
	rm -f .depend
	$(CC) -MM $(INCLUDE) $^ > .depend

include .depend
