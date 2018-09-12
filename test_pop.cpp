/**
 *	@file    test_pop.cpp
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

static int test_pop ( void )
{
  cout << "*** test_pop - stack" << endl;

  Stack<int>   MyIntStack(5);

  MyIntStack.push(100);
  MyIntStack.push(200);
  MyIntStack.push(300);
  MyIntStack.push(700);

  cout << "\ttest_pop - <int> stack 700 = " << MyIntStack.pop() << endl;
  cout << "\ttest_pop - <int> stack 300 = " << MyIntStack.pop() << endl;
  cout << "\ttest_pop - <int> stack 200 = " << MyIntStack.pop() << endl;
  cout << "\ttest_pop - <int> stack 100 = " << MyIntStack.pop() << endl;
  MyIntStack.StackDump(0);
  
  Stack<char>  MyCharStack(5);

  MyCharStack.push('A');
  MyCharStack.push('B');
  MyCharStack.push('C');
  MyCharStack.push('D');

  cout << "\ttest_pop - <char> stack D = " << MyCharStack.pop() << endl;
  cout << "\ttest_pop - <char> stack C = " << MyCharStack.pop() << endl;
  cout << "\ttest_pop - <char> stack B = " << MyCharStack.pop() << endl;
  cout << "\ttest_pop - <char> stack A = " << MyCharStack.pop() << endl;
  MyCharStack.StackDump(0);

  Stack<float>  MyFloatStack(5);

  MyFloatStack.push(1.2);
  MyFloatStack.push(2.3);
  MyFloatStack.push(3.4);
  MyFloatStack.push(4.5);
  cout << "\ttest_pop - <float> stack 4.5 = " << MyFloatStack.pop() << endl;
  cout << "\ttest_pop - <float> stack 3.4 = " << MyFloatStack.pop() << endl;
  cout << "\ttest_pop - <float> stack 2.3 = " << MyFloatStack.pop() << endl;
  cout << "\ttest_pop - <float> stack 1.2 = " << MyFloatStack.pop() << endl;
  MyFloatStack.StackDump(0);

  return 0;
}

int test_run_pop( void ) {
  int error_code = 0;

  try {
    error_code  = test_pop();    /* Run one of the tests */
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
  
