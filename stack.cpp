/*
 *****************************************************************************
 * 
 * MODULE: C++ Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: Simple Stack Class implementation
 *
 * 
 * $Revision:$
 * $History: $
 *
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string.h>
#include "stack.h"
#include "trap.h"

using namespace std;

/*
******************************************************************************
Private Constants
******************************************************************************
*/

/*
******************************************************************************
Private Types
******************************************************************************
*/

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/

/*
******************************************************************************
Private Macros
******************************************************************************
*/

/*
******************************************************************************
Global variables
******************************************************************************
*/

/*
******************************************************************************
Exported Global variables
******************************************************************************
*/
  
/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

// Constructor time
Stack::Stack(int elements) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  StackCount = elements;
  StackMax = elements;
  StackTop = -1;
  StackPolicy = e_fifo;

  pStack = new int[elements];
  if ( pStack == NULL ) {
    Thrower(e_stackoutofmemory);
  }
}

// Destructor time
Stack::~Stack() {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called pStack = "  << pStack << endl;  
#endif

  StackCount = 0;
  StackTop = 0;

  delete [] pStack;
}

int Stack::pop(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: pop  called"  << endl;  
#endif

  if ( StackTop == -1) {
    cout << "Stack empty - Cannot pull" << endl;
    Thrower(e_stackunderflow);

    return 0;  /* This doesnt look right! */
  } 

  return pStack[StackTop--];
}

int Stack::peek(void) {
  cout << "<" << this << ">TRACE: peek  called"  << endl;  

  if ( StackTop == -1) {
    cout << "Stack empty - Cannot pull" << endl;
    Thrower(e_stackunderflow);
  }
  
  return pStack[StackTop];
}
    
void Stack::push(int element) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: push called"  << endl;  
  cout << "Top = " << StackTop << "StackMax = " << StackMax << endl;
#endif

  if ( (StackTop+1) == StackMax ) {
    cout << "Stack Overflow - Cannot push" << endl;
    Thrower(e_stackoverflow);
  } else {
    StackTop++;
    pStack[StackTop] = element;
  }
}

bool Stack::isEmpty(void) {
  bool stackEmpty = false;
  
  if (StackTop == -1) {
    stackEmpty = true;
  }

  return stackEmpty;
}
  
void Stack::StackEmpty(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: StackEmpty called"  << endl;  
#endif

  StackTop = -1;
}

void Stack::StackDump(int num) {
#if defined ( DEBUG_TRACE )
  cout << "StackDump: Size = " << StackMax << ", used = " << StackCount << ", Top = " << StackTop << endl;
#endif

  if ( pStack == NULL ) {
    cout << "StackDump: Stack is not created";
  }
  else {    
    for (int i=0; i < StackMax; i++) {
      cout << "Stack[" << i << "] = " << pStack[i];
      if ( i == StackTop ) {
        cout << "  <--- Stacktop";
      }
      cout << endl;
    }
  }
  cout << endl;
}

//
// Fin
//
