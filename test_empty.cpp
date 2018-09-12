/**
 *	@file    test_empty.cpp
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


int test_empty ( void )
{
  cout << "*** test_empty - isEmpty unit test" << endl;

  Stack<int> empty(3);

  cout << "\tEmpty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  empty.push(111);
  cout << "\tEmpty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  Stack<int> S(2);

  S.StackDump(0);
  cout << "\tEmpty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  
  S.push(222);
  S.push(333); 
  S.StackDump(0);

  cout << "*** test_empty - Setting stack to empty" << endl;
  S.StackEmpty();
  S.StackDump(0);
  cout << "\tEmpty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  S.push(444);
  S.StackDump(0);
  cout << "\tEmpty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  

  cout << "*** test_empty - Ends" << endl;

  return 0;
}

int test_run_empty( void ) {
  int error_code = 0;

  try {
    error_code  = test_empty();    /* Run one of the tests */
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
  
