#
#  Makefile for Assignment 4
#
#  by Vincent Wang(yuwenWang)
#  vincent08tw@yahoo.com.tw
#  vincent08tw@gmail.com
#

CC = g++
PCFLAG = -O1 -Wall -c
POFLAG = -O1 -Wall
HDR = Node.h List.h 
SRC = ${HDR:.h=.cpp} main.cpp
OBJ = ${HDR:.h=.o} main.o
TARGET = list

all: $(TARGET)
Node.o: Node.h Node.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
List.o: List.h List.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
main.o: main.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
$(TARGET): $(OBJ)
	$(CC) $(POFLAG) $(LIB) $(OBJ) -o $@

clean:
	rm $(OBJ)
	rm $(TARGET)

exe:
	$(TARGET) double.txt string.txt