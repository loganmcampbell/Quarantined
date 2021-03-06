#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <array>
#include <stack>
#include <conio.h>
#define ARROW_UP    0x48
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

int randomnumber(bool deck[], bool newdeck)
{
    //Numbers between 0 and 15
    int randomnumber = rand() % 54;
    if (!newdeck)
    {
      while(deck[randomnumber])
      {
        //cout << randomnumber << endl;
        randomnumber = rand() % 54;
      }
      return (randomnumber);
    }
    else
    {
      return -1;
    }
}

card pullacard (bool chosencard[], card card)
{
  cout << "CARD NUMBER :" << card.number;
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

  }

  chosencard[card.number];
  return card;
}

bool newdeck (bool cards[])
{
  int count = 0;
  for (int x = 0; x < 54; x++)
  {
    if (cards[x])
    {
      count++;
    }
  }
  if (count == 54)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void game (stack<card> history)
{
  int stack_number = 0;
  card top_card = history.top();
  while (!history.empty())
  {
    cout << stack_number << " : " << top_card.suit << "|" << CARDS[top_card.number%13] << endl;
    stack_number++;
    history.pop();
  }
}


int main()
{
  string title = "| E G Y P T I A N  R A T  S L A P |\n";
  cout << title;
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

    card1.number = randomnumber(DECK,newdeck(DECK));
    pullacard(DECK,card1);
    card2.number = randomnumber(DECK,newdeck(DECK));
    pullacard(DECK,card2);

    history.push(card1);
    history.push(card2);
    game(history);
    cout << "-------------------------------------" << endl;







    cout << "-------------------------------------" << endl;
    cout << " *** Press Enter to Continue ***" << endl;
    cin.ignore();
  }

  return 0;
}
