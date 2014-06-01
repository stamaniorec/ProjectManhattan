#ifndef PLAYER_H
#define PLAYER_H 

#include "manapool.h"

#define NUM_OF_CARDS_IN_HAND 10

enum health_modifier { DECREASE, INCREASE }; 

struct player
{
	struct deck_t deck;
	card_t *hand;
	manapool_t manapool;
	int health;
};

void init_player(struct player *p);
void change_health(struct player *p, int hp, int modifier);
void print_health(struct player p);
void print_hand(struct player p);
void delete_card_from_hand(struct player *p, char *card_name);
void turn_begin(struct player *p);
card_t get_card_from_hand(struct player *p, int index);
int is_player_dead(struct player p);
int num_of_cards_in_hand(struct player p);

#endif
