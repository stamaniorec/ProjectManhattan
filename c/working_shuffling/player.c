#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// never used in the game
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
		if(!is_card_empty(p.hand[i]))
		{
			print_card(p.hand[i]);
		}
	}
}

// why should this return struct card_t ? 
void delete_card_from_hand(struct player *p, char *card_name)
{
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		// if the names are identical, i.e. if we found the card we're looking for
		// and yes, memcmp returns 0 if the strings are the same 
		if(memcmp(p->hand[i].name, card_name, strlen(card_name)) == 0)
		{
			p->hand[i].name[0] = '\0';
			p->hand[i].life = 0;
			p->hand[i].force = 0;
			p->hand[i].cost = 0;
			//put_card(p->hand[i], &(p->manapool), &(p->deck)); // why is this here?
			break;
		}
	}
}

void turn_begin(struct player *p)
{
	p->manapool.max_mana++;
	p->manapool.current_mana++;
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		// finds a spot to put a drawn card in
		if(is_card_empty(p->hand[i]))
		{
			if(p->deck.top < 0)
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

// index NOT including the empty cards
card_t get_card_from_hand(struct player *p, int index)
{
	int result = -1;
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		if(!is_card_empty(p->hand[i]))
		{
			if(++result == index)
			{
				break;
			}
		}
	}
	return p->hand[i];
}

int is_player_dead(struct player p)
{
	return p.health <= 0;
}

int num_of_cards_in_hand(struct player p)
{
	int i;
	int counter = 0;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		if(!is_card_empty(p.hand[i]))
		{
			++counter;
		}
	}
	return counter;
}