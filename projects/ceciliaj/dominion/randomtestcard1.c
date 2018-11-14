/* Program name: Dominion Card Random Test 1
 * Author: Josh Ceciliani
 * Date: November 12, 2018
 * Description: This tests the Smithy card function in dominion.c
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
	// Randomize the randomness
	srand(time(NULL));

	printf("TESTING Smithy Card:\n");

	randomSeed = rand() % 256 + 1;
	numPlayers = rand() % 4 + 2;
	// Initilize game
	initializeGame(numPlayers, k, randomSeed, &G); 
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	

	int i, j, cards;
	for(i = 0; i < numPlayers; i++)
	{
		printf("Current Player: %d\n", i);		
		cards = 5;	
		for(j = 0; j < handPos; j++)
		{
			printf("Number of cards in hand before playing smithy: %d, expected: %d, iteration#: %d - ", numHandCards(&testG), cards, j);	
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}	
			cardEffect(smithy, choice1, choice2, choice3, &testG, handPosition, &bonus);		
			handPosition++;
			cards += 2;
			printf("Number of cards in hand after playing smithy: %d, expected: %d,  iteration#: %d - ", numHandCards(&testG), cards, j);
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n\n");
			}
			else
			{
				printf("FAILED\n\n");
			}
		}	
		// End that players turn	
		endTurn(&testG);
	}

	return 0;
}
	
