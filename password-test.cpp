#include <iostream>
#include <string>

using namespace std;

bool PasswordIsGood(string pWord)
{
  bool result = true;
  bool MinPasswordLength(string);
  bool HasWhiteSpace(string);

  if()
  {
    result = true;
  }
  else
  {
    result = false;
  }
  return result;
}

bool HasWhiteSpace(string pWord)
{ // Checks password for whitespace. Meets requirements results in 'false' or '0'
  bool result = false;
  for (int i = 0; i < pWord.length(); i++)
  {
    if (pWord[i] == ' ')
    {
      result = true;
    }
  }
  return result;
}

bool MinPasswordLength(string pWord)
{ // Checks the length of the password. Meets requirements results in 'true' or '1'
  bool result = false;
  if (pWord.length() >= 10)
  {
    result = true;
  }
  return result;
}

int main()
{
  string pWord, strPWord;

  cout << PasswordIsGood("password password") << endl;  // only fails spaces    0
  cout << PasswordIsGood("asdf") << endl;               // only fails length    0
  cout << PasswordIsGood("a s d") << endl;              // fails both           0
  cout << PasswordIsGood("passwordpassword") << endl;   // good password        1

  // do {
  //   cout << "\nCreate a Password that is: " << endl;
  //   cout << "\t - At least 10 characters long " << endl;
  //   cout << "\t - Contains no whitespace " << endl;
  //   cout << "Password: ";
  //   getline(cin, pWord);
  // } while(PasswordIsGood(pWord) == false);
}
