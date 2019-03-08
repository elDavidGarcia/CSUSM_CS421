#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

// transform NFAe into NFA  (nfa-e.txt into nfa.txt)

// Transitions of the NFAe in a matrix.  10 states and 5 chars.
// Each slot contains a vector of integers indicating the next states.
vector<int> NFAe[10][5]; // with e's in slot 4
int maxState;   // the highest state number

// ----- put utility functions here ----------------------------------------


void buildnfae()
{ 
  int state; int dest; char c; 

  ifstream fin ("nfa-e.txt", ios::in);

  fin >> maxState; // states are 0 through this

  // ** store nfa-e.txt into NFAe and display it

  fin.close();
}


int main()
{ 

  buildnfae(); // NFAe has been created

  // for each state-char pair of NFAe, compute e* char e* to add to the NFA

  cout << "For each state, find all the states reachable using only e's" << endl; 
  for (int s = 0; s <= maxState;  s++)
    {
      // from state s, find all the states rechable using only e's
      // These are stored in the Eends[s]
    }
  // display the Eends 

  cout << "Computing e* c e* for each state-c pair.. " << endl;
  for (int s = 0; s <= maxState; s++)
    for (int ci = 0; ci < 4; ci++)  // ci 4 is epsilon so not used
      { 
        // from s get direct on ci destinations

        // For each Eend[s], add on (Eend, ci) destinations 

        // For each destination, add on the Ends of it

        // send the final result for (s, ci) pair to output file
      }
   cout << "Sent NFA to nfa.txt .... " << endl;

}

 
