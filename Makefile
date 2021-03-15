run: main.o Executive.o Player.o Ship.o Parent.o AI.o
	g++ -std=c++11 -g -Wall main.o Executive.o Player.o Ship.o Parent.o AI.o -o run

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp

Ship.o: Ship.h Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

Parent.o: Parent.h Parent.cpp
	g++ -std=c++11 -g -Wall -c Parent.cpp

AI.o: AI.h AI.cpp
	g++ -std=c++11 -g -Wall -c AI.cpp

clean:
	rm *.o run
