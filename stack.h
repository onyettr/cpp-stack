/**
 *	@file    stack.h
 *	@brief   simple c++ stack implementation
 *	@author
 *	@note
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

/**
 * The <code>Stack</code> class
 * @tparam T type of stack 
 */ 
template <class T>
class Stack
{
   private:
      T   *pStack;                // Stack base
      int  StackCount = 0;        // Stack Counter
      int  StackTop;              // Stack ptr
      int  StackMax;              // Stack Maximum size
      e_stack_policy_t StackPolicy; 
   public:
      ~Stack();                   

      Stack(int size=0);      

      // Member functions
      /**
       * @fn           <T> pop(void);          
       * @brief        Pull top of stack and return
       * @note         
       */
      T   pop(void);               // pop off the stack

      /** 
       * @fn           <T> peek(void);         
       * @brief        "Peek" the top of the stack and return, do not "pop"
       * @note         none
       */
      T   peek(void);              // Quick peek at the top of the stack

      /**
       * @fn           void push(<T> element);      
       * @brief        Push element to stack
       * @param        element - to be pushed to Stack
       * @note         none
       */
      void push(const T& element); // push new element
  
      /**
       * @fn           void StackDump(int num)
       * @brief        Dump the Stack 
       * @param        num - of entries to be output
       */
      void StackDump(int num);     // Debug routines
  
      /**
       * @fn           void StackEmpty(void)
       * @brief        Clear all of the stack, do not delete
       */
      void StackEmpty(void);       // Clear stack

      /**
       * @fn         bool isEmpty(void);  
       * @brief      Test if Stack is empty or not  
       */
      bool isEmpty(void);          // Test if empty

      /**
       * @fn         int StackSize(void)
       * @brief      Return depth of the stack
       */
      int StackSize(void) const;    // Size of stack
};

#include "stack.cpp"

#endif // __STACK_H__

