#ifndef DECK_H
#define DECK_H

#include "card.h"

#define DECK_SIZE 30

struct deck_t
{
	card_t array[DECK_SIZE];
	int top;
};

void init_deck(struct deck_t *player_deck);
int push_card(card_t card_to_push, struct deck_t *player_deck);
card_t draw_card(struct deck_t *player_deck);
int look_card(struct deck_t player_deck);
void print_deck(struct deck_t deck);
void load_deck(struct deck_t* deck, const char* name);
int to_integer(const char* source);

#endif
