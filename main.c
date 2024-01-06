#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include<ncurses.h>
#include "projet.h"

int main()
{
	
 srand( time( NULL ) );
 int numberofBee = rand() % 10 + 1;
 for (int i = 0; i < numberofBee; i++) 
 {
		bee bee = create_bee(i + 1);
    }
 
	struct hive* Hive = NULL;
	create_hive(&Hive);

	int males = 0;
	int females = 0;

	int total_children = reproduce(&Hive, &males, &females);

	printf("Number of children: %d\n", total_children);
	printf("Number of males: %d\n", males);
	printf("Number of females: %d\n", females);


	int jour = 0;
	char touche;
	initscr();
	while (1) 
	{
		touche = getch();

		if (touche == 'q') 
		{
			printw("Fin de la simulation.\n");
			break;
		} else if (touche != ERR) 
		{
			jour++;
			clear();
			printw("jour : %d\n", jour);
			refresh();
		}
	}


	endwin();

	// Champs  
	struct FlowerNode* my_field = NULL;
	struct FlowerNode* season_node = NULL; // GROS DOUTE SUR CA A VERIFIER
	create_field(&my_field, &season_node); // GROS DOUTE SUR CA A VERIFIER
	display_field(my_field);
	free_field(my_field);

	struct bee* my_bee = {0, 0, 0};
	int hive_x = 0;
	int hive_y = 0;
	
	return 0;
}
