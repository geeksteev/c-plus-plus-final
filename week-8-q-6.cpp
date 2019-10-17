#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <cstdlib>

using namespace std;

void ShowMainMenu()
{
  // Displays menu in do while loop
  cout << "\nPlease choose one of the following options: \n\n";
  cout << "\tEnter '1' to login to an existing account" << endl;
  cout << "\tEnter '2' to create a new account" << endl;
  cout << "\tEnter '3' to exit" << endl;
  cout << "" << endl;
  cout << "Option: ";
};

void ShowPasswordMenu(string fName, string lName)
{
  bool CheckAccountExists(string), ValidatePassword(string);
  string pWord, CreateAccount(string, string, string), ShowAccountDetails(string, string), BuildUserName(string, string), EncryptPassword(string);
  cout << "Create a Password that is: " << endl;
  cout << "\t - At least 10 characters long " << endl;
  cout << "\t - Contains no whitespace " << endl;
  cout << "Password: ";
  cin >> pWord;

  CreateAccount(fName, lName, EncryptPassword(pWord));

  // }
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

string BuildUserName(string fName, string lName) // WORKS!
{
  string uName;
  uName = lName.substr(0, 4) + fName[0];
  for (int i = 0; i < uName.length(); i++)
  {
    uName.at(i) = tolower(uName.at(i));
  }
  return uName;
};

bool CheckAccountExists(string uName)
{
  bool result = false;
  ifstream acctFile;
  string line, fileName = "creds.txt";
  int curLine = 0;

  acctFile.open(fileName.c_str(), fstream::app);
  while (getline(acctFile, line))
  {
    curLine++;
    if (line.find(uName, 0) != string::npos)
    { // Finds username in file
      result = true;
    }
    else
    { // Does not find username in file
      result = false;
    }
  }
  acctFile.close();
  return result;
};

void CreateAccount(string fName, string lName, string pWord)
{
  void ShowAccountDetails(string, string);
  string BuildUserName(string, string);
  ofstream acctFile;
  string fileName = "creds.txt";
  acctFile.open(fileName.c_str(), fstream::app);
  acctFile << BuildUserName(fName, lName) + ":" + pWord << "\n";
  acctFile.close();
  ShowAccountDetails(fName, lName);
}

string EncryptPassword(string pWord) // WORKS!
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

bool ValidatePassword(string pWord)
{
  bool result, CheckWhiteSpace(string), CheckPasswordLength(string);
  if ((CheckPasswordLength(pWord)) && (CheckWhiteSpace(pWord))) // == true)
  {
    result = true;
  }
  else
  {
    result = false;
  }
  return result;
}

bool CheckWhiteSpace(string pWord)
{ // Meets requirements results in 'true'
  bool result = true;
  for (int i = 0; i < pWord.length(); i++)
  {
    if (pWord[i] == ' ')
    {
      result = false;
    }
  }
  return result;
}

bool CheckPasswordLength(string pWord)
{ // Meets requirements results in 'true'
  bool result = false;
  if (pWord.length() > 10)
  {
    result = true;
  }
  return result;
}

void CreateNewAccount()
{
  void CreatePassword(string, string), CreateAccount(string, string, string), ShowAccountDetails(string, string);
  void ShowPasswordMenu(string, string);
  string fName, lName, pWord;

  cout << "Creating new account...\n\n";
  cout << "First Name: \t";
  cin >> fName;

  cout << "Last Name: \t";
  cin >> lName;
  cout << endl;

  ShowPasswordMenu(fName, lName);
}

void login(string uName, string passWord)
  {
      
    cout << "Log into your Account...."
    cout << "Username: " << uName << endl;
    cout << "Password: " << passWord << endl;
    cin >> uName;
    cin >> passWord;
    
    
    
    // Login user account
      // Takes uName & passWord
      // Logs in user
  };

int main()
{
  void createAccount(string, string);
      string inputString;
      string encryptedString;
      string uName;
      string pWord;
      int menuOption;

      do
      {
          printMenu();
          cin >> menuOption;
          cout << "\n";

          switch (menuOption)
          {
          case '1':	login();
              // Login to an existing account
              break;

          case '2':
              createAccount(uName, pWord);
              break;

          case '3':		break;

          default:	cout << "Invalid Option. Please choose from the menu.\n\n";
        break;
      }
      } while (menuOption != '3');

    cout << "\n***Exiting Program......... Goodbye.\n\n";
    return 0;
}
