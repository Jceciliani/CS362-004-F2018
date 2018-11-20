/* Program name: Dominion Unit Test 1
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
 * Description: This tests the isGameOver function in dominion.c
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
	
	printf("TESTING isGameOver():\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));	
	// First test - Does having 0 provinces end the game?
	printf("isGameOver before provinces set to zero: %d, expected: %d - ", isGameOver(&testG), 0);
	if(isGameOver(&testG) == 0)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	// Provinces set to 0	
	testG.supplyCount[province] = 0;
	//  Check
	printf("isGameOver after provinces set to zero: %d, expected: %d - ", isGameOver(&testG), 1);
	if(isGameOver(&testG) == 1)
	{
		printf("PASSED\n");	
	}
	else
	{
		printf("FAILED\n");
	}
	// Second test - does having three empty supply piles end the game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("isGameOver before 3 supplyCounts set to zero: %d, expected: %d - ", isGameOver(&testG), 0);
	if(isGameOver(&testG) == 0)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}

	testG.supplyCount[village] = 0;
	testG.supplyCount[remodel] = 0;
	testG.supplyCount[baron] = 0;

	printf("isGameOver after 3 supplyCounts set to zero: %d, expected: %d - ", isGameOver(&testG), 1);
	if(isGameOver(&testG) == 1)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}
	// Third test - does have two empty supply piles end the game
	memcpy(&testG, &G, sizeof(struct gameState)); //  refresh gamestate
	printf("isGameOver before 2 supplyCounts set to zero: %d, expected: %d - ", isGameOver(&testG), 0);
	if(isGameOver(&testG) == 0)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}

	testG.supplyCount[village] = 0;
	testG.supplyCount[remodel] = 0;

	printf("isGameOver after 2 supplyCounts set to zero: %d, expected: %d - ", isGameOver(&testG), 0);
	if(isGameOver(&testG) == 0)
	{
		printf("PASSED\n");
	}
	else
	{
		printf("FAILED\n");
	}
	return 0;
}
