#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;
string CONST CARDS [13] = {"1","2","3","4","5","6","7","8","9","10", "JACK", "QUEEN", "KING"};
string CONST SUIT [5] = {"JOKER", "HEARTS", "SPADES", "CLUBS", "DIAMONDS"};
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
    while (randomnumber == 28 || randomnumber == 14)
    {
      randomnumber = rand() % 52 + 0;
    }
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
      card.suit = 0;
    }
    // HEARTS = 1 through 13
    if ((card.number >= 1) && (card.number <= 13))
    {
      card.suit = 1;
    }
    // SPACES = 15 through 27
    if (card.number >= 15 && card.number <= 27)
    {
      card.suit = 2;
    }
    // CLUBS  = 29 through 41
    if (card.number >= 29 && card.number <= 41)
    {
      card.suit = 3;
    }
    // DIAMONDS = 42 through 54
    if (card.number >= 42 && card.number <= 54)
    {
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
  randomseed();
  while (!reset)
  {
    card card1;
    card1.number = randomnumber();
    card1 = pullacard(DECK,card1);

    cout << "RED OR BLACK ? [R/B] : ";
    char color;
    cin >> color;

    if ((color == 'R' || color == 'r') && (card1.suit == 1 || card1.suit == 4))
    {
      // cout << "CONTINUE!" << endl;
      //cout << "[" << CARDS[card1.number%13] << " of " << SUIT[card1.suit] << "] " << endl;
    }

    else if ((color == 'B' || color == 'b') && (card1.suit == 2 || card1.suit == 3))
    {
      // cout << "CONTINUE!" << endl;
      //cout << "[" << CARDS[card1.number%13] << " of " << SUIT[card1.suit] << "] " << endl;
    }
    else
    {
      cout << "[x] :: [" << CARDS[card1.number%13] << " of " << SUIT[card1.suit] << "] :: [x]" << endl;
      cout << "\n\t ...PRESS ENTER TO CONTINUE..." << endl;
      cin.get();
      cin.ignore();
      continue;
    }

    card card2;
    card2.number = randomnumber();
    card2 = pullacard(DECK,card2);
    cout << "HIGH OR LOW FROM [" << CARDS[card1.number%13] << " of " << SUIT[card1.suit] << "] ? [H/L] : ";
    char range;
    cin >> range;

    if ( (range == 'H' || range == 'h') && (card2.number%13 > card1.number%13))
    {
      cout << "[" << CARDS[card2.number%13] << " of " << SUIT[card2.suit] << "] " << endl;
    }
    else if ((range == 'L' || range == 'l') && (card2.number%13 < card1.number%13) )
    {
      cout << "[" << CARDS[card2.number%13] << " of " << SUIT[card2.suit] << "] " << endl;
    }
    else if ( card2.number%13 == card1.number%13 )
    {
      cout << "[" << CARDS[card2.number%13] << " of " << SUIT[card2.suit] << "] " << endl;
    }
    else
    {
      cout << "[x] :: [" << CARDS[card2.number%13] << " of " << SUIT[card2.suit] << "] :: [x]" << endl;
      cout << "\n\t ...PRESS ENTER TO CONTINUE..." << endl;
      cin.get();
      cin.ignore();
      continue;
    }

    card card3;
    card3.number = randomnumber();
    card3 = pullacard(DECK,card3);
    card lowest;
    card highest;
    if (card1.number%13 < card2.number%13)
    {
      lowest = card1;
      highest = card2;
    }
    else
    {
         highest = card1;
        lowest = card2;
    }
    cout << "OUTSIDE OR IN-BETWEEN,"<< " [" << SUIT[lowest.suit] << "-" << CARDS[lowest.number%13]
    << " ~ " << SUIT[highest.suit] << "-" << CARDS[highest.number%13] <<  "] [O/I]: " << endl;
    char inout;
    cin >> inout;

    if ((inout == 'O' || inout == 'o') && (card3.number%13 < lowest.number%13 || card3.number%13 > highest.number%13))
    {
      cout << "[" << CARDS[card3.number%13] << " of " << SUIT[card3.suit] << "]" << endl;

    }
    else if ((inout ='I' || inout == 'i') && (card3.number%13 < highest.number%13 && card3.number%13 > lowest.number%13))
    {
      cout << " [" << CARDS[card3.number%13] << " of " << SUIT[card3.suit] << "]" << endl;

    }
    else
    {
      cout << "[x] :: [" << CARDS[card3.number%13] << " of " << SUIT[card3.suit] << "] :: [x]" << endl;
      cout << "\n\t ...PRESS ENTER TO CONTINUE..." << endl;
      cin.get();
      cin.ignore();
      continue;
    }

    card card4;
    card4.number = randomnumber();
    card4 = pullacard(DECK,card4);
    cout << "SUIT ? [H/S/C/D] : ";
    char suit;
    cin >> suit;

    if ((suit == 'H' || suit == 'h') && card4.suit == 1)
    {

    }
    else if ((suit == 'S' || suit == 's') && card4.suit == 2)
    {

    }
    else if ((suit == 'C' || suit == 'c') && card4.suit == 3)
    {

    }
    else if ((suit == 'D' || suit == 'd') && card4.suit == 4)
    {

    }
    else
    {
      cout << "[x] :: [" << CARDS[card4.number%13] << " of " << SUIT[card4.suit] << "] :: [x]" << endl;
      cout << "\n\t ...PRESS ENTER TO CONTINUE..." << endl;
      cin.get();
      cin.ignore();
      continue;
    }
    cout << "YOU'RE OFF THE BUS!" << endl;
    reset = false;

  }
  return 0;
}
