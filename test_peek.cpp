/**
 *	@file    test_peek.cpp
 *	@brief   simple c++ stack test harness
 *	@author  ronyett
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

/**
 * @fn       static int test_peek ( void )
 *
 * @brief    Stack peek test
 * @note     
 */
static int test_peek ( void )
{
  Stack<int> peekme(3);  

  cout << "*** test_peek - peeking" << endl;

  peekme.push(2001);
  peekme.push(2002);
  peekme.push(2003);

  peekme.StackDump(0);
  cout << "\tPeeking with something there 2003 = " << peekme.peek() << endl;

  Stack<int> peekmeFail(1);    
  cout << "\tPeeking with nothing there " << peekmeFail.peek() << endl;
  
  return 0;
}

/**
 * @fn       int test_run_peek( void ) {
 *
 * @brief    run the test harness for peek
 * @note     
 */
int test_run_peek( void ) {
  int error_code = 0;

  try {
    error_code  = test_peek();    /* Run one of the tests */
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
  
