#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool AccountExists(string uName)
{ // Read file for username
  bool result;
  ifstream acctFile;
  string userLine, line, fName, lName;

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

int main()
{
  string uName;
  uName = "heffs";
  cout << "Account Exists: " << AccountExists(uName) << endl;
}
