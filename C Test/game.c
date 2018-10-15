#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level();
int randomNumber(int min, int max);
int restart(int new_game);

int main(int argc, char *argv[])
{
	int choose_level, hiddenNumber, restart_game;
	int new_game = 1;
	int random = 0;
	int pts = 0;
	int min = 0;
	int max = 0;
	
	do {
		printf("Veuillez choisir votre niveau de difficulte :\n");
		printf("\t1: Entre 1 et 100\n");
		printf("\t2: Entre 1 et 1000\n");
		printf("\t3: Entre 1 et 10000\n");
	
		choose_level = level();
	
		if (choose_level == 1)
		{
			min = 1;
			max = 100;
		} else if (choose_level == 2) {
			min = 1;
			max = 1000;
		} else if (choose_level == 3) {
			min = 1;
			max = 10000;
		}
	
		random = randomNumber(min, max);
	
		do {	
			printf("Quel est le nombre a deviner ?\n");
			scanf("%d", &hiddenNumber);
		
			if (hiddenNumber < random)
			{
				printf("Plus !\n");
				pts++;
			} else if (hiddenNumber > random) {
				printf("Moins !\n");
				pts++;
			} else {
				printf("Bien joue, vous avez trouve le nombre mystere en %d coups!\n", pts+1);
			}
		} while (hiddenNumber != random);
		
		printf("Refaire une nouvelle partie ?\n");
		restart_game = restart(new_game);
		
	} while (restart_game == 1);
	
	return 0;
}

int level() 
{
	int level_number;
	
	scanf("%d", &level_number);
	
	if (level_number == 1)
		return 1;
	else if (level_number == 2)
		return 2;
	else if (level_number == 3)
		return 3;
}

int randomNumber(int min, int max)
{
	int number = 0;
	
	srand(time(NULL));
	number = (rand() % (max - min + 1)) + min;
	
	return number;
}

int restart(int new_game)
{
	scanf("%d", &new_game);
	
	if (new_game == 0)
		return 0;
	else
		return 1;
}