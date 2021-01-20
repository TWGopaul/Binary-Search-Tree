# Programmer: Travis Gopaul
# Date: 11/8/20
# makefile for BST lab 7
# CC is variable for compiler name
# CFLAGS will be the option to pass

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Lab7.cpp TNode.cpp BST.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Lab7
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
