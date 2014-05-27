#ifndef AI_H
#define AI_H

#include "board.h"

int find_best_position(board_t board);
int find_best_card_index(board_t board);
void enemy_AI(board_t *board);

#endif