/**
 * Purpose: This program implements the 21 cards card trick
 *
 * The program will create a random deck of cards,
 * deal them out, pick them up, and determine the
 * secret card.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

// Function prototypes
void BuildDeck( int deck[], const int size );
void PrintDeck( int deck[], const int size );
void PrintCard( int card );
void Deal( int deck[], int play[][3] );
void PickUp(int deck[], int play[][3], int column);
void SecretCard ( int deck[] );

int main(void)
{
/* declare and initialize variables */
	int column = 0, i = 0;
	string name;
	char answer;
	char playAgain;

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
	     << "--> ";
	cin >> name;

/* Capitalize the first letter of the person's name. */
	name[0] -= 32;
	cout << endl << "Thank you " << name << endl;

	/* do while loop for playing again  */
	do
	{
		/* Build the deck */
		BuildDeck(deck, 52);

		/* Ask if the player wants to see the entire deck. If so, print it out. */
		cout << "Ok " << name << ", first things first.  Do you want to see what " << endl
		     << "the deck of cards looks like (y/n)? ";
		cin >> answer;
		if (answer == 'y')
			PrintDeck(deck, 52);


		cout << endl << name << " pick a card and remember it..." << endl;
		/* Begin the card trick loop */
		for (i = 0; i < 3; i++)
		{
			/* Begin the trick by calling the function to deal out the first 21 cards  */

			Deal(deck, play);

			/* Include error checking for entering which column  */
			do
			{
				/* Ask the player to pick a card and identify the column where the card is  */
				cout << endl << "Which column is your card in (0, 1, or 2)?: ";
				cin >> column;
			} while (column < 0 || column > 2);

			/* Pick up the cards, by column, with the selected column second  */

			PickUp(deck, play, column);
		}

		/* Display the top ten cards, then reveal the secret card */

		SecretCard (deck);

		/* if the player wants to play again  */
		cout << name << ", would you like to play again (y/n)? ";
		cin >> playAgain;
	} while (playAgain == 'y');

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
		if(used[card] == 0)    /* basically checks if we have added the card number to deck */
		{
			/* the next index in deck array is the card number, ensures no numerical order */
			deck[i] = card;
			used[card] = 1;
			/* only increament i if the value is not in used array, if we have added a card to deck array*/
			i++;
		}
	}
	return;

}

/* This function prints out the entire deck of 52 cards  */
void PrintDeck( int deck[], const int size )
{
	int i;

	/* Print out each card in the deck */
	for (i = 0; i < size; i++)
	{
		PrintCard(deck[i]);
		cout << endl;
	}
	cout << "The total number of cards is: " << i << endl;
	return;
}

/* This function determines the correct rank and suit of a card  */
void PrintCard( int card )
{
	int rank = 0;
	int suit = 0;

	// Determine the rank of the card and print it out i.e. Queen

	rank = card % 13;

	suit = card / 13;

	switch (rank)
	{
	case 0:
		cout << setw(10) << "Ace";
		break;
	case 10:
		cout << setw(10) << "Jack";
		break;
	case 11:
		cout << setw(10) << "Queen";
		break;
	case 12:
		cout << setw(10) << "King";
		break;
	default:
		rank += 1;
		cout << setw(10) << rank;
	}

	// Determine the suit of the card and print it out i.e. of Clubs

	switch (suit)
	{
	case 0:
		cout << setw(9) << " of Clubs";
		break;
	case 1:
		cout << setw(9) << " of Hearts";
		break;
	case 2:
		cout << setw(12) << " of Diamonds";
		break;
	case 3:
		cout << setw(10) << " of Spades";
		break;
	}

	return;
}

/* This function prints out the 21 cards in 3 columns each time  */
void Deal( int deck[], int play[][3] )
{
	int row = 0, col = 0, card = 0, i = 0;

/* deal cards by passing addresses of cardvalues from
   the deck array to the play array */
	cout << endl;
	cout << "         Column 0               Column1             Column 2" << endl;
	cout << "===================================================================" << endl;

	for(row = 0; row < 7; row++)
	{
		for( col = 0; col < 3; col++)
		{
			card = deck[i];
			play[row][col] = card;
			i++;
		}
	}

	/* deal out the cards again  */
	for(row = 0; row < 7; row++)
	{
		for( col = 0; col < 3; col++)
		{
			card = play[row][col];
			PrintCard(card);
		}
		cout << endl;
	}
	return;
}

/* This function picks up the cards column by column and instert to deck  */
void PickUp( int deck[], int play[][3], int column )
{
	int card = 0, row = 0;
	int first_column = 0, last_column = 0;

	if (column == 0)
	{
		first_column = 2;
		last_column = 1;
	}
	else if (column == 1)
	{
		first_column = 2;
		last_column = 0;
	}
	else if (column == 2)
	{
		first_column = 0;
		last_column = 1;
	}


	for (row = 0; row < 7; row++)
	{
		deck[card] = play[row][first_column];
		card++;
	}
	for(row = 0; row < 7; row++)
	{
		deck[card] = play[row][column];
		card++;
	}
	for (row = 0; row < 7;row++)
	{
		deck[card] = play[row][last_column];
		card++;

	}
	return;
}

/* Determine the secret card and print it out  */
void SecretCard ( int deck[] )
{
	int card = 0;

	cout << endl <<"Finding secret card..." <<endl;
	for(card = 0; card < 10; card++)
	{
		cout.width(5);
		PrintCard(deck[card]);
		cout << endl;
	}

	cout << endl <<"Your secret card is: ";
	PrintCard(deck[card]);
	cout << endl;
	return;
}
