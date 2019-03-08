#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

// transform NFA into DFA  (nfa.txt into dfa.txt)
// 0 a 0 1 -1 => <0> a <01>
// States allowed are 0 through 9
// Arrows allowed are a through e

ofstream fout ("dfa.txt", ios::out);  // output stream

vector<int> NFA[10][5];  // Transition of the NFA (10 states and 5 chars)
int maxState;      // the highest state indicated in nfa.txt first line
vector<string> DFA;  // vector of new states in DFA (each state name is a string)

// ----- utility functions ----------------------------------------


// ------------------ end of utility ------------------------------


// Reads nfa.txt to build the NFA data structure
void buildnfa()
{ 
  ifstream fin ("nfa.txt", ios::in);

  // **** code here *******************

  fin.close();
}


// adds state to DFA if it is new
void addNewState(string state)
{
  // *** code here ****************
}


// Main Driver
int main()
{ 

  cout << "Given your NFA in nfa.txt, this will produce the DFA in dfa.txt." << endl;
  cout << "State numbers must be 0 ... 9" << endl;
  cout << "Arrow labels can be anything from a .. e" << endl << endl;

  buildnfa();
  // NFA has been created

  addNewState("0");  // start with state 0 in DFA

  while (x < DFA.size() ) // for each DFA state
    { 
      // display the current DFA state S
      // For each possible arrow 
	   // go through each component state of S
	        // grab all destinations from NFA
                // append the destinations to a destination state name DS
           //If a transition on the arrow found for any component state,
                // display it and send it to dfa.txt
                // and DS is added to DFA if new
    }
  fout << "Any state with the original final state number is final" << endl;
  fout.close();
}

 
