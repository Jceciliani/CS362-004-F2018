/* Program name: Dominion Card Random Test 2
 * Author: Josh Ceciliani
 * Date: November 12, 2018
 * Description: This tests the Village card function in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>

int main()
{
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int numPlayers;
	int randomSeed;
	int handPos = 5;
	int handPosition = 0;	
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall};

	printf("TESTING Village Card:\n");

	randomSeed = rand() % 256 + 1;
	numPlayers = rand() % 4 + 2;
	// Initilize game
	initializeGame(numPlayers, k, randomSeed, &G); 
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	

	int i, j, cards, act;	
	for(i = 0; i < numPlayers; i++)
	{
		printf("Current Player: %d\n", i);		
		cards = 5;
		act = 1;
		for(j = 0; j < handPos; j++)
		{
			printf("Number of cards in hand before playing village: %d, expected: %d, iteration#: %d - ", numHandCards(&testG), cards, j);	
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Number of actions before playing village: %d, expected: %d, iteration#: %d - ", testG.numActions, act, j);
			if(testG.numActions == act)
			{
				printf("PASSED\n");
			}	
			else
			{
				printf("FAILED\n");
			}
			cardEffect(village, choice1, choice2, choice3, &testG, handPosition, &bonus);		
			handPosition++;
			act += 2;
	
			printf("Number of cards in hand after playing village: %d, expected: %d, iteration#: %d - ", numHandCards(&testG), cards, j);
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Number of actions after playing village: %d, expected: %d, iteration#: %d - ", testG.numActions, act, j);
			if(testG.numActions == act)
			{
				printf("PASSED\n\n");
			}
			else
			{
				printf("FAILED\n\n");
			}
		}
		// End current players turn
		endTurn(&testG);
	}

	return 0;
}		

