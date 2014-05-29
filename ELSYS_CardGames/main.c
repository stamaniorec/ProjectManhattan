#include <stdio.h>
#include <stdlib.h>
#include "AI.h"

int main () {
	srand(time(NULL));	

	board_t *board = NULL;

	int finished = 0;
	char blank[255];
	
	while(!finished)
	{
		write(1,"\E[H\E[2J",7);

		print_menu();
		int option = validate_input(1, 4);

		switch(option)
		{
			case 1: 
				board = (board_t*)malloc(sizeof(board_t));

				init_deck(&board->p[P_ONE].deck);	
				load_deck(&board->p[P_ONE].deck, "player_deck.csv");

				init_deck(&board->p[P_TWO].deck);	
				load_deck(&board->p[P_TWO].deck, "enemy_deck.csv");

				// the board inits the player and the player needs a deck
				board_init(board);	

				if(rand() % 2 == 0)
				{
					printf("The enemy goes first!\n");
					sleep(2);
					write(1,"\E[H\E[2J",7);
					turn_begin(&board->p[P_TWO]);
					print_field(*board);
					sleep(1);
					write(1,"\E[H\E[2J",7);

					enemy_AI(board);
					
					write(1,"\E[H\E[2J",7);
					print_field(*board);
					sleep(1);
					printf("\nEnemy's turn is over!\n");
					//--board.p[P_TWO].manapool.max_mana; // the turn_begin function
					//--board.p[P_TWO].manapool.current_mana; // increments these 
				}
				else
				{
					printf("The player goes first!\n");
					sleep(2);
				}

				write(1,"\E[H\E[2J",7);

				int i;
				while(1)
				{
					turn_begin(&board->p[P_ONE]);
					turn_begin(&board->p[P_TWO]);	

					print_field(*board);
					printf("\nGo, go, go!! :)\n");
					
					if(turn(board))
					{
						break;
					}
					
					write(1,"\E[H\E[2J",7);
					print_field(*board);
					sleep(1);
					printf("\nPlayer's turn is over!\n");
					sleep(2);
					
					enemy_AI(board);
					
					write(1,"\E[H\E[2J",7);
					print_field(*board);
					sleep(1);
					printf("\nEnemy's turn is over!\n");
					sleep(2);
					
					turn_attacks(board);
					printf("End-of-turn attacks!\n");
					
					if(is_player_dead(board->p[P_ONE]))
					{
						printf("Game over! \nThe player is dead!\n");
						break;
					}
					if(is_player_dead(board->p[P_TWO]))
					{
						printf("Game over! \nThe enemy is dead!\n");
						break;
					}
					
					sleep(2);
					write(1,"\E[H\E[2J",7);
				}
				free(board);
				break;
			case 2:
				write(1,"\E[H\E[2J",7);
				read_file("instructions.txt");
				printf("\n\nEnter anything to go back to the main menu.\n");
				scanf("%s", blank); 
				break;
			case 3:
				write(1,"\E[H\E[2J",7); 
				read_file("about.txt");
				printf("\nEnter anything to go back to the main menu.\n");
				scanf("%s", blank);
				break;
			case 4: 
				printf("Thank you for using this software! Please call us to get your free Awesome Person certificate!\n");
				finished = 1;
				break;
		}
	}
	
	return 0;
}
