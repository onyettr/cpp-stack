/**
 *	@file    test_diaplay.cpp
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

int test_display ( void )
{
  cout << "test_display - Stack Display" << endl;

  Stack<int> overload(5);

  overload.push(101);
  overload.StackDump(0);
  overload.push(202);
  overload.StackDump(0);
  overload.push(302);
  overload.StackDump(0);
  overload.push(402);
  overload.StackDump(0);

  overload.pop();
  overload.StackDump(0);
  overload.pop();
  overload.StackDump(0);

  return 0;
}

int test_run_display( void ) {
  int error_code = 0;

  try {
    error_code  = test_display();    /* Run one of the tests */
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
  
