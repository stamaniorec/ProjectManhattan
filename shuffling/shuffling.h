#ifndef SHUFFLING_H
#define SHUFFLING_H

#include "deck.h"

int shuffleChoice(struct deck_t *deck);
int RandomShuffling(struct deck_t *deck);
int manaOrder(struct deck_t *deck);
int lifeOrder(struct deck_t *deck);
int attackOrder(struct deck_t *deck);
int costattackOrder(struct deck_t *deck);
int file_saving(struct deck_t *deck);

#endif
