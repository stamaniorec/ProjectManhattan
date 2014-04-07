#include <stdio.h>
#include "card.h"

int attack(card_t *attacker, card_t *defender){
	defender->life-=attacker->force;
	attacker->life-=defender->force;
	if(defender->life<0 && attacker->life<0){
		return 0;
	}
	if(defender->life<0 && attacker->life>0){
		return 1;
	}
	if(defender->life>0 && attacker->life<0){
		return 2;	
	}
	if(defender->life>0 && attacker->life>0){
		return 3;
	}
}

void print_winner(card_t attacker, card_t defender)
{
	switch(attack(&attacker, &defender))
	{
		case 0:
			printf("Neither %s nor %s survived.\n", attacker.name, defender.name);
			break;
		case 1: 
			printf("The attacker (%s) survived.\n", attacker.name);
			break;
		case 2: 
			printf("The defender (%s) survived.\n", defender.name);
			break;
		case 3: 
			printf("Both %s and %s survived.\n", attacker.name, defender.name);
			break;
	}
}

void print_card(card_t card)
{
	printf("name: %s\n", card.name);
	printf("life: %d\n", card.life);
	printf("force: %d\n", card.force);
	printf("mana cost: %d\n", card.cost);
	printf("\n");
}

void init_card(card_t *card, char *name, int life, int force, int mana_cost)
{
	card->name = name;
	card->life = life;
	card->force = force;
	card->cost = mana_cost;
}