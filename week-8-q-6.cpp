#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool AccountExists(string uName)
{ // Read file for username
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

bool CheckCredentials(string uName, string pWord)
{ // Read file for string match of username + ":" + password
  bool result;
  ifstream acctFile;
  string line, userCreds = uName + ":" + pWord;
  acctFile.open("creds.txt");
  if (acctFile)
  {
    while (getline(acctFile, line))
    {
      stringstream ss(line);
      while(getline(ss, line))
      {
        if (line == userCreds)
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

string BuildUserName(string fName, string lName)
{ // Build username using first and last name
  string uName;
  uName = lName.substr(0, 4) + fName[0];
  for (int i = 0; i < uName.length(); i++)
  {
    uName.at(i) = tolower(uName.at(i));
  }
  return uName;
}

bool ValidatePassword(string pWord)
{ // Validate the password meets length and no whitespace requirements
  bool result, HasWhiteSpace(string);
  bool MeetsPasswordLength(string);
  string ShowPasswordMenu();
  if ((MeetsPasswordLength(pWord) == true) && (HasWhiteSpace(pWord) == false))
  {
    result = true;
  }
  else if(MeetsPasswordLength(pWord) == false)
  {
    // Prompt for new Password
    cout << "\nCreate a Password that is: " << endl;
    cout << "\t - At least 10 characters long " << endl;
    cout << "\t - Contains no whitespace " << endl;
    cout << "Password: ";
    cin >> pWord;
    ValidatePassword(pWord);
  }
  else if(HasWhiteSpace(pWord) == true)
  {
    // Prompt for new Password
    cout << "\nCreate a Password that is: " << endl;
    cout << "\t - At least 10 characters long " << endl;
    cout << "\t - Contains no whitespace " << endl;
    cout << "Password: ";
    cin >> pWord;
    ValidatePassword(pWord);
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

bool MeetsPasswordLength(string pWord)
{ // Checks the length of the password. Meets requirements results in 'true' or '1'
  bool result = false;
  if (pWord.length() >= 10)
  {
    result = true;
  }
  return result;
}

string EncryptPassword(string pWord)
{ // Encrypts the password using ROT13
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
{ // Displays the account creation menu
  string ShowAccountDetails(string, string);
  string BuildUserName(string, string);
  void ShowPasswordMenu();
  string EncryptPassword(string);
  void CreateNewAccount(string, string, string);
  bool AccountExists(string);
  string fileName = "creds.txt", fName, lName, pWord;


  cout << "Creating new account...\n\n";
  cout << "First Name: \t";
  cin >> fName;

  cout << "Last Name: \t";
  cin >> lName;
  cout << endl;

  cout << "\nCreate a Password that is: " << endl;
  cout << "\t - At least 10 characters long " << endl;
  cout << "\t - Contains no whitespace " << endl;
  cout << "Password: ";
  cin >> pWord;

  if(AccountExists(BuildUserName(fName, lName)) == true)
  {
    cout << "Account exists!";
  }
  else
  {
    if(ValidatePassword(pWord) == true)
    {
      CreateNewAccount(fName, lName, pWord);
    }
    else
    {
      ShowPasswordMenu();
    }
  }
}

void CreateNewAccount(string fName, string lName, string pWord)
{ // Creates the account in the "DB"
  string BuildUserName(string, string);
  string fileName = "creds.txt";
  void ShowAccountDetails(string, string);
  ofstream acctFile;
  acctFile.open(fileName.c_str(), fstream::app);
  acctFile << BuildUserName(fName, lName) + ":" + EncryptPassword(pWord) << "\n";
  acctFile.close();
  ShowAccountDetails(fName, lName);
}

void ShowPasswordMenu()
{ // Displays the password menu

  // void CreateNewAccount(string, string, string);
  // string pWord;
  cout << "\nCreate a Password that is: " << endl;
  cout << "\t - At least 10 characters long " << endl;
  cout << "\t - Contains no whitespace " << endl;
  cout << "Password: ";

  // if(ValidatePassword(pWord) == false)
  // {
  //   ShowPasswordMenu(fName, lName);
  // }
  // else
  // {
  //   CreateNewAccount(fName, lName, EncryptPassword(pWord));
  // }
  // return pWord;
}

void ShowAccountDetails(string fName, string lName)
{ // Displays the account information post account creation
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
{ // Login user account
  bool CheckCredentials(string, string);
  string uName, pWord;
  cout <<"Login To Your Account..... " << endl;
  cout << "\tUsername: ";
  cin >> uName;

  cout << "\tPassword: ";
  cin >> pWord;

  if(CheckCredentials(uName, EncryptPassword(pWord)) == true)
  {
    cout << "\n***Access Granted***" << endl;
    cout << "Welcome, " << uName << "!" << endl;
  }
  else
  {
    cout << "\n***Access Denied***" << endl;
  }
}

int main()
{
  void CreateAccount();
  void Login();
  int menuOption;

  do
  {
    cout << "\nPlease choose one of the following options: \n\n";
    cout << "\tEnter '1' to login to an existing account" << endl;
    cout << "\tEnter '2' to create a new account" << endl;
    cout << "\tEnter '3' to exit" << endl;
    cout << endl;
    cout << "Option: ";
    cin >> menuOption;
    cout << endl;

    switch (menuOption)
    {
      case 1:
      // Login to an existing account
      Login();
      break;

      case 2:
      // Create a new user account
      CreateAccountMenu();
      break;

      case 3:
      // Exit
      cout << "***Exiting Program...... Goodbye.\n" << endl;
      return 0;
      break;

      default:
      cout << "Invalid Option.\n\n";
    }
  } while (menuOption != 3);
}
