CC = gcc
CXX = g++ -std=c++11
RM = rm -f
FLAGS = -o

ordenacion: main.o
	$(CXX) $(FLAGS) ordenacion *.hpp *.cpp
clean:
	$(RM) ordenacion *.gch *.o
