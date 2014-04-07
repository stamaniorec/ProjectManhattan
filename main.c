#include <stdio.h>
#include "player.h"

int main () {
	struct player p;

	card_t attacker, attacker2, attacker3;
	card_t defender, defender2, defender3;

	init_card(&attacker, "The Almighty Joe", 10, 12, 1);
	init_card(&defender, "The Weirdo", 6, 3, 1);
	init_card(&attacker2, "Goat poop", 6, 3, 1);
	init_card(&defender2, "Cow poop", 10, 12, 1);
	init_card(&attacker3, "Mexican immigrant", 10, 3, 1);
	init_card(&defender3, "American redneck", 10, 3, 1);

	init_deck(&p.deck);

	push_card(attacker, &p.deck);
	push_card(defender, &p.deck);
	push_card(attacker2, &p.deck);
	push_card(defender2, &p.deck);
	push_card(attacker3, &p.deck);
	push_card(defender3, &p.deck);

	printf("--- PRINTING THE CONTENTS OF THE DECK ---\n");
	print_deck(p.deck);

	printf("--- TESTING TOP AND POP --- \n");
	struct deck_t temp_deck = p.deck;
	look_card(temp_deck);
	printf("\n");
	draw_card(&temp_deck);
	look_card(temp_deck);
	printf("\n");	
	draw_card(&temp_deck);
	look_card(temp_deck);
	printf("\n");
	draw_card(&temp_deck);
	look_card(temp_deck);

	printf("--- TESTING THE MANA SYSTEM --- \n");
	manapool_t temp_mana;
	mana_init(&temp_mana);
	print_mana(temp_mana);
	put_card(attacker, &temp_mana, &temp_deck);
	print_mana(temp_mana);
	put_card(defender, &temp_mana, &temp_deck);	
	print_mana(temp_mana);

	// to init a player there has to be a working deck first
	init_player(&p);

	printf("--- DEMONSTRATING THE BATTLE SYSTEM --- \n");

	printf("Attacker: \n");
	print_card(attacker);
	printf("Defender: \n");
	print_card(defender);

	print_winner(attacker, defender);
	
	printf("--- --- --- --- ---\n");	
	printf("Attacker: \n");
	print_card(attacker2);
	printf("Defender: \n");
	print_card(defender2);

	print_winner(attacker2, defender2);

	printf("--- --- --- --- ---\n");
	printf("Attacker: \n");
	print_card(attacker3);
	printf("Defender: \n");
	print_card(defender3);

	print_winner(attacker3, defender3);

	printf("--- DEMONSTRATING THE CHANGE HEALTH FUNCTION ---\n");
	print_health(p);

	change_health(&p, 30, DECREASE);
	print_health(p);

	change_health(&p, 30, INCREASE);
	print_health(p);

	printf("--- PRINTING THE CONTENTS OF THE HAND ---\n");
	print_hand(p);

	printf("--- PLAYING A CARD FROM THE HAND ---\n");
	play_card_from_hand(&p, "Cow poop");

	printf("--- PRINTING THE CONTENTS OF THE HAND AGAIN ---\n");
	print_hand(p);

	printf("--- DEMONSTRATING THE TURN BEGIN FUNCTION ---\n");
	turn_begin(&p);

	printf("--- PRINTING THE CONTENTS OF THE HAND AGAIN ---\n");
	print_hand(p);

	turn_begin(&p);

	return 0;
}
