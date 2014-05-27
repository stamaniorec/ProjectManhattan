#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include "board.h"

int validate_input(int lower_bound, int upper_bound);
int turn_options ();
int can_play_card(board_t *board, int turn, card_t card_to_put, int num_lane);
void print_menu();
void read_file(const char* name);

#endif