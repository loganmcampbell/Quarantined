#include <stdio.h>

// CONVERTS A STRING OF NUMBERS TO IT'S INTEGER FORM
int atoifunction (char *string)
{
  // printf("--------------\n");
  // printf("|ATOI FUNCTION| \n");
  // printf("--------------\n");
  //INITALIZE THE FIRST NEGATIVE (1) AND CONTAINER VALUE FOR THE STRING
  int negative = 1;
  int value = 0;
  // DETERMINE IF THE FIRST CHARACTER IS THE NEGATIVE SIGN
  if (string[0] == '-')
  {
    negative = -1;
    // INCREMENT NEXT TO THE NEXT CHARACTER
    string++;
  }
  //ITERATE THROUGH THE STRING AND CONVER CHARACTER #'S INTO THE VALUE
  for (char character = *string; character != '\0'; character = *++string)
  {
      //WHILE EACH CHARACTER IS LESS THAN OR EQUAL TO 9
      //AND EACH CHARACTER IS GREATER THAN OR EQUAL TO 0.
       if (character >= '0' && character <= '9')
      {
        // FOR THIS SECTION THE C STANDARD IS USED.
        // WHY CHARACTER - '0'? ANY NUMBER CHARACTER THAT'S HIGHER THAN 0 IS EQVIVALENT TO IT'S NUMBER VALUE.
        // BECAUSE : CHAR(1) - CHAR(0) = 1-0 = 1  FURTHERMORE => CHAR(9) - CHAR(0) = 9
        // WHY VALUE * 10? BECAUSE EACH PLACE VALUE IS x10 and then minus the character values ^(the above) to capture the same int form as above.
        value = value * 10 + (character - '0');
        //printf("%c VALUE : %d \n", character, value );
      }
      //IF NOT BETWEEN THE BOUNDS OF (0 to 9)
      else
      {
        //RETURN 0 => FOR A UNORTHODOX CHARACTER
        // printf("BAD STRING\n");
        return 0;
      }
    }
  // BASIC MULTPLICATION TO FLIP THE VALUE (POS/NEG)
  value = negative * value;
  // printf("%d\n",value );
  // printf("--------------\n");
  return value;
}

// CONVERTS STRING OF NUMBERS TO IT'S UNSIGNED INTEGER FORM
unsigned int atoufunction (unsigned char *string)
{
  // printf("--------------\n");
  // printf("|ATOU FUNCTION| \n");
  // printf("--------------\n");
  //INITALIZE THE FIRST NEGATIVE (1) AND CONTAINER VALUE FOR THE STRING
  unsigned int negative = 1;
  unsigned int value = 0;
  // DETERMINE IF THE FIRST CHARACTER IS THE NEGATIVE SIGN
  if (string[0] == '-')
  {
    // SINCE STRINGS THAT ARE NEGATIVE RETURN 0.
    negative = 0;
    // MULTPLICATION OF NEG*VALUE = 0.
    // INCREMENT NEXT TO THE NEXT CHARACTER
    string++;
  }
  //ITERATE THROUGH THE STRING AND CONVER CHARACTER #'S INTO THE VALUE
  for (char character = *string; character != '\0'; character = *++string)
  {
      //WHILE EACH CHARACTER IS LESS THAN OR EQUAL TO 9
      //AND EACH CHARACTER IS GREATER THAN OR EQUAL TO 0.
       if (character >= '0' && character <= '9')
      {
        value = value * 10 + (character - '0');
        //printf("%c VALUE : %d \n", character, value );
      }
      //IF NOT BETWEEN THE BOUNDS OF (0 to 9)
      else
      {
        //RETURN 0 => FOR A UNORTHODOX CHARACTER
        //printf("BAD STRING\n");
        return 0;
      }
    }
  // BASIC MULTPLICATION TO FLIP THE VALUE (POS/NEG)
  value = negative * value;
  // CHECK IF THE POS UNSIGNED INT IS VALID.
  if (!(value <= sizeof(unsigned int)))
  {
    //printf("Out of Range\n");
    return 0;
  }
  //printf("%d\n",value );
  // printf("--------------\n");
  return value;
}

// STRING TO INTEGER FOR STRCMP FUNCITON
int stoi (char *string)
{
  //INITALIZE A INTEGER CONTAINER/VALUE
  int value = 0;
  // ITERATRE THROUGH STRING TO GATHER LEXI VALUE AS A WHOLE
  for (char character = *string; character != '\0'; character = *++string)
  {
    //DATACASTING TO CHARACTER DATATYPE
    int cvalue = character;
    //ADD CHARACTER VALUE INTO VALUE CONTAINER
    value += cvalue;
  }
  //printf("ENTIRE STRING VALUE : %d\n", value);
  return value;
}

int strcmpfunction (char *string1, char *string2)
{
  //COMPARES EACH STRING ACCORDINGLY TO ASSIGNMENT.
  if (stoi(string1) == stoi(string2))
  {
    return 0;
  }

  if (stoi(string1) < stoi(string2))
  {
    return -1;
  }

  if (stoi(string1) > stoi(string2))
  {
    return 1;
  }

}

int main()
{
  int return_value = 0;
  //ATOI FUNCTION TEST//
  //============================================
  printf("======================== \n");
  printf(":: ATOI FUNCTION TEST :: \n");
  printf("======================== \n");
  char* test00 = "2020";
  char* test01 = "-2020";
  char* test02 = "&2020";
  return_value = atoifunction(test00);
  printf("TEST 1 || ATOI VALUE = %d\n", return_value);
  atoifunction(test01);
  return_value = atoifunction(test01);
  printf("TEST 2 || ATOI VALUE = %d\n", return_value);
  atoifunction(test02);
  return_value = atoifunction(test02);
  printf("TEST 3 || ATOI VALUE = %d\n", return_value);

  //ATOU FUNCTION TEST//
  //============================================
  printf("======================== \n");
  printf(":: ATOU FUNCTION TEST :: \n");
  printf("======================== \n");
  char* testa = "3";
  char* testb = "2147483647";
  char* testc = "2020";
  return_value = atoufunction(testa);
  printf("TEST 1 || ATOU VALUE = %d\n", return_value);
  return_value = atoufunction(testb);
  printf("TEST 2 || ATOU VALUE = %d\n", return_value);
  return_value = atoufunction(testc);
  printf("TEST 3 || ATOU VALUE = %d\n", return_value);

  //STRCMP FUNCTION TEST//
  //============================================
  printf("========================== \n");
  printf(":: STRCMP FUNCTION TEST :: \n");
  printf("========================== \n");
  char* test03 = "DOG";
  char* test04 = "DOG";
  return_value = strcmpfunction(test03,test04);
  printf("TEST 1 || STRCMP VALUE = %d\n", return_value );
  test03 = "CAT"; test04 = "DOG";
  return_value = strcmpfunction(test03,test04);
  printf("TEST 2 || STRCMP VALUE = %d\n", return_value );
  test03 = "FOX";
  return_value = strcmpfunction(test03,test04);
  printf("TEST 3 || STRCMP VALUE = %d\n", return_value );
  printf("======================================\n");
  //============================================

return 0;
}
