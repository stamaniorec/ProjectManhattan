#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void init_player(struct player *p)
{
	p->health = 100; // could change, not sure about the value
	mana_init(&p->manapool);

	p->hand = (card_t*)malloc(NUM_OF_CARDS_IN_HAND * sizeof(card_t)); 

	int i;
	for(i = 0; i < 5; ++i) // the player draws five cards from the deck
	{
		p->hand[i] = draw_card(&p->deck);
	}
}

void change_health(struct player *p, int hp, int modifier)
{
	if(modifier == INCREASE)
	{
		p->health += hp;
	}
	else if(modifier == DECREASE)
	{
		p->health -= hp;
	}
}

void print_health(struct player p)
{
	printf("Player health: %d\n", p.health);
}

void print_hand(struct player p)
{
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		if(p.hand[i].name != NULL && p.hand[i].name != "") // if the card is not "deleted" (played or whatever)
		{
			print_card(p.hand[i]);
		}
	}
}

// why should this return struct card_t ? 
void play_card_from_hand(struct player *p, char *card_name)
{
	// put the card with the name "card_name" on the field
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		if(p->hand[i].name == card_name)
		{
			p->hand[i].name = "";
			p->hand[i].life = 0;
			p->hand[i].force = 0;
			p->hand[i].cost = 0;
			break;
		}
	}
}

void turn_begin(struct player *p)
{
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		if(p->hand[i].name == NULL || p->hand[i].name == "") // finds an empty spot
		{
			if(p->deck.top <= 0)
			{
				printf("There are no more cards in the deck.\n");
			}
			else
			{
				p->hand[i] = draw_card(&p->deck);	
			}
			break;
		}
	}
}