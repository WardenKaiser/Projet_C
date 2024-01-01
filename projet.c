#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct role
{
	int queen;
	int forager;
	int receiver;
	int drone;
	int nanny;
	int guard;
	int bumblebee;
	int larva;
}role;

typedef struct bee
{
	int age;
	int identifiant;
	role Role;
	int pollen_capacity;
	char sex;
}bee;

typedef struct hive
{
	int total_larva;
	int total_nannies;
	int total_receivers;
	int total_builders;
	int total_guards;
	int total_foragers;
}hive;

void bee_life_cycle(struct hive* hive ,int current_day)
{
	if (current_day >= 1 && current_day <= 3)
	{
		hive->total_larva =+ 2000;
	}

    if (current_day >= 4 && current_day <= 9)
    {
        hive->total_nannies = hive->total_larva;
        hive->total_larva -= hive->total_nannies;
    }

    if (current_day >= 10 && current_day <= 12)
    {
        hive->total_receivers = hive->total_nannies;
        hive->total_nannies = 0;
    }

    if (current_day >= 13 && current_day <= 18)
    {
        hive->total_builders = hive->total_receivers;
        hive->total_receivers = 0;
    }

    if (current_day >= 19 && current_day <= 22)
    {
        hive->total_guards = hive->total_builders;
        hive->total_builders = 0;
    }

    if (current_day >= 23 && current_day <= 45)
    {
        hive->total_foragers = hive->total_guards;
        hive->total_guards = 0;
    }

    if (current_day > 45)
    {
        hive->total_foragers = 0;
        hive->total_guards = 0;
        hive->total_builders = 0;
        hive->total_receivers = 0;
        hive->total_nannies = 0;
    }
}

void warming_up_the_hive(struct hive *hive, int temperature, int current_day)
{
    if (temperature >= 10 && hive->total_receivers > 0) 
    {
        for (int i = 0; i < hive->total_receivers; ++i)
        {
            hive->total_receivers[i].pollen_capacity -= 5;
        }
        printf("Foragers nerf\n");
    } 

    else if (temperature < 10 && temperature >= 7 && hive->total_receivers > 0) 
    {
        for (int i = 0; i < hive->total_receivers; ++i)
        {
            hive->total_receivers[i].pollen_capacity -= 10; 
        }
        printf("Foragers nerf\n");
    } 

    else if (temperature < 7 && hive->total_bees > 0) 
    {
        printf("Death !\n");

        hive->total_larva = 0;
        hive->total_nannies = 0;
        hive->total_receivers = 0;
        hive->total_builders = 0;
        hive->total_guards = 0;
        hive->total_foragers = 0;
    } 

    else 
    {
        printf("All good\n");
    }
}

bee create_bee(int identifiant)
{
	bee Bee;
	Bee.identifiant=identifiant;
	Bee.sex=rand();
	Bee.Role.larva;
	return Bee;
}
void reproduction()
{

}

void adding_bees_from_outside_the_hive(struct hive *hive)
{
    srand(time(NULL));
    int chance = rand() % 100;
    int chanceToAddBees = 30; 

    if (chance < chanceToAddBees)
    {      
        int new_bees_from_outside;
        new_bees_from_outside = rand() % 30 + 1;

        printf("Lucky you ! U found %d new bees !\n", new_bees_from_outside);
        hive->total_foragers += new_bees_from_outside;
    }
    else
    {
        printf("Nothing u found nothing...\n");
    }
}

void queen_feeding()
{

}

void feed_recovery()
{

}

void season_management()
{

}

void food_storage()
{

}

void predator()
{

}

void outdoor_hazard()
{

}

void shortest_path() // Algo de Dijkra
{

}

void bee_to_queen_transformation()
{

}

void hive_capacity()
{

}

void temperature_management()
{

}

void action_between_recipient_bultine_bees()
{

}

void timer_counter()
{

}

void random_parameter()
{

}

void field_with_flowers()
{
	
}

void bear_attack()
{

}