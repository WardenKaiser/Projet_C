#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include<ncurses.h>

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
	int royalJelly_lvl;
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
	char data[20];
	bool on_off;
} Node;

typedef struct hiveNode_hive2
{
	int bees_hive2;
	struct hiveNode_hive2* left;
	struct hiveNode_hive2* right;
} hiveNode_hive2;

void bee_life_cycle(struct bee* bee ,int current_day,struct hive* hive);
void warming_up_the_hive(struct hive *hive, int temperature, int current_day);
Node* creerNode(bee bee);
bee create_bee(int identifiant);
hive create_hive(int food_capmax);
int reproduce(hive *hive, int *males, int *females);
void adding_bees_from_outside_the_hive(struct hive* hive, struct Node* season_node);
void add_flower(struct FlowerNode** field);
void display_field(struct FlowerNode* field);
void free_field(struct FlowerNode* field);
void create_field(struct FlowerNode* field, struct Node* season_node);
void display_bee(struct bee* bee);
void collect_pollen_from_field(struct bee* bee, FlowerNode* field, int hive_x, int hive_y);
struct hiveNode_hive2* create_hive2(int bees_hive2);
int totalBees2(hiveNode_hive2* root);
void convert_royalJelly(struct hive* hive);
void food_recovery(struct bee* bee,struct hive* hive ,int hive_x, int hive_y);
void queen_feeding(struct hive* hive);