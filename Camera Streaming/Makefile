##
##	Makefile for bravoGO in /home/inho/basaiWays/bravoSYS_cpp
##
##	Made by InHo
##
## Started on  Fri Nov 14  2018		InHo, Lin
## Last update Sun Nov     2018		InHo, Lin
##
EXECUTABLE=goThreadCV
#gcc my_program.c `pkg-config --cflags --libs gumbo`
#  https://github.com/google/gumbo-parser
#  reference:  https://github.com/google/gumbo-parser
CC=g++
CFLAGS=-c -Wall -std=c++14 -pthread -g -I/usr/local/include -L/usr/local/lib $(mysql_config --cflags) $(shell pkg-config --cflags opencv4)
#CFLAGS += $(shell pkg-config --cflags opencv4)
LDFLAGS=-g -I/usr/local/include  -L/usr/local/lib
LIBS=-O3   -lpthread -ltbb
LIBS+= $(shell pkg-config --libs opencv4)
DEPS=$(wildcard *.h)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

#run:
#	./$(EXECUTABLE)
