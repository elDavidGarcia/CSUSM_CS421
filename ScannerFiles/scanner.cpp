#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 7 
//=====================================================

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Damon Prince
// ** RE: (vowel | vowel n | consonant vowel | consonant vowel n |
//        consonant-pair vowel | consonant-pair vowel n)^+              
 
bool word(string s)
{
  int state = 0;
  int charpos = 0;
  
  while(s[charpos] != '\0')
    { //<state1> --n--> <state 0>
      if(state == 1 && (s[charpos] == 'n'))state = 0;
      //<state2> --y--> <state3>
      else if(state == 2 && (s[charpos] == 'y'))state = 3;
      //<state4> --h--> <state3>
      else if(state == 4 && (s[charpos] == 'h'))state = 3;
      //<state5> --s--> <state3>
      else if(state == 5 && (s[charpos] == 's'))state = 3;
      //<state6> --h--> <state3>
      else if(state == 6 && (s[charpos] == 'h'))state = 3;
      //<state0> or <state1> --s--> <state4>
      else if((state == 0 || state == 1) && (s[charpos] == 's'))
        state = 4;
      //<state0> or <state1> --t--> <state5>
      else if((state == 0 || state == 1)&& (s[charpos] == 't'))
        state = 5;
      //<state0> or <state1> --c--> <state6>
      else if((state == 0 || state == 1)&& (s[charpos] == 'c'))
        state = 6;
      //<state0> or <state1> --(d|j|w|y|z)--> <state 3>
      else if((state == 0 || state == 1) &&
              ((s[charpos] == 'd')||
               (s[charpos] == 'j')||
               (s[charpos] == 'w')||
               (s[charpos] == 'y')||
               (s[charpos] == 'z')))
        state = 3;
      //<state(0|1|2|3|4|5)> --(a|e|i|o|u|E|I)--> <state1>
      else if(((state == 0)||
	       (state == 1)||
	       (state == 2)||
	       (state == 3)||
	       (state == 4)||
	       (state == 5))&&
	      ((s[charpos] == 'a')||
	       (s[charpos] == 'e')||
	       (s[charpos] == 'i')||
	       (s[charpos] == 'o')||
	       (s[charpos] == 'u')||
	       ((s[charpos] == 'E')&&(charpos == s.size()-1))||
	       ((s[charpos] == 'I')&&(charpos == s.size()-1)))) 
	state = 1;
      //<state0> or <state1> --(b|g|h|k|m|n|p|r)--> <state2>
      else if(((state == 0)||(state == 1))&&
	      ((s[charpos] == 'b')||
	       (s[charpos] == 'g')||
	       (s[charpos] == 'h')||
	       (s[charpos] == 'k')||
	       (s[charpos] == 'm')||
	       (s[charpos] == 'n')||
	       (s[charpos] == 'p')||
	       (s[charpos] == 'r')))
	state = 2;
      //Invalid token, stuck, return.
      else return false;
      ++charpos;
    }//Close: while loop
  //Only return true if in a final state
  if(state == 0 || state == 1)return true;
  else return false;
}

// ** Add the PERIOD DFA here
// ** Done by: David A. Garcia
bool period(string s)
{//If the only character in the string is a period return true
  if((s[0] == '.')&&(s[1] == '\0')) return true;
  else return false;
}  
  
// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
enum tokentype {ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS,
		OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

static string tokenName[] = {"ERROR", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", 
			     "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", 
			     "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM"};


// ** Need the reservedwords table to be set up here. English will be
// ** used in Part C but it should be stored now.
// ** Do not require any file input for this.
// ** a.out should work without any additional files.
static string reservedWordBank[] = {"eofm","masu", "masen", "mashita", "masendeshita", 
				    "desu", "deshita", "o", "wa", "ni", "watashi", "anata",
				    "kare", "konojo", "sore", "mata", "soshite", 
				    "shikashi", "dakara"};

static tokentype reservedWordBankType[] = {EOFM,        //eofm
					   VERB,        //"masu"
					   VERBNEG,     //"masen"
					   VERBPAST,    //"mashita"
					   VERBPASTNEG, //"masendeshita"
					   IS,          //"desu"
					   WAS,         //"deshita"
					   OBJECT,      //"o"
					   SUBJECT,     //"wa"
					   DESTINATION, //"ni"
					   PRONOUN,     //"watashi"
					   PRONOUN,     //"anata"
					   PRONOUN,     //"kare"
					   PRONOUN,     //"konojo"
					   PRONOUN,     //"sore"
					   CONNECTOR,   //"mata"
					   CONNECTOR,   //"soshite"
					   CONNECTOR,   //"shikashi"
					   CONNECTOR};  //"dakara"

static string reservedWordBankTranslation[] = {"end of file marker",  //"eofm"
					       "",                    //"masu"
					       "",                    //"masen"
					       "",                    //"mashita"
					       "",                    //"masendeshita"
					       "",                    //"desu"
					       "",                    //"deshita"
					       "",                    //"o"
					       "",                    //"wa"
					       "",                    //"ni"
					       "I/me",                //"watashi"
					       "you",                 //"anata"
					       "he/him",              //"kare"
					       "she/her",             //"konojo"
					       "it",                  //"sore"
					       "also",                //"mata"
					       "then",                //"soshite"
					       "however",             //"shikashi"
					       "therefore"};          //"dakara"

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// ** Done by: David A. Garcia 
void scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file via fin
  /* 
  2. Call the token functions one after another (if-then-else)
     And generate a lexical error message if both DFAs failed.
     Let the token_type be ERROR in that case.
     
  3. Make sure WORDs are checked against the reservedwords list
     If not reserved, token_type is WORD1 or WORD2.
  4. Return the token type & string  (pass by reference)
  */

  fin >> w;
  if(w == reservedWordBank[0])//If word is == eofm 
    a = reservedWordBankType[0];//set a to EOFM
  else if(word(w))//If w is a word
    {
      for(int i = 0; i < 19; i++)//Checked reserved word bank
	{
	  if(w == reservedWordBank[i])
	    {
	      a = reservedWordBankType[i];//Set the type in a
	      return;
	    }
	}
      //Check if it's a word type 2
      if(w[w.size()-1] == 'E' || w[w.size()-1] == 'I') a = WORD2;
      else a = WORD1;//else it's a word type 1
    }
  else if(period(w)) a = PERIOD;//Check to see it's a period instead
  else//If both fail it is a lexical error
    {
      cout << "\nLexical Error: " << w << " is not a valid token";
      a = ERROR; 
    }
  return;
}//the end



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Rika & David A. Garcia
int main()
{
  tokentype thetype;
  string theword; 
  string filename;
  
  
  cout << "Enter the input file name: ";
  cin >> filename;
  
  fin.open(filename.c_str());

  if(!fin)
    {
      cerr << "\nError! Unable to open file: " << filename << endl;
      return 0;
    }
  
  while(1)
    {
      scanner(thetype, theword);  // call the scanner
      if(theword == "eofm") break;
      cout << "\nType is: " << tokenName[thetype] << endl;
      cout << "Word is: " << theword << endl;   
      }
  
  fin.close();
  return 0;
}// end
