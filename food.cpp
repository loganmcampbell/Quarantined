#include <iostream>
using namespace std;

// PARENT CLASS
 class Food
{
    // private:
    //   string name;
    //   string color;
    //   string foodgroup;
    //   string texture;
    //   int sourness;
    //   int sweetness;
    //   int saltiness;
      // USE GETTERS AND SETTERS TO SETUP ABSTRACTION
  public:
    // FOR TESTING ATTRIBUTES WERE PLACED IN PUBLIC
    string name;
    string color;
    string foodgroup;
    string texture;
    int sourness;
    int sweetness;
    int saltiness;

    //DEFAULT CONSTRUCTOR (CREATED AND SETUP EVERYTIME YOU DECLARE AN OBJECT(S))
    Food()
    {
      name = "";
      color = "";
      foodgroup = "";
      texture = "";
      sourness = 0;
      sweetness = 0;
      saltiness = 0;
    }

    //CONSTRUCTOR WITH PARAMETERS
    void setup(string fname, string fgroup, string fcolor, string ftext, int fsour, int fswee, int fsalt)
    {
      name = fname;
      foodgroup = fgroup;
      color = fcolor;
      texture = ftext;
      sourness = fsour;
      sweetness = fswee;
      saltiness = fsalt;
    }

    void print()
    {
      cout << "FOOD NAME : " << name << endl;
      cout << "FOOD COLOR : " << color << endl;
      cout << "FOOD TEXTURE: " << texture << endl;
      cout << "FOOD SOURNESS: " << sourness << endl;
      cout << "FOOD SWEETNESS: " << sweetness << endl;
      cout << "FOOD SALTINESS:" << saltiness << endl;
    }



    //USE GETTERS AND SETTERS FOR INDIVDUAL ATTRIBUTES ON FRUIT OBJECTS
    // get : int getName() {return name;}
    // set : void setName(string newName){ name = newName;}
    // ,,,


};

  //CHILD CLASS
  class Fat: public Food
  {
  public:
    //POLYMORPHISM
    // USING PRINT FUNCTION SEPARATELY FROM PARENT
      void print()
      {
        cout << "FATS NAME : " << name << endl;
        cout << "FATS COLOR : " << color << endl;
        cout << "FATS TEXTURE: " << texture << endl;
        cout << "FATS SOURNESS: " << sourness << endl;
        cout << "FATS SWEETNESS: " << sweetness << endl;
        cout << "FATS SALTINESS:" << saltiness << endl;
      }

  };

  //CHILD CLASS
  class Dairies: public Food
  {

  };

  //CHILD CLASS
  class Proteins: public Food
  {

  };

  //CHILD CLASS
  class Vegetables: public Food
  {

  };

  //CHILD CLASS
  class Fruits: public Food
  {

  };

  //CHILD CLASS
  class Grains: public Food
  {

  };



int main()
{
  Fat chips;
  //setup(string fname, string fgroup, string fcolor, string ftext, int fsour, int fswee, int fsalt)
  chips.setup("DORITOS", "FATS", "ORANGE", "CRISPY", 0, 0, 10);
  chips.print();




  return 0;
}
