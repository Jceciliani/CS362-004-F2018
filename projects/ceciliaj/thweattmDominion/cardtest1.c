/* Program name: Dominion Card Unit Test 1
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
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
	
	printf("TESTING Smithy Card:\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	printf("Player 1: Number of cards in hand before Smithy: %d, expected: %d - ", numHandCards(&testG), 5);
	
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");	
	}

	// Check supplycount for smithy before playing 
	supplyCount(smithy, &testG);
	printf("Supply Count for Smithy before being played: %d, expected: %d - ", supplyCount(smithy, &testG), 10);
	if(supplyCount(smithy, &testG) == 10)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Play smithyCard 		
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Check supplycount after smithy played
	printf("Supply Count for Smithy after being played: %d, expected: %d - ", supplyCount(smithy, &testG), 9);
	if(supplyCount(smithy, &testG) == 9)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}

	printf("Player 1: Number of cards in hand after Smithy: %d, expected: %d - ", numHandCards(&testG), 7);	
	if(numHandCards(&testG) == 7)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}
	// Change to other player
	endTurn(&testG);
	// Player 2 state change?
	printf("Player 2: Number of cards in hand before Smithy: %d, expected: %d - ", numHandCards(&testG), 5);
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Player 2 also plays Smithy - +3 - 1 for discard
	choice1 = 2;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Player 2: Number of cards in hand after Smithy: %d, expected: %d - ", numHandCards(&testG), 7);	
	if(numHandCards(&testG) == 7)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}


	return 0;
}
