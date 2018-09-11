/**
 *	@file    test_push.cpp
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

int test_push ( void )
{
  cout << "test_push - create <int> stack" << endl;

  Stack<int>   MyStack(5);

  MyStack.push(100);
  MyStack.push(200);
  MyStack.push(300);
  MyStack.push(700);

  MyStack.StackDump(0);

  cout << "test_push - create <char> stack" << endl;

  Stack<char>  MyCharStack(5);

  MyCharStack.push('A');
  MyCharStack.push('B');
  MyCharStack.push('C');
  MyCharStack.push('D');

  MyCharStack.StackDump(0);
  MyCharStack.StackEmpty();

  cout << "test_push - create <float> stack" << endl;

  Stack<float>  MyFloatStack(5);

  MyFloatStack.push(1.2);
  MyFloatStack.push(2.3);
  MyFloatStack.push(3.4);
  MyFloatStack.push(4.5);

  MyFloatStack.StackDump(0);
  MyFloatStack.StackEmpty();
#if 0
  cout << "test01c - pop <int> stack" << endl;
  MyStack.pop();
  MyStack.pop();
  MyStack.pop();
  MyStack.StackDump(0);
#endif
  cout << "test_push - Ends" << endl;

  return 0;
}

int test_run_push( void ) {
  int error_code = 0;

  try {
    error_code  = test_push();    /* Run one of the tests */
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
  
