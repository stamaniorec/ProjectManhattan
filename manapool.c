#include <stdio.h>
#include "manapool.h"

void mana_init(manapool_t *pool){
	pool->max_mana=1;
	pool->current_mana=1;
}
int can_put_card(card_t card_to_put, manapool_t pool){
	if(card_to_put.cost>pool.current_mana){
		return 0;
	}else{
		return 1;
	}
}
void put_card(card_t card_to_put, manapool_t *pool, struct deck_t *player_deck){
	switch(can_put_card(card_to_put, *pool)){
		case 0:printf("You don't have enough mana to put this card\n");
			break;
		case 1:{pool->current_mana-=card_to_put.cost;
			push_card(card_to_put, player_deck);
			break;
		}
	}
}
void print_mana(manapool_t pool){
	printf("%d/%d\n", pool.current_mana, pool.max_mana);
}
