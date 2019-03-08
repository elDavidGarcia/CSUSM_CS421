#include<iostream>
#include<string>
using namespace std;

// CS421 HW1 Write a recognizer in C++ for L = {x | x is a binary number}.

// Your name: David A. Garcia

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{
  for(int i = 0; i < s.length(); ++i)//loop stops when All chars checked
    if(s[i] != '1' && s[i] != '0') return false;//compares to binary
  return true;
}

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout YES IN L or NO NOT IN L depending on what was returned.
int main()
{
  string input;
  cout << "Enter a string in binary: ";
  cin >> input;
  //If returned true display it is in the language
  if(recognizer(input)) 
    cout << "YES IN L\n";
  else //Was not in the language 
    cout << "NO NOT IN L\n"; 
}
