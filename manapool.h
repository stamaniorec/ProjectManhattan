#ifndef MANA_H
#define MANA_H

#include "deck.h"

typedef struct{
	int max_mana;
	int current_mana;
} manapool_t;

void mana_init(manapool_t *pool);
int can_put_card( card_t card_to_put, manapool_t pool);
void put_card(card_t card_to_put, manapool_t *pool, struct deck_t *player_deck);
void print_mana(manapool_t);

#endif
