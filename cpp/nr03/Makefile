
# The -Wall option sets all warnings on. Take warnings seriously:
# c++14 is the C++ standard (from 2014).
# It is important to use c++11 at least, because in that year
# there was a big reform. 

main : string.o main.o
	g++ -o main main.o string.o

main.o : main.cpp string.h 
	g++ -o main.o -c main.cpp -Wall -std=c++14   

string.o : string.cpp string.h
	g++ -o string.o -c string.cpp -Wall -std=c++14


