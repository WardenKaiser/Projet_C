#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "projet.h"

// OHHHHH Guy Yome bon j'ai essayé de mettre un peu d'ordre dans ce programme j'ai changé d'endroit certaines parties pour que tout le code fonctionne
// Par contre c'est trop chelou ça m'a encore tout supprimé une partie de mon programme je sais pas pourquoi ça me fait ça... 
// Avec l'autre sauvegarde qu'on a sur le discord j'ai pu récupérer les parties perdues mais c'est très frustrant 
// Dans le doute avant de dormir je t'enverrais une copie du programme pour éviter ce genre de douille
// Et j'ai trouvé un site qui expliquait les erreurs chelous en gros ça veut dire que potentiellement il peut y avoir des erreurs c'est juste à titre
// Indicatif

Node* createNode(const char* data) 
{
	struct Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, data);
	newNode->on_off = true;
	newNode->left = NULL;
	newNode->right = NULL;
    
	return newNode;
}

Node* generateWorld() 
{
	srand(time(NULL));

	struct Node* root = createNode("Monde");

	if (rand() % 2 == 0) 
	{
		root->left = createNode("Froid");
		root->right = createNode("Chaud");
	} 

	else
	{
		root->left = createNode("Chaud");
		root->right = createNode("Froid");
	}

	if (strcmp(root->right->data, "Chaud") == 0) 
	{
		if (rand() % 2 == 0) 
		{
			strcpy(root->right->left->data, "Printemps");
			strcpy(root->right->right->data, "Été");
		} 

		else 
		{
        	strcpy(root->right->left->data, "Été");
        	strcpy(root->right->right->data, "Printemps");
		}
	}

	if (strcmp(root->left->data, "Froid") == 0) 
	{
		if (rand() % 2 == 0) 
		{
			strcpy(root->left->left->data, "Automne");
            strcpy(root->left->right->data, "Hiver");
		} 

		else 
		{
			strcpy(root->left->left->data, "Hiver");
			strcpy(root->left->right->data, "Automne");
		}
    }

	return root;
}

void printPrefix(Node* root) 
{
	if (root != NULL) 
	{
		if (root->on_off) 
		{
			printf("%s ", root->data);
		}

        printPrefix(root->left);
		printPrefix(root->right);
	}
}

void removeSeason(Node* root, const char* season) 
{
	if (root == NULL) 
	{
		return;
	}

	if (root->left != NULL && strcmp(root->left->data, season) == 0) 
	{
		free(root->left);
		root->left = NULL;
	} 

	else if (root->right != NULL && strcmp(root->right->data, season) == 0) 
	{
		free(root->right);
		root->right = NULL;
	}

	removeSeason(root->left, season);
	removeSeason(root->right, season);
}

void bee_life_cycle(struct bee* bee ,int current_day)
{
	if (current_day >= 1 && current_day <= 3)
	{
		bee->Role.larva;
	}

	if (current_day >= 4 && current_day <= 9)
	{
		bee->Role.nanny;
	}

	if (current_day >= 10 && current_day <= 12)
	{
		bee->Role.receiver;
	}
	
	if (current_day >= 13 && current_day <= 18)
	{
		bee->Role.guard;
	}

	if (current_day >= 19 && current_day <= 45)
	{
		bee->Role.forager;
	}

	if (current_day > 45)
	{
		bee->age=45;
        bee->pollen_capacity=0;
        bee->pollen_collected=0;
	}
}

void add_flower(struct FlowerNode** field) 
{
    int x = rand() % 10; 
    int y = rand() % 10;
    int pollen_capacity = rand() % 10 + 1;

    struct FlowerNode* new_flower = (struct FlowerNode*)malloc(sizeof(struct FlowerNode));
    new_flower->x = x;
    new_flower->y = y;
    new_flower->pollen_capacity = pollen_capacity;
    new_flower->next = *field;
    *field = new_flower; // GROS DOUTE SUR CA A VERIFIER
}

void create_field(struct FlowerNode* field, struct Node* season_node) 
{
    int n = rand() % 15 + 1;

    for (int i = 0; i < n; ++i) 
    {
        int x = rand() % 10; 
        int y = rand() % 10;  
        int pollen_capacity = rand() % 10 + 1;

        if (strcmp(season_node->data, "Été") == 0) 
        {
            pollen_capacity += 20;
            n += 10;
        }
        else if (strcmp(season_node->data, "Printemps") == 0) 
        {
            pollen_capacity += 10;
            n += 5;
        }
        else if (strcmp(season_node->data, "Automne") == 0) 
        {
            pollen_capacity += 5;
            n += 3;
        }
        else if (strcmp(season_node->data, "Hiver") == 0) 
        {
            pollen_capacity += 0;
            n += 0;
        }    

		add_flower(&field);
    }
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

void display_bee(struct bee* bee) 
{
	printf("Bee at (%d, %d) with %d pollen.\n", bee->x, bee->y, bee->pollen_collected);
}

void collect_pollen_from_field(struct bee* bee, FlowerNode* field, int hive_x, int hive_y) 
{
	struct FlowerNode* current_flower = field;

	while (current_flower != NULL) 
	{
		int distance = abs(bee->x - current_flower->x) + abs(bee->y - current_flower->y);

        if (distance <= 3) 
        {
            printf("Bee at (%d, %d) collecting %d pollen from flower at (%d, %d).\n",
                   bee->x, bee->y, current_flower->pollen_capacity, current_flower->x, current_flower->y);

            bee->pollen_collected += current_flower->pollen_capacity;
            current_flower->pollen_capacity = 0;
        }
		if (distance <= 3) 
		{
			printf("Bee at (%d, %d) collecting %d pollen from flower at (%d, %d).\n", bee->x, bee->y, current_flower->pollen_capacity, current_flower->x, current_flower->y);
			bee->pollen_collected += current_flower->pollen_capacity;
			current_flower->pollen_capacity = 0; // Marquer la fleur comme ayant été vidée
		}
        current_flower = current_flower->next;
	}

	printf("Bee returning to the hive at (%d, %d) with %d pollen.\n", hive_x, hive_y, bee->pollen_collected);

	bee->x = hive_x;
	bee->y = hive_y;
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
	Bee.pollen_collected=0;
	Bee.pollen_capacity=0;
	Bee.Role.larva;
    
	return Bee;
}

hive create_hive(int food_capmax)
{
	struct hive Hive;
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

void adding_bees_from_outside_the_hive(struct hive* hive, struct Node* season_node)
{
	srand(time(NULL));

	int chance = rand() % 100;
	int chanceToAddBees = 30;

	if (strcmp(season_node->data, "Été") == 0) 
	{
		chanceToAddBees += 15;
	}

	else if (strcmp(season_node->data, "Printemps") == 0) 
	{
		chanceToAddBees += 10;
	}

	else if (strcmp(season_node->data, "Hiver") == 0) 
	{
		chanceToAddBees = 0;
		printf("Pas d'abeille supplémentaire les abeilles ibernent l'hiver\n");
	}

	else if (strcmp(season_node->data, "Automne") == 0) 
	{
		chanceToAddBees += 5;
	}

	if (chance < chanceToAddBees)
	{
		int new_bees_from_outside;
		new_bees_from_outside = rand() % 30 + 1;

		printf("Lucky you! You found %d new bees!\n", new_bees_from_outside);
		hive->total_foragers += new_bees_from_outside;
    }

	else
	{
		printf("Nothing, you found nothing...\n");
	}
}



void queen_feeding(struct hive* hive)
{
    int queen_consuption = 2;

    if (hive->royalJelly_lvl>= queen_consuption)
    {
        hive->royalJelly_lvl -= queen_consuption;
    }
    else
    {
        printf("not enough royalJelly to feed the queen.\n");
    }
}

void convert_royalJelly(struct hive* hive)
{
    int total_food = hive->food_lvl;
    int amount_royalJelly = total_food * 0.2;
    hive->food_lvl -= amount_royalJelly;
    hive->royalJelly_lvl += amount_royalJelly;
}


void food_recovery(struct bee* bee,struct hive* hive ,int hive_x, int hive_y)
{
    bee->x = hive_x;
    bee->y = hive_y;
    hive->food_lvl += bee->pollen_collected;
    bee->pollen_collected = 0;
}

struct hiveNode_hive2* create_hive2(int bees_hive2)
{
    struct hiveNode_hive2* node_2 = malloc(sizeof(hiveNode_hive2));
    node_2->bees_hive2 = bees_hive2;
    node_2->left = node_2->right = NULL;
    
    return node_2;
}

int totalBees2(hiveNode_hive2* root) 
{
	if (root == NULL)
	{
		return 0;
    }

	return root->bees_hive2 + totalBees2(root->left) + totalBees2(root->right);
}

/*void food_storage()
{

}*/

void outdoor_hazard()
{

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