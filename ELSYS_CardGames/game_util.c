#include <stdio.h>
#include "game_util.h"
#include "AI.h"

int validate_input(int lower_bound, int upper_bound)
{
	int num;
	while(1)
	{
		scanf("%d", &num);
		if(num >= lower_bound && num <= upper_bound)
		{
			break;
		}
		printf("Error: Invalid input. Your input must be in the range [%d;%d]\n", lower_bound, upper_bound);
	}
	return num;
}

int turn_options (){
	int turn_act;
	printf ("1: play card, 2: end turn, 3: quit game\n");
	turn_act = validate_input(1, 3);
	return turn_act;
}

int can_play_card(board_t *board, int turn, card_t card_to_put, int num_lane){
	switch(can_put_card(card_to_put, board->p[turn].manapool)){
		case 0:
			printf("You don't have enough mana to put this card.\n");
			return 0;
		case 1:
			if(is_card_empty(board->lanes[turn][num_lane])){
				return 1;
			}else {
				print_card(board->lanes[turn][num_lane]);
				printf("This line is taken.\n");
				return 0;
			}
	}
}

void print_menu()
{
	printf("1. Start game\n");
	printf("2. Instructions\n");
	printf("3. About\n");
	printf("4. Exit\n");
}

void read_file(const char* name)
{
	FILE *file = fopen(name, "r");
	if(!file)
	{
		printf("Error opening instructions file.\n");
		return;
	}
	char cur_line[255];
	while(fgets(cur_line, 255, file))
	{
		printf("%s", cur_line);
	}
	fclose(file);
}