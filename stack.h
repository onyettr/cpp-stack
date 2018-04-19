/*!
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
 * PURPOSE: 
 * Header file for simple String class
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
#ifndef __STACK_H__
#define __STACK_H__

#include "trap.h"

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
typedef enum e_stack_policy {
  e_lifo = 0,
  e_fifo
} e_stack_policy_t;

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


class StackOutofMemoryExcep {
  public: 
    StackOutofMemoryExcep() {
      throw e_stackoutofmemory;
    }
};

class StackOverFlowExcep {
  public: 
    StackOverFlowExcep() {
      throw e_stackoverflow;
    }
};

class StackUnderFlowExcep {
  public: 
    StackUnderFlowExcep() {
      throw e_stackunderflow;
    }
};

/*!
 * Stack classs
 */ 
class Stack
{
   private:
     int  *pStack;               // Stack base
     int  StackCount;            // Stack Counter
     int  StackTop;              // Stack ptr
     int  StackMax;              // Stack Maximum size
     e_stack_policy_t StackPolicy; 
   public:
     ~Stack();                   // dtor

     /*! Constructor for the Stack */
     Stack(int elements=0);      // ctor

    // Member functions
    /*! \fn         int pop(void);          */
    int pop(void);               // pop off the stack
    /*! \fn         int peek(void);         */
    int peek(void);              // Quick peek at the top of the stack
    /*!
       \fn     void push(int element);      
       \param element Integer to be pushed to Stack
    */
    void push(int element);      // push new element
    void StackDump(int num);     // Debug routines
    void StackEmpty(void);       // Clear stack

    /*! \fn     bool isEmpty(void);  Test is Stack is empty or not  */
    bool isEmpty(void);          // Test if empty
};

#endif // __STACK_H__

