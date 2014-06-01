#ifndef CARD_H
#define CARD_H

typedef struct {
	char name[255];
	int life;
	int force;
	int cost;
} card_t;

int attack(card_t *attacker, card_t *defender);
void print_winner(card_t attacker, card_t defender);
void print_card(card_t card);
void init_card(card_t *card, char *name, int life, int force, int mana_cost);
void kill_card(card_t *card);
int is_card_empty(card_t card);

#endif
