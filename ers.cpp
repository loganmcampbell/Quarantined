#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <stack>

using namespace std;
string CONST CARDS [13] = {"1","2","3","4","5","6","7","8","9","10", "JACK", "QUEEN", "KING"};
int CONST SUITS [5] = {0,1,2,3,4};

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


int randomnumber1()
{
    //Numbers between 0 and 15
    int randomnumber = rand() % 54 + 1;
    return (randomnumber);
}
int randomnumber2()
{
    //Numbers between 0 and 15
    int randomnumber = rand() % 54 + 1;
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

void game (stack<card> history, bool chosencard[])
{
  card last_card = history.top();
  while (!history.empty())
  {
    history.pop();
    card curr_card = history.top();
    if (CARDS[last_card.number%13] == CARDS[curr_card.number%13])
    {
      cout << "DOUBLES" << endl;
    }
    else
    {
      break;
    }
  }





  cout <<"COMPLETE"<< endl;

}


int main()
{
  string title = "| E G Y P T I A N  R A T  S L A P |\n";
  //typer(title);
  cout << "===================================" << endl;
  cout << "___________________________________" << endl;
  cout << endl; cout << endl;
  bool DECK [54] = {true};
  int turns = 1;
  stack<card> history;

  randomseed();

  while (turns <= 54)
  {
    card card1;
    card card2;
    card1.number = randomnumber1();
    card2.number = randomnumber2();
    // ENSURE THERE ISN'T TWO CARDS PULLED AT THE SAME TIME.
    while (card1.number == card2.number)
    {
      card1.number = randomnumber1();
      card2.number = randomnumber2();
    }
    cout << "-------------------------------------" << endl;
    history.push(pullacard(DECK, card1));
    history.push(pullacard(DECK,card2));
    game(history,DECK);
    cout << "-------------------------------------" << endl;
    cout << " *** Press Enter to Continue ***" << endl;
    cin.ignore();
    turns = turns+2;
  }

  return 0;
}
