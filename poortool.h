/*
 *****************************************************************************
 * COPYRIGHT (C) STMicroelectronics 1997,1998,1999,2000,2001,2002
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
 * EMAIL: richard.onyett@st.com
 *
 * PURPOSE: 
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

typedef enum e_stack_policy {
  e_lifo = 0,
  e_fifo
} e_stack_policy_t;

typedef enum stack_exception {
  e_stackoverflow    = 100,
  e_stackunderflow   = 200,
  e_stackoutofmemory = 300
} stack_exception_t;


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
     Stack(int elements);        // ctor

    // Member functions
    int pop(void);               // pop off the stack
    int peek(void);              // Quick peek at the top of the stack
    void push(int element);      // push new element
    void StackDump(int num);     // Debug routines
    void StackEmpty(void);       // Clear stack
};

#endif // __STACK_H__

