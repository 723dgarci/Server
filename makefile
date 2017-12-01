CFLAGS = -std=c++11 -Wall -pedantic 

all: proj5.x 

proj5.x: proj5.o passserver.o
	g++ $(CFLAGS) -lcrypt -o  $@ $^


proj5.o: hashtable.h proj5.cpp
	g++ $(CFLAGS) -c $^

passserver.o: passserver.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm *.o *.gch
