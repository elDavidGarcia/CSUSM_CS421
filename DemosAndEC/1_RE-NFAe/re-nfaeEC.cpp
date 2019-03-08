#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Each transition 
struct transition
{
  int start;    // start state
  char arrow;   // what to see in an arrow
  int end;      // next state
};

vector<transition> NFA[10];  // each NFA machine is a vector of transitions

// ------------- Put utility functions here --------------------
      

void processConcat()
{ int M1, M2;
  cout << "Enter number of the first machine:"; cin >> M1; 
  cout << "Enter number of the second machine:"; cin >> M2; 
  if (M1 == M2) { 
    cout << "copying the machine first ...." << endl;
    // copy the machine and display it }

    // create trasition from M1's end to M2's start
    // add the new machine to NFA
} 

void processOr()
{ int M1, M2;
  cout << "Enter number of the first machine:"; cin >> M1; 
  cout << "Enter number of the second machine:"; cin >> M2; 
  if (M1 == M2) { // must be a different one from M1
    cout << "Enter differnt number for the second machine";  cin >> M2;}
     
  // create new start 
  // create new final
  // For the new machine in NFA:
  // add transition from new start to M1 start
  // add transition from new start to M2 start
  // add M1 and M2 
  // add transition from M1 end to new final
  // add transition from M2 end to new final

 } 


void processStar()
{ int M1;
  cout << "Enter number of the machine:"; cin >> M1; 

  // create new start 
  // create new final
  // For the new machine in NFA:
  // add transition from new start to M1 start
  // add M1 
  // add transition (back) from M1 end to M1 start
  // add transition from M1 end to new final
  // add transition (skip) from new to new final

} 

void processPlus()
{ int M1;
  cout << "Enter number of the machine:"; cin >> M1; 

  // create new start 
  // create new final
  // For the new machine in NFA:
  // add transition from new start to M1 start
  // add M1 
  // add transition (back) from M1 end to M1 start
  // add transition from M1 end to new final
} 


int main()
{
 cout << "This program will transform regular expressions into NFA-e" << endl;
 cout << "But it is done interactively by asking you to apply operators" << endl;
 cout << "to component machines." << endl;

 ifstream fin ("re.txt", ios::in);  // components  come from re.txt

 char c;
 transition s;

 while (fin >> c)
    { 
      // build a transition for arrow label c
      // display the transition
      // add it to NFA
    }  
  fin.close();
  // finished creating component machines


  char A;  // user choice
  while (A != 'n')
    {
  cout << "---- MENU -----" << endl;
  cout << "* for a machine" << endl;
  cout << "+ for a machine" << endl;
  cout << "| for two machines" << endl;
  cout << "- for appending two machines" << endl;
  cout << "n to quit" << endl;
  cin >> A;
  
   if (A == '*') processStar();
   else if (A == '+') processPlus();
   else if (A == '|') processOr();
   else if (A == '-') processConcat();

    }
  cout << "Outputting all machines to nfa-e.txt... " << endl;
  ofstream fout ("nfa-e.txt", ios::out);
  // send all NFA contents to the output file
} 
