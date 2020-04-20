#include <iostream>
#include <vector>
using namespace std;

class Expense
{
private:
  string expenseName;
  int expenseAmount;
  public:
    void set_expense (int, string);
    int getAmt();
    string getName();
};

void Expense::set_expense(int value, string name)
{
  expenseName = name;
  expenseAmount = value;
}
int Expense::getAmt()
{
  return expenseAmount;
}
string Expense::getName()
{
  return expenseName;
}


int main()
{
  cout << "---------------------" << endl;
  cout << "|| Expenses Creator || " << endl;
  cout << "---------------------" << endl;
  cout << "press enter to start : ";
  cin.ignore();
  cout << "=====================" << endl;
  bool continuing = true;
  char choice;
  while (continuing)
  {
    cout << "\t ======= \t" << endl;
    cout << "\t M e n u \t" << endl;
    cout << "\t ======= \t" << endl;

    cout << "[0] : Add an expense" << endl;
    cout << "[1] : Delete an expense" << endl;
    cout << "[2] : Edit an expense" << endl;
    cout << "[3] : Calculate expenses" << endl;
    cout << "[*] : Exit PRGM " << endl;
    vector<Expense> allExpenses;
    cin >> choice;
    if (choice == '*')
      continuing = false;
    if (choice == '0')
    {
      Expense newExp;
      cout << "add expense name : ";
      string name;
      cin >> name;
      cin.clear();
      cout << "add expense amount : ";
      int amt;
      cin >> amt;
      cin.clear();
      newExp.set_expense(amt,name);
      allExpenses.push_back(newExp);
    }
    if (choice == '2')
    {
      cout << "displaying all expenses" << endl;
      cout << "=======================" << endl;
      cout << allExpenses.size() << endl;
      cout << "select the index of the expense [#] : ";
    }
    if (choice == '3')
    {
      cout << "calculating all total amounts : ";
      cout << "sum total : " << endl;
    }
  cout << endl;
  cout << "press enter to continue : ";
  cout << endl << endl;
  }
  return 0;
}
