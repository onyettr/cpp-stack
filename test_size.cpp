/**
 *	@file    test_size.cpp
 *	@brief   simple c++ stack test harness
 *	@author
 *	@note
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include "stack.h"
#include "test.h"

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

int test_size ( void )
{
  cout << "*** test_size" << endl;

  Stack<int>   MyStack(5);

  MyStack.push(400);
  MyStack.push(500);
  MyStack.push(600);
  MyStack.push(700);

  MyStack.StackDump(0);

  cout << "\ttest_size:           " << MyStack.StackSize() << endl;

  cout << "\ttest_size: " << MyStack.pop() << " after pop #1 = " << MyStack.StackSize() << endl;  
  cout << "\ttest_size: " << MyStack.pop() << " after pop #2 = " << MyStack.StackSize() << endl;  
  cout << "\ttest_size: " << MyStack.pop() << " after pop #3 = " << MyStack.StackSize() << endl;
  cout << "\ttest_size: " << MyStack.pop() << " after pop #4 = " << MyStack.StackSize() << endl;

  /*
   * Test will fail here as we are empty
   */
  cout << "\ttest_size: " << MyStack.pop() << " after pop #5 = " << MyStack.StackSize() << endl;

 return 0;
}

int test_run_size( void ) {
  int error_code = 0;

  try {
    error_code  = test_size();    /* Run one of the tests */
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  return error_code;
}

//
// Fin
//
  
