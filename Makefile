A05: main.o Escape.o Hero.o Participant.o random.o Snorc.o MoveBehaviour.o Ninja.o
	g++ -std=c++11 -o A05 main.o Escape.o Hero.o Participant.o random.o Snorc.o MoveBehaviour.o Ninja.o

main.o: main.cc Escape.h
	g++ -std=c++11 -c main.cc

Escape.o: Escape.cc Escape.h
	g++ -std=c++11 -c Escape.cc

Hero.o: Hero.cc Hero.h
	g++ -std=c++11 -c Hero.cc

Participant.o: Participant.cc Participant.h
	g++ -std=c++11 -c Participant.cc

random.o: random.cc defs.h
	g++ -std=c++11 -c random.cc

Snorc.o: Snorc.cc Snorc.h
	g++ -std=c++11 -c Snorc.cc

Ninja.o: Ninja.cc Ninja.h
	g++ -std=c++11 -c Ninja.cc

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h
	g++ -std=c++11 -c MoveBehaviour.cc

clean:
	rm -f *.o A05
