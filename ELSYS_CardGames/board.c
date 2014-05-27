#include <stdio.h>
#include <math.h>
#include <string.h>
#include "game_util.h"

void board_init(board_t *board){
	init_player(&board->p[P_ONE]);
	init_player(&board->p[P_TWO]);	
	int i;

	// null the board
	for(i=0; i<5; i++){
		board->lanes[P_ONE][i].name[0] = '\0';
		board->lanes[P_ONE][i].life = 0;
		board->lanes[P_ONE][i].force = 0;
		board->lanes[P_ONE][i].cost = 0;
	}
	for(i=0; i<5; i++){
		board->lanes[P_TWO][i].name[0] = '\0';
		board->lanes[P_TWO][i].life = 0;
		board->lanes[P_TWO][i].force = 0;
		board->lanes[P_TWO][i].cost = 0;
	}	
}

// put card on lane
void play_card(board_t *board, int turn, card_t card_to_put, int num_lane){	
	if(can_put_card(card_to_put, board->p[turn].manapool)) // checks for mana
	{
		memcpy(board->lanes[turn][num_lane].name, card_to_put.name, strlen(card_to_put.name) + 1);
		board->lanes[turn][num_lane].life = card_to_put.life;
		board->lanes[turn][num_lane].force = card_to_put.force;
		board->lanes[turn][num_lane].cost = card_to_put.cost;		
		delete_card_from_hand(&(board->p[turn]), card_to_put.name);
		board->p[turn].manapool.current_mana -= card_to_put.cost;
	}
}

// needs to be worked on!
void print_field(board_t board){
	int i;
	printf("Player: Player, Health: %d/100, Mana: %d/%d\n", 
		board.p[P_ONE].health, board.p[P_ONE].manapool.current_mana, board.p[P_ONE].manapool.max_mana);
	printf("|");
	for(i=0;i<5;i++){
		if(!is_card_empty(board.lanes[P_ONE][i])){
			printf(" %d|%d |",board.lanes[P_ONE][i].life,board.lanes[P_ONE][i].force);		
		}else {
			printf("       |");
		}
	}
	printf("\n|");
	for(i=0;i<5;i++){
		if(!is_card_empty(board.lanes[P_TWO][i])){
			printf(" %d|%d |",board.lanes[P_TWO][i].life,board.lanes[P_TWO][i].force);		
		}else {
			printf("       |");
		}
	}
	printf("\nPlayer: Enemy, Health: %d/100, Mana: %d/%d\n", 
		board.p[P_TWO].health,board.p[P_TWO].manapool.current_mana,board.p[P_TWO].manapool.max_mana);
}

int turn(board_t *board){
	int attack_lane, put_lane, put_num, i, check_card;
	switch(turn_options()){
		case 1:
			i = 0; 
			check_card=0;
			while(i < NUM_OF_CARDS_IN_HAND){
				++i;
				if((board->p[P_ONE].hand[i].name[0]!='\0')&&(board->p[P_ONE].hand[i].force!=0)&&
				(board->p[P_ONE].hand[i].life!=0)&&(board->p[P_ONE].hand[i].cost!=0)&&
				(board->p[P_ONE].hand[i].cost <= board->p[P_ONE].manapool.current_mana)){
					check_card=1;
					break;
				}	
			}
			if(check_card==0){
				printf("Not enough mana\n");
				break;
			}
			printf("Choose a lane\n");
			while(1)
			{
				put_lane = validate_input(1, 5);
				// if the lane is not taken
				if(is_card_empty(board->lanes[P_ONE][put_lane-1]))
				{
					break;
				}
				printf("This line is taken.\n");
			}
			
			--put_lane; // the counting is 1-based
			while(1)
			{
				print_hand(board->p[P_ONE]);
				printf("Choose number of corresponding card\n");
				put_num = validate_input(1, num_of_cards_in_hand(board->p[P_ONE]));
				--put_num;  // the actual game uses 0-based counting
				// mostly needed for when this function is used for the AI
				if(can_play_card(board, P_ONE, get_card_from_hand(&board->p[P_ONE], put_num), put_lane)){
					break;
				}
				sleep(2);
			}
			
			play_card(board, P_ONE, get_card_from_hand(&board->p[P_ONE], put_num), put_lane);
			break;
		case 2:
			// yep, empty case; SUE ME mwahahaha 
			break;	
		case 3: 
			return 1;
	}
	return 0;
}

void turn_attacks(board_t *board)
{
	int i, has_defender_survived;
	for(i = 0; i < 5; ++i)
	{
		has_defender_survived = 0;
		// if there is a card at lane i (player)
		if(!is_card_empty(board->lanes[P_ONE][i]))
		{
			// if there is a card at lane i (AI) FIGHT
			if(!is_card_empty(board->lanes[P_TWO][i]))
			{
				switch(attack(&board->lanes[P_ONE][i], &board->lanes[P_TWO][i]))
				{
					case 0: 
						board->p[P_ONE].health -= abs(board->lanes[P_ONE][i].life);
						board->p[P_TWO].health -= abs(board->lanes[P_TWO][i].life);
						kill_card(&board->lanes[P_ONE][i]);
						kill_card(&board->lanes[P_TWO][i]);
						break;
					case 1: 
						board->p[P_TWO].health -= abs(board->lanes[P_TWO][i].life); 
							// the cards are passed by reference to the attack function
							// because of that the life of the defeated card is equal to the difference between
							// the force of the attacker and the life of the defender
							// but it's negative so we use abs 
						kill_card(&board->lanes[P_TWO][i]);
						break;
					case 2:
						board->p[P_ONE].health -= abs(board->lanes[P_ONE][i].life); 
						kill_card(&board->lanes[P_ONE][i]);
						has_defender_survived = 1; // the attacker will be nulled and the if below will 
							// cause an additional damage to be dealt on the player
						break;
				}
			}
			// if there is no card at lane i (AI) attack AI's health points
			else
			{
				board->p[P_TWO].health -= board->lanes[P_ONE][i].force;
			}
		}
		// only checks for empty lanes because the battles have already been taken of
		if(!is_card_empty(board->lanes[P_TWO][i]))
		{
			if(is_card_empty(board->lanes[P_ONE][i]) && !has_defender_survived)
			{
				board->p[P_ONE].health -= board->lanes[P_TWO][i].force;
			}
		}
	}
}
