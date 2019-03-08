#include<iostream>
#include<string>
using namespace std;
#include "queue.h" //Uses queue from 311 

// CS421 HW1 Write a generator in C++ for L = {x | x is a binary number}.

// Your name: David A. Garcia

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
  for(int i = 0; i < s.length(); ++i)//Looks at individual characters
    if(s[i] != '1' && s[i] != '0') return false;//Compares them to 0 and 1
  return true;
}

// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C 
//   after 20 strings have been displayed.
int main()
{
  queue myQueue; //Make a string queue
  el_t elem; //Variable to store element removed from queue
  string L[3] = {"0", "1", "2"};//This is the language
  int counter = 0;//used for array counter
  string front_Elem = "";//Start off with zero
  string sum;//The strings will concatinate into here
  while(1)// loop -- indefinitely
    {
      try
        {//every 3 iterations we need the next item in the queue
	  for(int i = 0; i < 3; ++i)
	    {
	      sum = front_Elem + L[counter];//"add" the strings 
	      if(recognizer(sum))//If its bianry, display it
		cout << sum << endl;
	      myQueue.add(sum);//add sum into the queue
	      counter = (counter+1)%3;//moves array "pointer" within the array
	    }//Close for(int i...
	  myQueue.remove(front_Elem);//Need to remove next item of the queue to
	}//close try                //create new string
      //Catch the overflow thrown when queue filled up, let user know queue is full
      //and end program
      catch(queue::Overflow)
        {
          cout << "\n**Cannot add anymore, queue is full**\n";
          return 0;
        }
    }//Close while loop
}// end of program
