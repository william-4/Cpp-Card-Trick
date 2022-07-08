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
void BuildDeck( int deck[], const int size );
void PrintDeck( int deck[], const int size );
void PrintCard( int card );
void Deal( int deck[], int play[][3] );
void PickUp( int deck[], int play[][3], int column );
void SecretCard( int deck[] );

int main(void)
{

/* declare and initialize variables */
	int column = 0, i = 0, c = 0, r = 0;

/* Declare a 52 element array of integers to be used as the deck of cards */
	int deck[52] = {0};

/* Declare a 7 by 3 array to receive the cards dealt to play the trick */
	int play[7][3] = {0};



/* Generate a random seed for the random number generator. */
	srand(time(0));



/* Openning message.  Ask the player for his/her name */
	cout << "Hello, I am a really tricky computer program and " << endl
	     << "I can even perform a card trick.  Here's how." << endl
	     << "To begin the card trick type in your name: "<< endl
	     << -->;
	cin >> name;

/* Capitalize the first letter of the person's name. */
	name[0] -= 32;
	cout << name << endl;


	cout << endl << "Thank you " << name << endl;

	do
	{
    /* Build the deck */
		for (i = 0; i < 52; i++)
			int deck[i] = rand() % 52;


    /* Ask if the player wants to see the entire deck. If so, print it out. */
    cout << "Ok " + name + ", first things first.  Do you want to see what " << endl
		 << "the deck of cards looks like (y/n)? ";





    cout << endl << name << " pick a card and remember it..." << endl;

    /* Begin the card trick loop */
    for(i = 0; i < 3; i++)
    {
	/* Begin the trick by calling the function to deal out the first 21 cards */




	/* Include error checking for entering which column */
        do
	{
		/* Ask the player to pick a card and identify the column where the card is */
		cout << endl <<"Which column is your card in (0, 1, or 2)?: ";
		cin >> column;
	} while(column < 0 || column > 2);

	/* Pick up the cards, by column, with the selected column second */



    }

    /* Display the top ten cards, then reveal the secret card */



    /* if the player wants to play again */
    cout << name << ", would you like to play again (y/n)? ";
    cin >> PlayAgain;
} while(PlayAgain == 'y');

/* Exiting message */
cout << endl << endl << "Thank you for playing the card trick!" << endl;
return;
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

void PrintDeck( int deck[], const int size )
{
	int i;

	/* Print out each card in the deck */




}

void Deal( int deck[], int play[][3] )
{
	int row = 0, col = 0, card = 0;

	/* deal cards by passing addresses of cardvalues from
	   the deck array to the play array                   */
	cout << endl;
	cout << "   Column 0           Column 1           Column 2");
	cout << "======================================================="
		 << endl;




	return;
}

void PrintCard( int card )
{
	int rank = 0;
	int suit = 0;

	// Determine the rank of the card and print it out i.e. Queen
	if (card % 14 == 11)
		cout << "King of ";
	else if (card % 14 == 12)
		cout << "Queen of ";
	else if (card % 14 == 13)
		cout << "Jack of ";
	else if (card % 14 == 0)
		cout << "Ace of ";
	else
	{
		rank = card;
		cout << rank << " of ";
	}



	// Determine the suit of the card and print it out i.e. of Clubs



	return;
}

void PickUp( int deck[], int play[][], int column )
{
	int card = 0, row = 0;








	return;
}

void SecretCard( int deck[] )
{
	int card = 0;

	cout << endl <<"Finding secret card...";
	for(card = 0; card < 10; card++)
	{
		PrintCard(deck[card]);
		cout << endl;
	}

	cout << endl <<"Your secret card is: ";
    PrintCard(deck[card]);
	cout << endl;
	return;
}

}
