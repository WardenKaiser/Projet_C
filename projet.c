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
}role;

typedef struct bee
{
	int age;
	int role;
	int pollen_capacity;
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

void bee_life_cycle(struct hive *hive, int current_day)
{
    if (current_day >= 1 && current_day <= 3)
    {
        hive->total_larva += 2000;
    }

    if (current_day >= 3 && current_day <= 9)
    {
        hive->total_nannies = hive->total_larva;
        hive->total_larva -= hive->total_nannies;
    }

    if (current_day >= 9 && current_day <= 12)
    {
        hive->total_receivers = hive->total_nannies;
        hive->total_nannies = 0;
    }

    if (current_day >= 12 && current_day <= 18)
    {
        hive->total_builders = hive->total_receivers;
        hive->total_receivers = 0;
    }

    if (current_day >= 15 && current_day <= 22)
    {
        hive->total_guards = hive->total_builders;
        hive->total_builders = 0;
    }

    if (current_day >= 22 && current_day <= 45)
    {
        hive->total_foragers = hive->total_guards;
        hive->total_guards = 0;
    }

    if (current_day > 45)
    {
        hive->total_foragers = 0;
    }
}

void warming_up_the_hive()
{
	
}

void reproduction()
{

}

void adding_bees_from_outside_the_hive()
{

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