#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <array>
#include <stack>

using namespace std;
bool DECK [54] = {};
string CONST CARDS [13] = {"1","2","3","4","5","6","7","8","9","10", "JACK", "QUEEN", "KING"};
string CONST SUIT [5] = {"JOKER", "HEARTS", "SPADES", "CLUBS", "DIAMONDS"};

//UP KEY TO DRAW A CARD
//SPACE TO SLAP A CARD

struct card
{
  int number;
  int suit;
};

void typer (string typing)
{
  int x = 0;
  while ( typing[x] != '\0')
  {
  	cout << typing[x];
  	Sleep(50);
  	x++;
  };
}

void randomseed()
{
  srand(time(NULL));
}

int randomnumber(bool deck[])
{
    //Numbers between 0 and 15
    int randomnumber = rand() % 54;

    while(deck[randomnumber])
    {
      cout << randomnumber << endl;
      randomnumber = rand() % 54;
    }
    return (randomnumber);
}

card pullacard (bool chosencard[], card card)
{
  if (chosencard[card.number] = true)
  {
    // JOKER  = 28
    if (card.number == 28 || card.number == 14)
    {
      cout << "JOKER " << endl;
      card.suit = 0;
    }
    // HEARTS = 1 through 13
    if ((card.number >= 0) && (card.number <= 13))
    {
      cout << "Hearts of : " << CARDS[card.number%13] << endl;
      card.suit = 1;
    }
    // SPACES = 15 through 27
    if (card.number >= 15 && card.number <= 27)
    {
      cout << "Spades of : " << CARDS[card.number%13]  << endl;
      card.suit = 2;
    }
    // CLUBS  = 29 through 41
    if (card.number >= 29 && card.number <= 41)
    {
      cout << "Clubs of : " << CARDS[card.number%13] << endl;
      card.suit = 3;
    }
    // DIAMONDS = 42 through 54
    if (card.number >= 42 && card.number <= 54)
    {
      cout << "Diamonds of : " << CARDS[card.number%13] << endl;
      card.suit = 4;
    }


    //cout << chosencard[card.number] << endl;
    // for (int x = 0; x < 54; x++)
    // {
    //   Sleep(3);
    //   if (x%13 == 0)
    //   {
    //     cout << endl;
    //   }
    //   cout << chosencard[x] << " ";
    // }
    // cout << endl;
  }
  chosencard[card.number];
  return card;
}

void game (stack<card> history, bool chosencard[])
{


}


int main()
{
  string title = "| E G Y P T I A N  R A T  S L A P |\n";
  //typer(title);
  cout << "===================================" << endl;
  cout << "___________________________________" << endl;
  cout << endl; cout << endl;
  stack<card> history;
  bool cycle = true;
  randomseed();

  while (cycle)
  {
    card card1;
    card card2;
    card1.number = randomnumber(DECK);
    card2.number = randomnumber(DECK);

    cout << "-------------------------------------" << endl;
    history.push(pullacard(DECK, card1));
    history.push(pullacard(DECK,card2));
    game(history,DECK);

    cout << "-------------------------------------" << endl;
    cout << " *** Press Enter to Continue ***" << endl;
    cin.ignore();
  }

  return 0;
}
