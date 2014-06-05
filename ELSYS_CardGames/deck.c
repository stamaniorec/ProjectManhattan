#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "board.h"

void init_deck(struct deck_t *player_deck)
{
	player_deck->top = -1;
}

// this function is never used, but it exists for the completeness of the stack
int push_card(card_t card_to_push, struct deck_t *player_deck)
{
	player_deck->array[++player_deck->top] = card_to_push;
}

card_t draw_card(struct deck_t *player_deck)
{
	card_t temp = player_deck->array[player_deck->top];
	
	// "deletes" the card on top of the deck
	player_deck->array[player_deck->top].name[0] = '\0';
	player_deck->array[player_deck->top].life = 0;
	player_deck->array[player_deck->top].force = 0;
	player_deck->array[player_deck->top].cost = 0;
	--player_deck->top;

	return temp;
}

// this also isn't used in the game because it makes no sense
// again, it exists for the completeness of the stack
int look_card(struct deck_t player_deck)
{
	printf("name: %s\n", player_deck.array[player_deck.top].name);
	printf("life: %d\n", player_deck.array[player_deck.top].life);
	printf("force: %d\n", player_deck.array[player_deck.top].force);
	printf("mana cost: %d\n", player_deck.array[player_deck.top].cost);
}

// not used either; could be used for debugging
void print_deck(struct deck_t deck)
{
	int i;
	printf("top = %d\n", deck.top); // for debugging purposes
	for(i = 0; i <= deck.top; i++)
	{
		print_card(deck.array[i]);
	}
}

int to_integer(const char* source)
{
	int result = 0, i, tens = 1;
	for(i = strlen(source) - 1; i >= 0; --i)
	{
		result += (source[i] - '0')*tens;
		tens *= 10;
	}
	return result;
}

void load_deck(struct deck_t* deck, const char* deck_name)
{
	FILE* deck_file = fopen(deck_name, "r");
	
	if(!deck_file)
	{
		printf("Error opening file %s\n", deck_name);
		return;
	}
	
	char cur_entry[255];
	char* token;
	char cur_value[255];
	int i = 0;
	int cur_column, value;
	char *card_name;
	int card_life, card_force, card_cost;
	while(fgets(cur_entry, 255, deck_file))
	{
		card_t cur_card;
		token = strtok(cur_entry, ","); 
		cur_column = 0;
		while(token)
		{
			sscanf(token, "%s", cur_value); // reads from string

			switch(cur_column)
			{
				case 0:
					memcpy(cur_card.name, cur_value, strlen(cur_value) + 1);
					break;
				case 1: 
					value = to_integer(cur_value);
					cur_card.life = value;
					break;
				case 2: 
					value = to_integer(cur_value);
					cur_card.force = value;
					break;
				case 3: 
					value = to_integer(cur_value);
					cur_card.cost = value;
					break;
			}
			cur_column++;
			token = strtok(NULL, ",");
		}
		push_card(cur_card, deck);
	}

	fclose(deck_file);
}