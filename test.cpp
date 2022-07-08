/* File: Cardtrick.cpp
 * Programmer:
 * Date:
 * Course: COP 2931
 *
 * Purpose:
 * Write a program that performs a cardtrick. The program will create a
 * random deck of cards, deal them out, pick them up, and determine the
 * secret card.
 *
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void BuildDeck( int deck[], const int size);

int main(void)
{

/* declare and initialize variables */
	int column = 0, i = 0;
	char name[10] = {};
	char answer;

/* Declare a 52 element array of integers to be used as the deck of cards */
	int deck[52] = {0};

/* Declare a 7 by 3 array to receive the cards dealt to play the trick */
	int play[7][3] = {0};



/* Generate a random seed for the random number generator. */
	srand(time(0));



/* Openning message.  Ask the player for his/her name */
	cout << "Hello, I am a really tricky computer program and " << endl
	     << "I can even perform a card trick.  Here's how." << endl
	     << "To begin the card trick type in your name: " << endl
	     << " --> ";
	cin >> name;

/* Capitalize the first letter of the person's name. */
	name[0] -= 32;
	cout << name << endl;


	cout << endl << "Thank you " << name << endl;

    /* Build the deck */
	BuildDeck(deck, size);


    /* Ask if the player wants to see the entire deck. If so, print it out. */
	cout << "Ok " <<  name <<", first things first.  Do you want to see what " << endl
	     << "the deck of cards looks like (y/n)? ";
	cin >> answer;

	if (answer == 'y')
		for (i = 0; deck[i]; i++)
			cout << deck[i] << " " << endl;


	cout << endl << name << " pick a card and remember it..." << endl;
	return 1;

}

void BuildDeck( int deck[], const int size)
{
  int used[52] = {0};
  int card = 0, i = 0;

  /* Generate cards until the deck is full of integers */
  while(i < size)
    {
		/* generate a random number between 0 and 51 */
	    card = rand() % 52;


		/* Check the used array at the position of the card.
		   If 0, add the card and set the used location to 1.  If 1, generate another number */
		if(used[card] == 0)
		{
			deck[card] = card;
			used[card] = 1;
		}
    }
	return;
}
