/* Program name: Dominion Unit Test 3
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
 * Description: This tests the endTurn function in dominion.c
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

	int seed = 555;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall};
	
	printf("TESTING endTurn():\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	// Check starting hand for player 1
	printf("Player 1: Starting hand size before endTurn: %d, expected: %d - ", testG.handCount[0], 5);
	if(testG.handCount[0] == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check starting hand for player 2
	printf("Player 2: Starting hand size before endTurn: %d, expected: %d - ", testG.handCount[1], 5);
	if(testG.handCount[1] == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check whose turn it is before endTurn
	printf("Who's turn is it before endTurn: %d, expected: %d - ", testG.whoseTurn, 0);
	if(testG.whoseTurn == 0)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}

	//End players turn
	endTurn(&testG);

	// Check whose turn it is after ending turn
	printf("Who's turn is it after endTurn: %d, expected: %d - ", testG.whoseTurn, 1);
	if(testG.whoseTurn == 1)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check hand size for player 2
	printf("Player 2: Hand size after endTurn: %d, expected: %d - ", testG.handCount[1], 5);
	if(testG.handCount[1] == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Check hand size for player 1
	printf("Player 1: Hand size after endTurn: %d, expected: %d - ", testG.handCount[0], 0);
	if(testG.handCount[0] == 0)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}


	return 0;
}
