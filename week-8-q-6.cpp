#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstdlib>

using namespace std;

bool AccountExists(string uName)
{
  bool result;
  ifstream acctFile;
  string line;

  acctFile.open("creds.txt");
  if (acctFile)
  {
    while (getline(acctFile, line))
    {
      stringstream ss(line);
      while(getline(ss, line, ':'))
      {
        if (line == uName)
        {
          result = true;
          return result;
        }
        else
        {
          result = false;
        }
      }
    }
    acctFile.close();
  }
  return result;
}

bool PasswordExists(string pWord)
{
  bool result;
  ifstream acctFile;
  string line;

  acctFile.open("creds.txt");
  if (acctFile)
  {
    while (getline(acctFile, line))
    {
      stringstream ss(line);
      while(getline(ss, line, ':'))
      {
        if (line == pWord)
        {
          result = true;
          return result;
        }
        else
        {
          result = false;
        }
      }
    }
    acctFile.close();
  }
  return result;
}

string BuildUserName(string fName, string lName)       // WORKS!
{
  string uName;
  uName = lName.substr(0, 4) + fName[0];
  for (int i = 0; i < uName.length(); i++)
  {
    uName.at(i) = tolower(uName.at(i));
  }
  return uName;
}

bool ValidatePassword(string pWord)                      // Works!
{
  bool result, HasWhiteSpace(string), MeetsPasswordLength(string);
  if ((MeetsPasswordLength(pWord) == true) && (HasWhiteSpace(pWord) == false))
  {
    result = true;
  }
  else
  {
    result = false;
  }
  return result;
}

bool HasWhiteSpace(string pWord)                        // WORKS!
{ // Meets requirements results in 'false' or '0'
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

bool MeetsPasswordLength(string pWord)                  // WORKS!
{ // Meets requirements results in 'true' or '1'
bool result = false;
if (pWord.length() >= 10)
{
  result = true;
}
return result;
}

string EncryptPassword(string pWord)                    // WORKS!
{
  int key = 13;
  for (int i = 0; i < pWord.length(); i++)
  {
    pWord.at(i) = (pWord.at(i) + key) % 127;
    if (pWord.at(i) < 33)
    {
      pWord.at(i) = (pWord.at(i)) + 33;
    }
  }
  return pWord;
}

void CreateAccountMenu()
{
  // void CreateAccount(string, string, string)
  string ShowAccountDetails(string, string);
  string BuildUserName(string, string);
  string ShowPasswordMenu();
  string EncryptPassword(string);
  string fileName = "creds.txt", fName, lName, uName, pWord;
  bool AccountExists(string);
  ofstream acctFile;

  cout << "Creating new account...\n\n";
  cout << "First Name: \t";
  cin >> fName;

  cout << "Last Name: \t";
  cin >> lName;
  cout << endl;

  uName = BuildUserName(fName, lName);
  ShowPasswordMenu();
  cin >> pWord;

  if(AccountExists(uName) == true)
  {
    cout << "Account exists!";
  }
  else
  {
    if(ValidatePassword(pWord) == true)
    {
      acctFile.open(fileName.c_str(), fstream::app);
      acctFile << BuildUserName(fName, lName) + ":" + EncryptPassword(pWord) << "\n";
      acctFile.close();
      ShowAccountDetails(fName, lName);
    }
    else
    {
      ShowPasswordMenu();
    }
  }
}

string ShowPasswordMenu()
{
  string pWord;
  cout << "Create a Password that is: " << endl;
  cout << "\t - At least 10 characters long " << endl;
  cout << "\t - Contains no whitespace " << endl;
  cout << "Password: ";
  return pWord;
}

void ShowAccountDetails(string fName, string lName)
{
  string BuildUserName(string, string);
  string uName = BuildUserName(fName, lName);
  string emailAddress = uName + "@norwich.edu";
  cout << "\nWelcome, " << fName << " " << lName << "!" << endl;
  cout << "Your request for a new account has been approved! " << endl;
  cout << "Your username is: " << uName << endl;
  cout << "Your new email address is: " << emailAddress << endl;
  cout << endl;
}

void Login()
{
  // Login user account
  bool AccountExists(string);
  bool PasswordExists(string);
  string uName, pWord;
  cout <<"Login To Your Account..... " << endl;
  cout << "\tUsername: ";
  cin >> uName;

  cout << "\tPassword: ";
  cin >> pWord;

  if(AccountExists(uName) && PasswordExists(EncryptPassword(pWord)))
  {
    cout << "\n***Access Granted***" << endl;
    cout << "Welcome, " << uName << "!" << endl;
  }
  else
  {
    cout << "\n***Access Denied***" << endl;
  }
};

int main()
{
  void CreateAccount();
  int menuOption;

  do
  {
    cout << "\nPlease choose one of the following options: \n\n";
    cout << "\tEnter '1' to login to an existing account" << endl;
    cout << "\tEnter '2' to create a new account" << endl;
    cout << "\tEnter '3' to exit" << endl;
    cout << "" << endl;
    cout << "Option: ";
    cin >> menuOption;
    cout << "\n";

    switch (menuOption)
    {
      case 1:
      // Login to an existing account
      Login();
      break;

      case 2:
      CreateAccountMenu();
      break;

      case 3:
      // Exit
      return 0;
      break;

      default:
      cout << "Invalid Option.\n\n";
    }
  } while (menuOption != 3);
}
