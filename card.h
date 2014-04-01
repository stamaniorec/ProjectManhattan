#include<stdio.h>
typedef struct {
	char name [30];
	int life;
	int force;
	int cost;
} card_t;
int attack(card_t *attacker, card_t *defender){
