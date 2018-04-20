/**
 *	@file    stack.cpp
 *	@brief   simple c++ stack implementation
 *	@author
 *	@note	
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

/**
 * @function  Stack::Stack(int elements)
 *
 * @brief     Stack ctor
 *
 * @param[in] int elements - number of stack elements to allocate
 *
 * @return    None
 *
 * @note      Entry point
 */
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

/**
 * @function  Stack::~Stack
 *
 * @brief     Stack dtor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      dtor
 */
Stack::~Stack() {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called pStack = "  << pStack << endl;  
#endif

  StackCount = 0;
  StackTop = 0;

  delete [] pStack;
}

/**
 * @function  int Stack::pop(void) {
 *
 * @brief     Stack pop operation
 *
 * @param[in] none
 *
 * @return    Top of the stack (its an int)
 *
 * @note      
 */
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

/**
 * @function  int Stack::peek(void)
 *
 * @brief     Stack peek operation
 *
 * @param[in] none
 *
 * @return    return Top of the stack (its an int)
 *
 * @note      
 */
int Stack::peek(void) {

  cout << "<" << this << ">TRACE: peek  called"  << endl;  

  if ( StackTop == -1) {
    cout << "Stack empty - Cannot pull" << endl;
    Thrower(e_stackunderflow);
  }
  
  return pStack[StackTop];
}
    
/**
 * @function  void Stack::push(int element) {
 *
 * @brief     Stack push element
 *
 * @param[in] int element
 *
 * @return    none
 *
 * @note      
 */
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

/**
 * @function  bool Stack::isEmpty(void)
 *
 * @brief     Stack is stack empty?
 *
 * @param[in] none
 *
 * @return    TRUE is empty, FALSE otherwise
 *
 * @note      
 */
bool Stack::isEmpty(void) {
  bool stackEmpty = false;
  
  if (StackTop == -1) {
    stackEmpty = true;
  }

  return stackEmpty;
}
  
/**
 * @function  void Stack::StackEmpty(void) 
 *
 * @brief     Stack is set to empty
 *
 * @param[in] none
 *
 * @return    none
 *
 * @note      
 */
void Stack::StackEmpty(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: StackEmpty called"  << endl;  
#endif

  StackTop = -1;
}

/**
 * @function  void Stack::StackDump(int num) 
 *
 * @brief     Stack output
 *
 * @param[in] int num  - deprecated for now, will allow for number of entries to be output. 
 *
 * @return    none
 *
 * @note      
 */
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
