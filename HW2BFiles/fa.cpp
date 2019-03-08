#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// CS421 File fa.cpp for HW2B

//-----------------------------------------------------------------
// Your name: David A. Garcia

// ** Change this to fit the HW3C specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE
//-----------------------------------------------------------------

// IDENT DFA 
 // This FA is for identifier token
bool ident_token(string s)
{
  int state = 0;
  int charpos = 0;
  cout << "\nTrying ident token machine\n";
  while (s[charpos] != '\0')//While not end of string
    {
      cout << "(Current state: " << state << ") (Character: " << s[charpos] << ")\n";
      //State 0; needs an a or b to go to state 1. 
      if (state == 0 && ((s[charpos] == 'a')||(s[charpos] == 'b')))
	state = 1;
      //State 1, loop back to itself if any of the characters are met. Else go to error. 
      else if(state == 1 && 
	      ((s[charpos] == 'a')|| 
	       (s[charpos] == 'b')||
	       (s[charpos] == '_')||
	       (s[charpos] == '2')||
	       (s[charpos] == '3')))
	state = 1;
      //error state. Can not travel because requirements were not met.
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;//move character index
    }//end of while
  //only return true if it ended up in state 1
  if (state == 1) return(true);  // end in a final state
  return(false);//requirements were not met for this machine
}

// REAL DFA 
// This FA is for real token
bool real_token(string s)
{
  int state = 0;
  int charpos = 0;
  cout << "\nTrying real token token machine\n";
  while (s[charpos] != '\0')//go through all charaters of string
    {
      cout << "(Current state: " << state << ") (Character: " << s[charpos] << ")\n";
      //State 0. Loop back to itself if it encounters a "digit"
      if (state == 0 && ((s[charpos] == '2')||(s[charpos] == '3'))) state = 0;
      //State 0. Move to next state once there is a period
      else if(state == 0 && s[charpos] == '.') state = 1;
      //State 1. Must have a digit after period to move to final state.
      else if(state == 1 && ((s[charpos] == '2')||(s[charpos] == '3'))) state = 2;
      //State 2. Final state. Loop back to itself if there are more "digits". 
      else if(state == 2 && ((s[charpos] == '2')||(s[charpos] == '3'))) state = 2;
      //Error state. Cannot move forward. Requirements not met.
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;//update character position
    }//end of while
  //return true if requirements were met and its in final state
  if (state == 2) return(true);  // end in a final state
  return(false);//else return false. Requirements not met
}


//INT DFA 
// This FA is for integer token
bool integer_token(string s)
{
  int state = 0;
  int charpos = 0;
  cout << "\nTrying integer token token machine\n";
  while (s[charpos] != '\0')//Go through all characters in string.
    {
      cout << "(Current state: " << state << ") (Character: " << s[charpos] << ")\n";
      //State 0. Move to state 1 if there is a "digit"
      if (state == 0 && ((s[charpos] == '2')||(s[charpos] == '3'))) state = 1;
      //State 1. Final state. Loop back to itself if there are more digits. 
      else if(state == 1 && ((s[charpos] == '2')||(s[charpos] == '3'))) state = 1;
      //Error state. Cannot move forward. Requirements not met, return false.
      else
        {
          cout << "I am stuck in state " << state << endl;
          return(false);
        }
      charpos++;//Update the character position index
    }//end of while
  //Return true if requirements were met and ended up in state 1
  if (state == 1) return(true);  // end in a final state
  return(false);//Requirements not met so return false.
}

// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
fstream fin;   // file stream to use

// The test-driver
int main()
{ 
  //Get file name from user
  string fname;
  cout << "Enter the input file name:";
  cin >> fname; 
  //Attempt to open file input from user.
  fin.open( fname.c_str(), fstream::in);
  //Check if it was successful, if not let user know and exit.
  if(!fin)
    {
      cerr << "\nError: Unable to open file!" << fname << endl;
      return 0;
    }

  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword; 

  while(true)  // keep on going, uses break to get out of loop 
    {//Call the scanner
      scanner(thetype, theword);  // the paramers will be set by Scanner
      if (theword == "EOF") break;//Break out of loop if it reaches EOF
      cout << "\nType is:" << tokens[thetype] << endl;//Display word type.
    }
  cout << "\n**End of file was reached**\n";
  fin.close();//Close file
  return 0;
}// end of main

// sets the_type and w 
int scanner(tokentype& the_type, string& w)
{  
  // This goes through all machines one by one on the input string w
  cout << "\n\n.....Scanner was called..." << endl;
  fin >> w;//Get word from the file
  cout << "Word is: " << w << endl;//Display word
  //call Identifier "machine". If true, type is identifier
  if(ident_token(w)) the_type = IDENT;
  //Not Ident so check real "machine". If true, type is real number.
  else if(real_token(w)) the_type = REAL;
  //Not real either! Check integer "machine". If true, type is integer.
  else if(integer_token(w)) the_type = INT;
  //Not in this language. Return type as ERROR
  else
    { cout << "Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }
}//the very end of scanner
