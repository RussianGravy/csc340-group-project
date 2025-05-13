CC = g++
CCFLAGS = -std=c++2a -g -fsanitize=address

CPP_FILES = $(shell find . -name "*.cpp")

a.out: clean main.cpp
	$(CC) -I./include $(CCFLAGS) $(CPP_FILES)

clean:
	rm -rf a.out main *.o core *.dSYM
