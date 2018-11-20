/* Program name: Dominion Unit Test 4
 * Author: Josh Ceciliani
 * Date: Obtober 24, 2018
 * Description: This tests the numHandCards function in dominion.c
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
	
	printf("TESTING numHandCards():\n");

	// Initilize Game
	initializeGame(numPlayers, k, seed, &G);
	// Copy Game to test case
	memcpy(&testG, &G, sizeof(struct gameState));
	// Check number of cards to start
	printf("numHandCards at the start of the game: %d, expected: %d - ", numHandCards(&testG), 5);
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}

	// Play a card and test again
	choice1 = 1;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);


	printf("numHandCards after playing Great Hall: %d, expected: %d - ", numHandCards(&testG), 5);
	if(numHandCards(&testG) == 5)
	{
		printf("PASSED\n");
	}	
	else
	{
		printf("FAILED\n");
	}
	// Play a card and test again
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);


	printf("numHandCards after playing Smithy: %d, expected: %d - ", numHandCards(&testG), 7);
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
