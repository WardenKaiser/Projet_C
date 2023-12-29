projet: projet.o main.o
	gcc -std=c99 -o projet projet.o main.o -lncurses

projet.o: projet.c
	gcc -std=c99 -c projet.c -o projet.o -W -lncurses

main.o: main.c projet.h
	gcc -std=c99 -c main.c -o main.o -W -lncurses