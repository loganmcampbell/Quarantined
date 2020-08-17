#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;
string CONST CARDS [13] = {"1","2","3","4","5","6","7","8","9","10", "JACK", "QUEEN", "KING"};
int CONST SUITS [5] = {0,1,2,3,4};
bool DECK [52] = {true};

struct card
{
  int number;
  int suit;
};

void randomseed()
{
  srand(time(NULL));
}

int randomnumber()
{
    //Numbers between 0 and 15
    int randomnumber = rand() % 52 + 0;
    return (randomnumber);
}

card pullacard (bool chosencard[], card card)
{
  //cout << "card # in entire deck : " << card << endl;
  if (chosencard[card.number] = true)
  {
    // JOKER  = 28
    if (card.number == 28 || card.number == 14)
    {
      cout << "JOKER " << endl;
      card.suit = 0;
    }
    // HEARTS = 1 through 13
    if ((card.number >= 1) && (card.number <= 13))
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

    chosencard[card.number] = false;
  }
  return card;
}


int main()
{
  cout << " =========================" << endl;
  cout << " CAN YOU GET OFF THE BUS?!" << endl;
  cout << " =========================" << endl;

  int cycle = 0;
  bool reset = false;
  while ( cycle < 52 && reset == false)
  {
    reset = false;
    card card;
    card.number = randomnumber();
    card = pullacard(DECK,card);

    cout << "RED OR BLACK ? : ";
    char color;
    cin >> color;

    if ((color == 'R') && (card.suit == 1 || card.suit == 4))
    {
      cout << "CONTINUE!" << endl;
    }

    if ((color == 'B') && (card.suit == 2 || card.suit == 3))
    {
      cout << "CONTINUE!" << endl;
    }
    reset = true;
  }



  return 0;
}
