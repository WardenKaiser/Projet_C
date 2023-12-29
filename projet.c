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
}role;

typedef struct bee
{
	int age;
	int role;
	int capacite_pollen;
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

void bee_life_cycle(struct hive* hive ,int days_of_death)
{
	if (days_of_death >= 1 && days_of_death <= 3)
	{
		hive->total_larva =+ 2000;
	}

	if (days_of_death >= 3 && days_of_death <= 9)
	{
		hive->total_nannies = hive->total_larva;
	}

	if (days_of_death >= 9 && days_of_death <= 12)
	{
		hive->total_nannies = hive->total_receivers;
	}

	if (days_of_death >= 12 && days_of_death <= 18)
	{
		hive->total_receivers = hive->total_builders;
	}

	if (days_of_death >= 15 && days_of_death <= 22)
	{
		hive->total_builders = hive->total_guards;
	}

	if (days_of_death >= 22 && days_of_death <= 45)
	{
		hive->total_guards = hive->total_foragers;
	}

	if (days_of_death > 45)
	{
		hive->total_foragers = NULL;
	}

}

void adding_bees_from_outside_the_hive()
{

}

void queen_feeding()
{

}

void reproduction()
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