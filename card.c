#include"card.h"
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
