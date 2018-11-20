/* Program name: Dominion Unit Test 2
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
 * Description: This tests the supplyCount function in dominion.c
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
	int handpos = 0;
	int seed = 555;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall};
	
	printf("TESTING supplyCount():\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	// First test - Does specifying a card get the correct supply count
	printf("supplyCount with a card in the game: %d, expected: %d - ", supplyCount(smithy, &testG), testG.supplyCount[smithy]);
	if(supplyCount(smithy, &testG) == testG.supplyCount[smithy])
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
		
	// Play smithy 3 times	
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	choice1 = 2;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	choice1 = 3;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);


	printf("supplyCount after playing the card 3 times in game: %d, expected: %d - ", supplyCount(smithy, &testG), 7);
	if(supplyCount(smithy, &testG) == 7)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}


	return 0;
}
