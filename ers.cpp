#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;

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


void pullacard (bool chosencard[], int card)
{
  string cards [14] = {"1","2","3","4","5","6","7","8","9","10", "JACK", "QUEEN", "KING","JOKER"};
  if (chosencard[card] = true)
  {
    // HEARTS = 1 through 13
    if (card = 1 || card <= 13)
    {

      cout << "Hearts of : " << card << " ♥ " << endl;
    }
    // JOKER  = 14
    else if (card = 14)
    {
      cout << "JOKER || LOL || " << endl;
    }
    // SPACES = 15 through 27
    else if (card >= 15 && card <= 27)
    {
      cout << "Spades of : " << cards[card%13] << " ♠ " << endl;
    }
    // JOKER  = 28
    else if (card = 28)
    {
      cout << "JOKER || LOL || " << endl;
    }
    // CLUBS  = 29 through 41
    else if (card >= 29 && card <= 41)
    {
      cout << "Clubs of : " << cards[card%13] << " ♣ " << endl;
    }
    // DIAMONDS = 42 through 54
    else if (card >= 42 && card <= 41)
    {
      cout << "Diamonds of : " << cards[card%13] << " ♦ " << endl;
    }
    chosencard[card] = false;
  }
  cout <<"END OF PULLACARD" << endl;
}


int main()
{
  string title = "| E G Y P T I A N  R A T  S L A P |\n";
  //typer(title);
  cout << "===================================" << endl;
  cout << "___________________________________" << endl;
  cout << endl; cout << endl;
  bool deck [54] = {true};
  randomseed();
  int card = randomnumber1();
  cout << "CARD PICKED : " << card << endl;
  cout << "CARD PICKED MOD 13 " << card%13 << endl;
  pullacard(deck, card);

  return 0;
}
