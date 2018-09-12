/**
 *	@file    test_underflow.cpp
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

int test_underflow ( void )
{
  cout << "*** test_underflow - Stack underflow" << endl;

  Stack<int> overload(2);
  overload.push(101);
  overload.push(202);

  cout << "test03, first  pop = 202 " << overload.pop() << endl;
  cout << "test03, second pop = 101 " << overload.pop() << endl;
  cout << "test03, third  pop = fail" << overload.pop() << endl;    

  overload.StackDump(0);
  overload.StackEmpty();

  return 0;
}

int test_run_underflow( void ) {
  int error_code = 0;

  try {
    error_code  = test_underflow();    /* Run one of the tests */
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
  
