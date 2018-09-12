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
 * @brief Stack class
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

      Stack(int elements=0);      

      // Member functions
      /**
       * @function     <T> pop(void);          
       * @brief        Pull top of stack and return
       * @param        none
       * @note         
       */
      T   pop(void);               // pop off the stack

      /** 
       * @function     <T> peek(void);         
       * @brief        "Peek" the top of the stack and return, do not "pop"
       * @param        none
       * @note         none
       */
      T   peek(void);              // Quick peek at the top of the stack

      /**
       * @function     void push(<T> element);      
       * @brief        Push element to stack
       * @param        const <T>& element to be pushed to Stack
       * @note         none
       */
      void push(const T&);         // push new element

      /**
       * @function     void StackDump(int num
       * @brief        Dump the Stack 
       * @param        int num
       */
      void StackDump(int num);     // Debug routines
  
      /**
       * @function     void StackEmpty(void)
       * @brief        Clear all of the stack, do not delete
       * @param        int num
       */
      void StackEmpty(void);       // Clear stack

      /**
       * @function   bool isEmpty(void);  
       * @brief      Test if Stack is empty or not  
       * @param      none
       */
      bool isEmpty(void);          // Test if empty

      /**
       * @function   int StackSize(void)
       * @brief      Return depth of the stack
       * @param      none
       */
      int StackSize(void) const;    // Size of stack
};

#include "stack.cpp"

#endif // __STACK_H__

