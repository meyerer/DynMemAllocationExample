output: main.o Space.o Game.o Quest1.o Quest2.o Quest3.o Quest4.o Quest5.o Quest6.o Trolls.o 
	g++ main.o Space.o Game.o Quest1.o Quest2.o Quest3.o Quest4.o Quest5.o Quest6.o Trolls.o -o output


main.o: main.cpp
	g++ -c main.cpp -std=gnu++11

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp -std=gnu++11

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp -std=gnu++11

Quest1.o: Quest1.cpp Quest1.hpp
	g++ -c Quest1.cpp -std=gnu++11

Quest2.o: Quest2.cpp Quest2.hpp
	g++ -c Quest2.cpp -std=gnu++11

Quest3.o: Quest3.cpp Quest3.hpp
	g++ -c Quest3.cpp -std=gnu++11

Quest4.o: Quest4.cpp Quest4.hpp
	g++ -c Quest4.cpp -std=gnu++11

Quest5.o: Quest5.cpp Quest5.hpp
	g++ -c Quest5.cpp -std=gnu++11

Quest6.o: Quest6.cpp Quest6.hpp
	g++ -c Quest6.cpp -std=gnu++11

Trolls.o: Trolls.cpp Trolls.hpp
	g++ -c Trolls.cpp -std=gnu++11

clean:
	rm *.o output
