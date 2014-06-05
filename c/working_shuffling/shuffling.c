#include <stdio.h>
#include "AI.h"
#include <time.h>
#include <string.h>
int choice;
enum{j,NO,YES};
int shuffleChoice(){
	printf("Choose the type of shuffling: \n1: Random\n2: Ordered by mana\n3: Ordered by life\n4: Ordered by force\n5: Ordered by mana and force\n");
	//for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	scanf("%d", &choice);
	return choice;
	/*switch(choice){
		case 1:{
			return RandomShuffling(deck);
			break;
		}
		case 2:{
			return manaOrder(deck);
			break;
		}
		case 3:{
			return lifeOrder(deck);
			break;
		}
		case 4:{
			return attackOrder(deck);
			break;
		}
		case 5:{
			return costattackOrder(deck);
			break;
		}	
	}*/
}
int RandomShuffling(struct deck_t *deck){
	//printf("ds\n");
	//print_deck(*deck);
	int cards_in_deck=0;
	//printf("ds\n");
	//while(!is_card_empty(deck->array[cards_in_deck++]));
	int deck_count = 0;
	while(deck_count>0){
		if(!is_card_empty(deck->array[cards_in_deck])){
			cards_in_deck++;
		}
		deck_count--;
			/*printf("%s,%d,%d,%d\n", 
			deck->array[deck_count].name,
			deck->array[deck_count].cost,
			deck->array[deck_count].force,
			deck->array[deck_count].life);*/	
	}
	//printf("%d\n",cards_in_deck);
	//for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	//srand(time(NULL));
	card_t temp[30];
	deck->top=0;
	int rand_pos;
	while(deck->top++<=cards_in_deck){
		rand_pos=rand()%30;
		//printf("ds\n");
		if(!is_card_empty(deck->array[rand_pos])){
			temp[deck->top].name;
			//printf("ds\n");
			strcpy(deck->array[rand_pos].name,temp[deck->top].name);	
			temp[deck->top].cost = deck->array[rand_pos].cost;
			temp[deck->top].life = deck->array[rand_pos].life;
			//printf("ds\n");
			temp[deck->top].force = deck->array[rand_pos].force;
			kill_card(&(deck->array[rand_pos]));
			deck->top++;
		}
	}
	for(deck->top=0;deck->top<cards_in_deck+1;deck->top++){
		//deck->array[deck->top]=temp[deck->top];
		deck->array[deck->top].cost = temp[deck->top].cost;
		strcpy(temp[deck->top].name,deck->array[deck->top].name);
		deck->array[deck->top].life = temp[deck->top].life;
		deck->array[deck->top].force = temp[deck->top].force;
	}
	printf("Do you want to save shuffled deck in file: 0:NO,1:YES\n");
	scanf("%d",&choice);
	if(choice+1==YES){
		return 1;
	}
	else return 0;
}
int manaOrder(struct deck_t *deck){
	//print_deck(*deck);
	int cards_in_deck;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	int counter_1,counter_2;
	for(counter_1=0;counter_1<cards_in_deck;counter_1++){
		for(counter_2=0;counter_2<=cards_in_deck-1;counter_2++){
			if(deck->array[counter_2].cost<deck->array[counter_2+1].cost){
				//card_t temp = deck->array[counter_2];
				//deck->array[counter_2]				
				char temp_name[40];	
				int temp_cost =	deck->array[counter_2].cost;
				int temp_life = deck->array[counter_2].life;
				int temp_force = deck->array[counter_2].force;
				deck->array[counter_2].cost=deck->array[counter_2+1].cost;
				deck->array[counter_2+1].cost=temp_cost;
				strcpy(temp_name,deck->array[counter_2].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2].name,deck->array[counter_2+1].name);
				//printf("%s\n",deck->array[counter_2+1].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2+1].name,temp_name);
				//printf("%s\n",deck->array[counter_2+1].name);
				deck->array[counter_2].life=deck->array[counter_2+1].life;
				deck->array[counter_2+1].life=temp_life;
				deck->array[counter_2].force=deck->array[counter_2+1].force;
				deck->array[counter_2+1].force=temp_force;
				//print_deck(*deck);
				//printf("\n");
			}
		}
	}
	printf("Do you want to save shuffled deck in file: 0:NO,1:YES\n");
	scanf("%d",&choice);
	if(choice+1==YES){
		return 1;
	}
	else return 0;
}
int lifeOrder(struct deck_t *deck){
	int cards_in_deck;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	int counter_1,counter_2;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	for(counter_1=0;counter_1<cards_in_deck;counter_1++){
		for(counter_2=0;counter_2<cards_in_deck-1;counter_2++){
			if(deck->array[counter_2].life<deck->array[counter_2+1].life){
				//card_t temp = deck->array[counter_2];
				//deck->array[counter_2]				
				char temp_name[40];	
				int temp_cost =	deck->array[counter_2].cost;
				int temp_life = deck->array[counter_2].life;
				int temp_force = deck->array[counter_2].force;
				deck->array[counter_2].cost=deck->array[counter_2+1].cost;
				deck->array[counter_2+1].cost=temp_cost;
				strcpy(temp_name,deck->array[counter_2].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2].name,deck->array[counter_2+1].name);
				//printf("%s\n",deck->array[counter_2+1].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2+1].name,temp_name);
				//printf("%s\n",deck->array[counter_2+1].name);
				deck->array[counter_2].life=deck->array[counter_2+1].life;
				deck->array[counter_2+1].life=temp_life;
				deck->array[counter_2].force=deck->array[counter_2+1].force;
				deck->array[counter_2+1].force=temp_force;
				//print_deck(*deck);
				//printf("\n");
			}
		}
	}
	printf("Do you want to save reordered deck in file: 0:NO,1:YES\n");	
	scanf("%d",&choice);
	if(choice+1==YES){
		return 1;
	}
	else return 0;
}
int attackOrder(struct deck_t *deck){
	int cards_in_deck;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	int counter_1,counter_2;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	for(counter_1=0;counter_1<cards_in_deck;counter_1++){
		for(counter_2=0;counter_2<cards_in_deck-1;counter_2++){
			if(deck->array[counter_2].force<deck->array[counter_2+1].force){
				//card_t temp = deck->array[counter_2];
				//deck->array[counter_2]				
				char temp_name[40];	
				int temp_cost =	deck->array[counter_2].cost;
				int temp_life = deck->array[counter_2].life;
				int temp_force = deck->array[counter_2].force;
				deck->array[counter_2].cost=deck->array[counter_2+1].cost;
				deck->array[counter_2+1].cost=temp_cost;
				strcpy(temp_name,deck->array[counter_2].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2].name,deck->array[counter_2+1].name);
				//printf("%s\n",deck->array[counter_2+1].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2+1].name,temp_name);
				//printf("%s\n",deck->array[counter_2+1].name);
				deck->array[counter_2].life=deck->array[counter_2+1].life;
				deck->array[counter_2+1].life=temp_life;
				deck->array[counter_2].force=deck->array[counter_2+1].force;
				deck->array[counter_2+1].force=temp_force;
				//print_deck(*deck);
				//printf("\n");
			}
		}
	}
	printf("Do you want to save reordered deck in file: 0:NO,1:YES\n");
	scanf("%d",&choice);
	if(choice+1==YES){
		return 1;
	}
	else return 0;
}
int costattackOrder(struct deck_t *deck){
	int cards_in_deck;
	for(cards_in_deck=0;!is_card_empty(deck->array[cards_in_deck]);cards_in_deck++);
	int counter_1,counter_2;
	for(counter_1=0;counter_1<cards_in_deck;counter_1++){
		for(counter_2=0;counter_2<cards_in_deck-1;counter_2++){
			if(deck->array[counter_2].cost<deck->array[counter_2+1].cost){
				//card_t temp = deck->array[counter_2];
				//deck->array[counter_2]				
				char temp_name[40];	
				int temp_cost =	deck->array[counter_2].cost;
				int temp_life = deck->array[counter_2].life;
				int temp_force = deck->array[counter_2].force;
				deck->array[counter_2].cost=deck->array[counter_2+1].cost;
				deck->array[counter_2+1].cost=temp_cost;
				strcpy(temp_name,deck->array[counter_2].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2].name,deck->array[counter_2+1].name);
				//printf("%s\n",deck->array[counter_2+1].name);
				//printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2+1].name,temp_name);
				//printf("%s\n",deck->array[counter_2+1].name);
				deck->array[counter_2].life=deck->array[counter_2+1].life;
				deck->array[counter_2+1].life=temp_life;
				deck->array[counter_2].force=deck->array[counter_2+1].force;
				deck->array[counter_2+1].force=temp_force;
				//print_deck(*deck);
				//printf("\n");
			}
		}
	}	
	for(counter_1=0;counter_1<cards_in_deck;counter_1++){
		for(counter_2=0;counter_2<cards_in_deck-1;counter_2++){
			if(deck->array[counter_2].force<deck->array[counter_2+1].force){
				//card_t temp = deck->array[counter_2];
				//deck->array[counter_2]				
				char temp_name[40];	
				int temp_cost =	deck->array[counter_2].cost;
				int temp_life = deck->array[counter_2].life;
				int temp_force = deck->array[counter_2].force;
				deck->array[counter_2].cost=deck->array[counter_2+1].cost;
				deck->array[counter_2+1].cost=temp_cost;
				strcpy(temp_name,deck->array[counter_2].name);
				printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2].name,deck->array[counter_2+1].name);
				//printf("%s\n",deck->array[counter_2+1].name);
				printf("%s\n",temp_name);
   				strcpy(deck->array[counter_2+1].name,temp_name);
				//printf("%s\n",deck->array[counter_2+1].name);
				deck->array[counter_2].life=deck->array[counter_2+1].life;
				deck->array[counter_2+1].life=temp_life;
				deck->array[counter_2].force=deck->array[counter_2+1].force;
				deck->array[counter_2+1].force=temp_force;
				//print_deck(*deck);
				//printf("\n");
			}
		}
	}	
	printf("Do you want to save reordered deck in file: 0:NO,1:YES\n");
	scanf("%d",&choice);
	if(choice+1==YES){
		return 1;
	}
	else return 0;
}
int file_save(struct deck_t *deck){
	//printf("ds\n");
	FILE *f = NULL;
	f = fopen ("ShuffledDeck.csv","w");
	//printf("ds\n");
	int card_in_deck,counter_1=0;
	//printf("ds\n");
	for(card_in_deck=0;!is_card_empty(deck->array[card_in_deck]);card_in_deck++);
		//printf("ds\n");
		while(counter_1++ < card_in_deck-1){
			//printf("ds\n");
			fprintf(f, "%s,%d,%d,%d\n", 
			deck->array[counter_1].name,
			deck->array[counter_1].cost,
			deck->array[counter_1].force,
			deck->array[counter_1].life);
			/*printf("%s,%d,%d,%d\n", 
			deck->array[counter_1].name,
			deck->array[counter_1].cost,
			deck->array[counter_1].force,
			deck->array[counter_1].life);*/
		}
		//printf("ns\n");
	fclose(f);
	//printf("ns\n");
	return 0;
}


