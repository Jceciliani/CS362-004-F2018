/* Program name: Dominion Card Random Test 3
 * Author: Josh Ceciliani
 * Date: November 12, 2018
 * Description: This tests the Adventurer card function in dominion.c
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

	printf("TESTING Adventurer Card:\n");

	randomSeed = rand() % 256 + 1;
	numPlayers = rand() % 4 + 2;
	// Initilize game
	initializeGame(numPlayers, k, randomSeed, &G); 
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	

	int i, j, cards, Coins, deckC;
	for(i = 0; i < numPlayers; i++)
	{
		printf("Current Player: %d\n", i);		
		cards = 5;
		Coins = 4;	
		deckC = 10;
		for(j = 0; j < handPos; j++)
		{
			printf("Number of cards in hand before playing adventurer: %d, expected: %d, iteration#: %d - ", numHandCards(&testG), cards, j);	
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Number of coins before playing adventurer: %d, expected: %d, iteration#: %d - ", testG.coins, Coins, j);
			if(testG.coins == Coins)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Deck count before playing adventurer: %d, expected: %d, iteration#: %d - ", testG.deckCount[i], deckC, j);
			if(testG.deckCount[i] == deckC)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handPosition, &bonus);		
			handPosition++;
			cards++;
			Coins += 2;
			deckC--;	

			printf("Number of cards in hand after playing adventurer: %d, expected: %d, iteration#: %d - ", numHandCards(&testG), cards, j);	
			if(numHandCards(&testG) == cards)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Number of coins after playing adventurer: %d, expected: %d, iteration#: %d - ", testG.coins, Coins, j);
			if(testG.coins == Coins)
			{
				printf("PASSED\n");
			}
			else
			{
				printf("FAILED\n");
			}
			printf("Deck count after playing adventurer: %d, expected: %d, iteration#: %d - ", testG.deckCount[i], deckC, j);
			if(testG.deckCount[i] == deckC)
			{
				printf("PASSED\n\n");
			}
			else
			{
				printf("FAILED\n\n");
			}
	
		}	
		// Current player ends turn
		endTurn(&testG);
	}


	return 0;

}

