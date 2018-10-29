/* Program name: Dominion Card Unit Test 3
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
 * Description: This tests the Great Hall card function in dominion.c
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
	
	printf("TESTING Great Hall Card:\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	// Check initial hand size
	printf("Player 1: Number of cards in hand before Great Hall: %d, expected: %d - ", numHandCards(&testG), 5);
	
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");	
	}
	// Check initial action actions
	printf("Player 1: Number of actions before Great Hall: %d, expected: %d - ", testG.numActions, 1);
	if(testG.numActions == 1)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	choice1 = 1;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Check hand size after Village
	printf("Player 1: Number of cards in have after Great Hall: %d, expected: %d - ", numHandCards(&testG), 5);
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}
	// Check number of actions after Village
	printf("Player 1: Number of actions after Great Hall: %d, expected: %d - ", testG.numActions, 2);
	if(testG.numActions == 2)
	{
		printf("PASSED\n");
	}
	else 
	{
		printf("FAILED\n");
	}
	

	return 0;
}
	
