#include <stdio.h>
#include "deck.h"

void init_deck(struct deck_t *player_deck)
{
	player_deck->top = -1;
}

int push_card(card_t card_to_push, struct deck_t *player_deck)
{
	player_deck->array[++player_deck->top] = card_to_push;
}

card_t draw_card(struct deck_t *player_deck)
{
	card_t temp = player_deck->array[player_deck->top];
	
	player_deck->array[player_deck->top].name = "";
	player_deck->array[player_deck->top].life = 0;
	player_deck->array[player_deck->top].force = 0;
	player_deck->array[player_deck->top].cost = 0;
	--player_deck->top;

	return temp;
}

int look_card(struct deck_t player_deck)
{
	printf("name: %s\n", player_deck.array[player_deck.top].name);
	printf("life: %d\n", player_deck.array[player_deck.top].life);
	printf("force: %d\n", player_deck.array[player_deck.top].force);
	printf("mana cost: %d\n", player_deck.array[player_deck.top].cost);
}

void print_deck(struct deck_t deck)
{
	int i;
	for(i = 0; i <= deck.top; i++)
	{
		print_card(deck.array[i]);
	}
}
