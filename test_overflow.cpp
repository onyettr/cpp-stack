/**
 *	@file    test_overflow.cpp
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

int test_overflow ( void )
{
  // Sign on
  cout << "test_overflow - Stack overflow" << endl;

  Stack<int> overload(2);
  overload.push(100);
  overload.push(200);
  overload.push(300);  // Fail here

  overload.StackDump(0);

  return 0;
}

int test_run_overflow( void ) {
  int error_code = 0;

  try {
    error_code  = test_overflow();    /* Run one of the tests */
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
  
