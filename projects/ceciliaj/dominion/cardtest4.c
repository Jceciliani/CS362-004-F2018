/* Program name: Dominion Card Unit Test 4
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
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

int main()
{
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int numPlayers = 2;
	int handpos = 0;
	int seed = 555;
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall};
	
	printf("TESTING Adventurer Card:\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	// Check starting hand size before adventurer
	printf("Player 1: Number of cards in hand before Adventurer: %d, expected: %d - ", numHandCards(&testG), 5); 
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check starting coins
	printf("Player 1: Number of coins starting the game: %d, expected: %d - ", testG.coins, 4);
	
	if(testG.coins == 4)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");	
	}
	// Deck count before adventurer
	printf("Player 1: Deck count before Adventurer: %d, expected: %d - ", testG.deckCount[0], 10);
	if(testG.deckCount[0] == 10)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Deck count before adventurer for player 2
	printf("Player 2: Deck count before Adventurer: %d, expected %d: - ", testG.deckCount[1], 10);
	if(testG.deckCount[1] == 10)
	{
		printf("PASSED\n");
	}
	else	
	{
		printf("FAILED\n");
	}
	// Play adventurer
	choice1 = 1;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Deck count after adventurer for player 2
	printf("Player 2: Deck counter after Adventurer: %d, expected: %d - ", testG.deckCount[1], 9);
	if(testG.deckCount[1] == 9)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Deck count after adventurer
	printf("Player 1: Deck count after Adventurer: %d, expected: %d - ", testG.deckCount[0], 9);
	if(testG.deckCount[0] == 9)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check coins after playing adventurer
	printf("Player 1: Number of coins after adventurer: %d, expected: %d - ", testG.coins, 6);
	if(testG.coins == 6)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check hand size after adventurer
	printf("Player 1: Number of cards in hand after Adventurer: %d, expected: %d - ", numHandCards(&testG), 4);
	if(numHandCards(&testG) == 4)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}

	return 0;
}
	
	
