#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include<time.h>
#include<ncurses.h>

int main(int argc, char const *argv[])
{
	/*int x;
	printf("print\n");
clock_t start_time, end_time;

    start_time = clock();

    while ( x !=1000)
	{
	printf("print\n");
	x++;
	}
	
    
    end_time = clock();

    
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Le temps écoulé est de %.2f secondes.\n", elapsed_time);
	*/

 srand( time( NULL ) );
 
   int jour = 0;
    char touche;
    initscr();
    while (1) 
	{
        touche = getch();

        if (touche == 'q') 
		{
            printw("Sortie du programme.\n");
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
return 0;

}
