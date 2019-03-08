//=========================================================
//HW#: HW1P1 queue
//Your name: David Garcia
//Complier:  g++
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

//PURPOSE: Constructor intializes count and front to 0 and rear to -1 to begin with
queue::queue()
{
  count = front = 0; //Indicate stack is empty and set front to first slot in array
  rear = -1; //Start rear not pointing to the first slot
}

//PURPOSE: Destructor doesn't have to do anything beacuse it's a static array
queue::~queue()
{//nothing to do
}

//PURPOSE: Checks count and returns true if  empty, otherwise false.
//         Queue is empty if count equals zero.
bool queue::isEmpty()
{
  //If count is 0 there is nothing in the queue, return true
  if(count == 0) return true;

  //Count is not zero, there are contents int the queue, return false
  else return false;
}

// PURPOSE: Checks count and returns true if full, otherwise false.
//          Queue is full when count equals MAX_SIZE
bool queue::isFull()
{
  //If count equals MAX_SIZE then queue is full, return true
  if(count == MAX_SIZE) return true;

  //Queue has some contents inside, return false
  else return false;
}

// PURPOSE: Calls isFull, throws an exception Overflow
// if true, otherwise enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  //If queue is full you can't add more elements, throw Overflow
  if(isFull()) throw Overflow();
  
  //There is space in queue, add new element to rear
  else
    {
      rear = (rear+1) % MAX_SIZE; //Increment rear, use mod to make sure it wraps
                                  //around if it reaches the end of the array
      el[rear] = newElem;         //Add contnet of newElem to slot in array
      count++;                    //Increment queue counter
    }
}

// PURPOSE: Calls isEmpty, throw Underflow
// if true, removes the front element and passes it by reference
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  //If queue is empty, throw Underflow  
  if(isEmpty()) throw Underflow();

  //There are one or more contents in the queue. Remove the 
  //front element, increment front, and decrement queue counter.
  else
    {
      removedElem = el[front]; //Remove front element, store in removedElem
      front = (front+1) % MAX_SIZE; //Use mod to increment front so it wraps around
      count--; //Decrement queue counter
    }
}

// PURPOSE: Calls isEmpty, throws an exception Underflow
// if true, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  //If queue is empty throw Underflow
  if(isEmpty()) throw Underflow();
  
  //There is at least on element in the queue return the front 
  //element by storing a copy in theElem 
  else theElem = el[front];
}

// PURPOSE: Returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count; //Pass count, by value
}

// PURPOSE: Display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
//ALGORITHM: Display the front item, start a for loop and initialize an integer counter (i)
//           to 1 plus the front, using mod equation in case it needs to wrap around, and
//           increment the counter, using mod equation, stopping at the rear slott. Use
//           same counter (i) to display the contents onto the screen.
void queue::displayAll()
{
  //If empty, display empty on screen 
  if(isEmpty()) cout << " [ empty ] \n";

  // There are one or more elements in queue, display all of them
  else
    {
      cout << " [ " << el[front] << " "; //Display front element before loop
      //Make loop for going through queue, keep in mind wrapping around
      for(int i = ((front+1)%MAX_SIZE); i != ((rear+1)%MAX_SIZE); i = (i+1)%MAX_SIZE) 
	cout << el[i] << " "; //Display the element in slot pointed by cointer (i)
      cout << "]\n";
    }
}

// PURPOSE: Calls empty, throws an exception Underflow if true.
//If queue has just 1 element, does nothing.
//if queue has more than 1 element, moves the front element to the rear by
//doing remove followed by add.
void queue::goToBack()
{
  //If queue is empty, throw an Underflow
  if(isEmpty()) throw Underflow();
  
  //There is at least one element inside queue
  else
    {
      el_t temp; //Variable to store element removed and later added
      remove(temp); //Remove front element and store inside temp varible
      add(temp); //Add the recently removed element stored in temp and add it to the queue
    }
}





