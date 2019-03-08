// =====================================================
// HW#: HW1P1 queue
// Your name: David Garcia
// Compiler:  g++ compiler
// File type: queue header file for queue.h 
//=====================================================

//----- Globally setting up the aliases ----------------
using namespace std;
#include <string>

typedef string el_t;          // el_t is an alias for the data type
// el_t is unknown to the client  

const int MAX_SIZE = 100;  // this is the max number of elements
// MAX is unknown to the client
//-------------------------------------------------------

class queue  
{
  private:
  // Data members are:
  el_t el[MAX_SIZE]; // an array called el.
                     // Elements will be found between front and rear but
                     // front may be behind rear since the queue wraps around
  int  count;          // how many elements do we have right now?
  int  front;          // where the front element of the queue is.
  int  rear;           // where the rear element of the queue is.

  public:    // prototypes to be used by the client
  // Note that no parameter variables are given

  //Exception handling classes
  class Overflow{};  //Thrown when the stack overflows
  class Underflow{}; //Thrown when the stack underflows

   queue();   // constructor to create an object 
   ~queue();  //destructor to destroy an object

   // PURPOSE: returns true if queue is empty, otherwise false
   bool isEmpty();

   // PURPOSE: returns true if queue is full, otherwise false
   bool isFull();

   // PURPOSE: if full, throws an exception Overflow
   // if not full, enters an element at the rear 
   // PRAMETER: provide the element to be added
   void add(el_t);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, removes the front element to give it back 
   // PRAMETER: provide a holder for the element removed (pass by ref)
   void remove(el_t&);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // PARAMETER: provide a holder for the element (pass by ref)
   void frontElem(el_t&);

   // PURPOSE: returns the current size to make it 
   // accessible to the client caller
   int getSize();

   // PURPOSE: display everything in the queue from front to rear
   //  enclosed in []
   // if empty, displays [ empty ]
   void displayAll();

   // PURPOSE: if empty, throws an exception Underflow
   //if queue has just 1 element, does nothing
   //if queue has more than 1 element, moves the front one to the rear
   void goToBack();


};           

