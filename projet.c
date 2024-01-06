#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "projet.h"

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
} role;

typedef struct bee
{
	int x;
    int y;
    int pollen_collected;
    int age;
    int identifiant;
    int pollen_capacity;
    char sex;
    role Role;
} bee;

// Structure pour une fleur
typedef struct FlowerNode 
{
    int x;
    int y;
    int pollen_capacity;
    struct FlowerNode* next;
}FlowerNode;

typedef struct hive
{
	bee* Bee;
	int food_cap;
	int food_lvl;
	int total_larva;
	int total_nannies;
	int total_receivers;
	int total_builders;
	int total_guards;
	int total_foragers;
	int total_bees;
	struct Node* root;
}hive;

typedef struct Node 
{
    struct Node* left;
    struct Node* right;
    bee beech;
} Node;


void bee_life_cycle(struct hive* hive ,int current_day)
{
    if (current_day >= 1 && current_day <= 3)
    {
        hive->total_larva += 2000;
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
    if (temperature >= 10 && hive->total_foragers > 0) 
    {
        hive->total_foragers = hive->total_foragers * 5 / 6;
        printf("Foragers nerf\n");
    } 

    else if (temperature < 10 && temperature >= 7 && hive->total_foragers > 0) 
    {
        hive->total_foragers = hive->total_foragers * 4 / 5;
        printf("Foragers nerf\n");
    } 

    else if (temperature < 7 && (hive->total_larva + hive->total_nannies + hive->total_receivers + hive->total_builders + hive->total_guards + hive->total_foragers) > 0) 
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
Node* creerNode(bee bee) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node != NULL) 
    {
        node->left = NULL;
        node->right = NULL;
        node->beech = bee;
    }
    return node;
}
bee create_bee(int identifiant)
{
	bee Bee;
	Bee.identifiant=identifiant;
	Bee.sex=rand()% 100 < 5?'M':'F';
	Bee.age=0;
	Bee.Role.larva;
    
	return Bee;
}
hive create_hive(int food_capmax)
{
	hive Hive;
	Hive.food_cap=food_capmax;
	Hive.food_lvl=0;
	Hive.Bee=NULL;
	Hive.total_bees=0;
	return Hive;
}
int reproduce(hive *hive, int *males, int *females)
{
	int total_children = 0;
	for (int i = 0; i < 10; i++)
	{
		bee child = create_bee(hive->total_bees + total_children + 1);
		child.Role.larva;
		hive->total_bees++;
		total_children++;
		switch (child.sex)
		{
		case 'M':
			*males++;
			break;
		case 'F':
			*females++;
			break;
		}
	}
	return total_children;
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

void food_recovery()
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

void shortest_path() 
{

}

void add_flower(int x, int y, int pollen_capacity) 
{
	FlowerNode* field = NULL;
    FlowerNode* new_flower = (FlowerNode*)malloc(sizeof(FlowerNode));
    new_flower->x = x;
    new_flower->y = y;
    new_flower->pollen_capacity = pollen_capacity;
    new_flower->next = field;
    field = new_flower;
}

void display_field(struct FlowerNode* field) 
{
    struct FlowerNode* element = field;

    while (element != NULL) 
    {
        printf("Flower's capacity is %d. At (%d, %d)\n", element->pollen_capacity, element->x, element->y);
        element = element->next;
    }
}

void free_field(struct FlowerNode* field) 
{
    struct FlowerNode* element = field;
    struct FlowerNode* next;

    while (element != NULL) 
    {
        next = element->next;
        free(element);
        element = next;
    }

    field = NULL;
}

void create_field(struct FlowerNode* field) 
{
    int n = rand() % 15 + 1;  
    for (int i = 0; i < n; ++i) 
    {
        int x = rand() % 10; 
        int y = rand() % 10;  
        int pollen_capacity = rand() % 10 + 1; 
        add_flower(x, y, pollen_capacity);
    }
}

void display_bee(struct bee* bee) 
{
    printf("Bee at (%d, %d) with %d pollen.\n", bee->x, bee->y, bee->pollen_collected);
}

void collect_pollen_from_field(struct bee* bee, FlowerNode* field, int hive_x, int hive_y) 
{
    FlowerNode* current_flower = field;

    while (current_flower != NULL) 
    {
        int distance = abs(bee->x - current_flower->x) + abs(bee->y - current_flower->y);

        if (distance <= 3) 
        {
            printf("Bee at (%d, %d) collecting %d pollen from flower at (%d, %d).\n",
                   bee->x, bee->y, current_flower->pollen_capacity, current_flower->x, current_flower->y);

            bee->pollen_collected += current_flower->pollen_capacity;
            current_flower->pollen_capacity = 0; // Marquer la fleur comme ayant été vidée
        }
        current_flower = current_flower->next;
    }

    printf("Bee returning to the hive at (%d, %d) with %d pollen.\n",
	hive_x, hive_y, bee->pollen_collected);

    bee->x = hive_x;
    bee->y = hive_y;
}


void bee_to_queen_transformation()
{

}

void hive_capacity()
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


void bear_attack()
{

}