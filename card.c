#include"card.h"
int main () {
	card_t attacker;
	card_t defender;
	printf("winner:1-attacker,2-defender,3-both/none(both are alive)\n");
	printf("attacker: defender:\nlife:10   life:6\nforce:12  force:3\n");
	attacker.life=10;
	attacker.force=12;
	defender.life=6;
	defender.force=3;
	printf("winner:%d\n",attack(&attacker,&defender));
	printf("attacker: defender:\nlife:6    life:10\nforce:3   force:12\n");
	attacker.life=6;
	attacker.force=3;
	defender.life=10;
	defender.force=12;
	printf("winner:%d\n",attack(&attacker,&defender));
	printf("attacker: defender:\nlife:10   life:10\nforce:3   force:3\n");
	attacker.life=10;
	attacker.force=3;
	defender.life=10;
	defender.force=3;
	printf("winner:%d\n",attack(&attacker,&defender));
	return 0;
}
