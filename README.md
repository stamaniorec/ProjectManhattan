# ProjectManhattan
A command-line card game written in C by Stanimir Bogdanov and Dimitar Terziev, students at the Technological School of Electronic Systems, as a group project for 10th grade programming class.

The game was inspired by "Hearthstone".

No copyright intended.

### Rules:
- In order to play a card, you need to have enough mana. 
- Your manapool is 1 in the beginning of the game.
- It's incremented by one on every turn. 
- At the end of each turn all cards attack all other cards.
- If there are two cards in one corridor, they attack each other. 
- If there is only one card, it attacks the other player's health points. 
- The game finishes when either player's health is brought down to 0.

### How to run:
1. Clone repo
2. Navigate to ```ELSYS_CardGames/```
3. ```rm old_main.c``` - it was left there for school reasons
4. ```gcc *.c```
5. ```./a.out```
6. Play!

If you'd like to have more than 6 cards (duh), edit ```player_deck.csv``` and add more cards.

##### There are two mini-projects included, too:
1. ```card_generator/``` - it generates cards for you, so you don't have to - developed by me, Stanimir Bogdanov

  Run ```gcc card_generator.c -lm``` and then ```./a.out```
  
  Currently it can only generate 25 cards because there are 5 nouns and 5 adjectives available.
  
  If you'd like more, edit ```card_generator.c``` and edit the ```desc``` and ```noun``` arrays by simply adding more adjectives and nouns to generate more combinations.

2. ```c/``` and ```shuffling/``` - developed by Dimitar Terziev

Oh, and the repo is called ProjectManhattan instead of ELSYS_CardGames to make it harder for other people to cheat. We had to use git and host the repos on Github as a project requirement but there was no control on cheating and yeah...
