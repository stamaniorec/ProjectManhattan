#ifndef CARD_H
#define CARD_H

typedef struct {
	char *name;
	int life;
	int force;
	int cost;
} card_t;

int attack(card_t *attacker, card_t *defender);
void print_winner(card_t attacker, card_t defender);
void print_card(card_t card);
void init_card(card_t *card, char *name, int life, int force, int mana_cost);

#endif
