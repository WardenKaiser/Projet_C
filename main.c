#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include<ncurses.h>
#include "projet.h"

// Bite tu as bien reçu les changements ? 

int main(int argc, char const *argv[])
{
	
 srand( time( NULL ) );
 struct hive Hive = create_hive(100);
 bee bee;
 int numberofBee = rand() % 10 + 1;
 for (int i = 0; i < numberofBee; i++) 
 {
		 bee = create_bee(i + 1);
		Hive.total_bees++;
    }
 
	/*struct hive Hive = create_hive(100);
	

	int males = 0;
	int females = 0;

	int total_children = reproduce(&Hive, &males, &females);

	printw("Number of children: %d\n", total_children);
	printw("Number of males: %d\n", males);
	printw("Number of females: %d\n", females);
*/
int males = 0;
	int females = 0;
	int current_day = 0;
	char touche;
	initscr();
	while (1) 
	{
		touche = getch();
		
	

	

	int total_children = reproduce(&Hive, &males, &females,current_day);
	struct bee my_bee = {0, 0, 0};
	int hive_x = 0;
    int hive_y = 0;
			struct FlowerNode* my_field = NULL;
			struct FlowerNode* season_node = NULL; // GROS DOUTE SUR CA A VERIFIER
			create_field(&my_field, &season_node); // GROS DOUTE SUR CA A VERIFIER		
			add_flower(my_field);
			bee_life_cycle(&bee ,current_day,&Hive);
		if (touche == 'q') 
		{
			printw("Fin de la simulation.\n");
			break;
		} else if (touche != ERR) 
		{
			current_day++;
			clear();
			printw("jour : %d\n", current_day);
		 	printw("Food Capacity: %d\n", Hive.food_cap);
		    printw("Current Food Level: %d\n", Hive.food_lvl);
		    printw("Total Bees: %d\n", Hive.total_bees);
			printw("Total larvas:%d\n",Hive.total_larva);
			printw("Total Nannies:%d\n",Hive.total_nannies);
			printw("Total Receivers:%d\n",Hive.total_receivers);
			printw("Total Guards:%d\n",Hive.total_guards);
			printw("Total Forager:%d\n",Hive.total_foragers);
			printw("Number of males: %d\n", males);
			printw("Number of females: %d\n", females);
			collect_pollen_from_field(&my_bee, my_field, hive_x, hive_y, current_day);
		   
			display_field(my_field);
			free_field(my_field);	
//			test();		


			refresh();
		}
	}


	endwin();



	struct bee* my_bee2 = {0, 0, 0};
	int hive_x2 = 0;
	int hive_y2 = 0;

	// Ruche avec arbre 

	struct hiveNode_hive2* root = create_hive2(10);
    root->left = create_hive2(5);
    root->right = create_hive2(8);
    root->left->left = create_hive2(3);
    root->left->right = create_hive2(2);
    root->right->left = create_hive2(4);
    root->right->right = create_hive2(6);

    int totalBeesCount2 = totalBees2(root);

    printf("Le nombre total d'abeilles dans la ruche est : %d\n", totalBeesCount2);
	
	return 0;
}
