#ifndef BOARD_H
#define BOARD_H

#include "player.h"

enum players { P_ONE, P_TWO };

typedef struct {
	struct player p[2];
	card_t lanes[2][5];
} board_t;

void board_init(board_t *board);
void play_card(board_t *board, int turn, card_t card_to_put, int num_lane); 
int turn(board_t *board);
void print_field(board_t board);
void turn_attacks(board_t *board);

#endif
