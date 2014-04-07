#ifndef PLAYER_H
#define PLAYER_H value

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
void play_card_from_hand(struct player *p, char *card_name);
void turn_begin(struct player *p);

#endif