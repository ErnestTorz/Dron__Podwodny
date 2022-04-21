#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/Wektor3D.o obj/MacierzObrotu.o obj/Bryla.o obj/Scena.o obj/Generatory.o
	g++ -Wall -pedantic -std=c++11 -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o obj/Wektor3D.o obj/MacierzObrotu.o obj/Bryla.o obj/Scena.o obj/Generatory.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/Wektor3D.o: inc/Wektor3D.hh src/Wektor3D.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/MacierzObrotu.o: inc/MacierzObrotu.hh src/MacierzObrotu.cpp inc/Wektor.hh inc/Macierz.hh inc/Wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/MacierzObrotu.o src/MacierzObrotu.cpp

obj/Bryla.o: inc/Bryla.hh src/Bryla.cpp inc/Wektor.hh inc/Macierz.hh inc/Wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/MacierzObrotu.hh inc/Wektor3D.hh inc/Macierz.hh inc/Wektor.hh inc/Bryla.hh inc/Zakresy.h inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Scena.o: inc/Scena.hh src/Scena.cpp inc/Macierz.hh inc/lacze_do_gnuplota.hh inc/Bryla.hh inc inc/Zakresy.h inc/Generatory.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Generatory.o: inc/Generatory.hh src/Generatory.cpp inc/Bryla.hh inc inc/Zakresy.h
	g++ -c ${CXXFLAGS} -o obj/Generatory.o src/Generatory.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
