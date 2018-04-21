/**
 *	@file    trap.cpp
 *	@brief   simple c++ stack trap / exception handler
 *	@author
 *	@note
 */
#include <iostream>
#include <string.h>
#include "trap.h"

using namespace std;

/**
 * @function  void Thrower(stack_exception_t exp)
 *
 * @brief     Thrower of exceptions
 *
 * @param[in] stack_exception_t exp - the exception type
 *
 * @return    None
 *
 * @note      if EXCEPTION is defined then it will "throw" a real exception
 */
void Thrower(stack_exception_t exp) {
#if defined (EXCEPTION)
  if (exp == e_stackoverflow ) {
    throw new StackOverFlowExcep();  
  } else if (exp == e_stackunderflow) {
    throw new StackUnderFlowExcep();  
  } else if (exp == e_stackoutofmemory) {
    throw new StackOutofMemoryExcep();  
  } else if (exp == e_stacksizeisnegative) {
    throw new StackSizeIsNegativeExcep();  
  }
#else
  cout << "ouch something bad went on = ";
  if (exp == e_stackoverflow ) {
    cout << "StackOverFlowExcep";
  } else if (exp == e_stackunderflow) {
    cout << "StackUnderFlowExcep";
  } else if (exp == e_stackoutofmemory) {
    cout << "StackOutofMemoryExcep()";
  } else if (exp == e_stacksizeisnegative) {
    cout << "StackSizeIsNegativeExcep()";
  }
  
  cout << endl;
#endif
}
