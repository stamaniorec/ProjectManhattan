#include"card.h"
int attack(card_t *attacker, card_t *defender){
	defender->life-=attacker->force;
	attacker->life-=defender->force;
	if(defender->life<0 && attacker->life>0){
		return 1;
	}
	if(defender->life>0 && attacker->life<0){
		return 2;	
	}
	if(defender->life>0 && attacker->life>0){
		return 3;
	}
}
