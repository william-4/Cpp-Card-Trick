#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void BuildDeck( int deck[], const int size );
void PrintDeck( int deck[], const int size );
void PrintCard( int card );
void Deal( int deck[], int play[][3] );

int main(void)
{
/* declare and initialize variables */
	int column = 0, i = 0;
	char *name;
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
	     << "To begin the card trick type in your name: "<< endl
	     << "--> ";
	cin >> name;

/* Capitalize the first letter of the person's name. */
	name[0] -= 32;
	cout << endl << "Thank you " << name << endl;

	// do
	// {
    /* Build the deck */
	BuildDeck(deck, 52);

    /* Ask if the player wants to see the entire deck. If so, print it out. */
    cout << "Ok " << name << ", first things first.  Do you want to see what " << endl
		 << "the deck of cards looks like (y/n)? ";
    cin >> answer;
    if (answer == 'y')
        PrintDeck(deck, 52);
        
    Deal(deck, play);
        
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
			  /* only increament i if the value is not in used */
			  i++;
		  }
    }
    return;

}
void PrintDeck( int deck[], const int size )
{
	int i;

	/* Print out each card in the deck */
	for (i = 0; i < size; i++)
	{
		PrintCard(deck[i]);
		cout << endl;
	}
		
	return;
}

void PrintCard( int card )
{
	int rank = 0;
	int suit = 0;
	
	char *rankArray[4] = {"King of ", "Queen of ", "Jack of ", "Ace of "};
	char *suitArray[4] = {"Spades", "Diamonds", "Clubs", "Hearts"};

	// Determine the rank of the card after 10 and print it out i.e. Queen
	if (card == 10 || card == 23 || card == 36 || card == 49)
		cout << rankArray[0];
	else if (card == 11 || card == 24 || card == 37 || card == 50)
	    cout << rankArray[1];
	else if (card == 12 || card == 25 || card == 38 || card == 51)
	    cout << rankArray[2];
	else if (card == 0 || card == 13 || card == 26|| card == 39)
	    cout << rankArray[3];

	/* Determine rank of cards from 2 and 10 */
	else
	{
	    if (card < 13)
	        rank = card += 1;
	    else if (card > 12 && card < 26)
	        rank = card % 12;
	    else if (card > 25 && card < 39)
	        rank = card % 25;
	    else if (card > 39 && card < 52)
	        rank = card % 38;
	    
	    cout << rank << " of ";
	}
	
	// Determine the suit of the card and print it out i.e. of Clubs
	if (card < 13)
	    suit = 0;
	else if (card > 12 && card < 26)
	    suit = 1;
	else if (card > 25 && card < 39)
	    suit = 2;
	else if (card > 39 && card < 52)
	    suit = 3;
	    
	cout << suitArray[suit];
	return;
}

void Deal( int deck[], int play[][3] )
{
	int row = 0, col = 0, card = 0;

	/* deal cards by passing addresses of cardvalues from
	   the deck array to the play array                   */
	cout << endl;
	cout << "   Column 0           Column 1           Column 2";
	cout << "======================================================="
	     << endl;
	for (row = 0; row < 7; row++)
	{
	    for (col = 0; col < 3; col++)
	    {
	        play[row][col] = deck[card];
	        card += 2;
	    }
	}
	for (row = 0; row < 7; row++)
	{
	    for (col = 0; col < 3; col++)
	    { 
	        card = play[row][col];
	        cout << setw(5);
	        PrintCard(card);
	    }
	    cout << endl;
	}
	return;
}
