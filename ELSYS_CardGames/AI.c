#include "AI.h"
#include <stdio.h>	

// best lane to put the AI's card on
int find_best_position(board_t board)
{
	int found = 0;
	int found_spot = 0;
	int free_spot, i;
	int best_position = 0;
	for(i = 0; i < 5; ++i)
	{
		// if there's an empty space
		if(is_card_empty(board.lanes[P_TWO][i]) && !found_spot)		
		{
			free_spot = i; // just in case 
			found_spot = 1; // only run this block once
		}

		// find the player's card with the greatest force
		if(!is_card_empty(board.lanes[P_ONE][i]))
		{
			if(board.lanes[P_ONE][i].force > board.lanes[P_ONE][best_position].force)
			{
				// if there's an empty spot
				if(is_card_empty(board.lanes[P_TWO][i]))
				{
					found = 1; // found some card
					best_position = i;
				}
			}
		}
	}
	if(!found) 
	{
		best_position = free_spot;
	}
	return best_position;
}

// index of best card in hand
int find_best_card_index(board_t board)
{
	int i, best_card_index = 0;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i)
	{
		// for every non empty card
		// find the card with the least cost
		if(!is_card_empty(board.p[P_TWO].hand[i])){
			if(board.p[P_TWO].hand[i].cost <= board.p[P_TWO].hand[best_card_index].cost)
			{
				// and greatest force
				if(board.p[P_TWO].hand[i].force >= board.p[P_TWO].hand[best_card_index].force)
				{
					best_card_index = i;
				}
			}
		}
	}
	return best_card_index;
}

// play turn
void enemy_AI(board_t *board)
{
	int best_position = find_best_position(*board);
	int best_card_index = find_best_card_index(*board); // index including the empty cards; 
					//that's why I don't call get_card_from_hand down below	
	print_card(board->p[P_TWO].hand[best_card_index]);
	play_card(board, P_TWO, board->p[P_TWO].hand[best_card_index], best_position);
}
