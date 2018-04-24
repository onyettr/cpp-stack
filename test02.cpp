/**
 *	@file    test02.cpp
 *	@brief   simple c++ stack test harness, this time with strings
 *	@author
 *	@note
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string.h>
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

static int string_test01 ( void )
{
  cout << "test01 - create stack" << endl;

  Stack<string> MyStack(5);

  MyStack.StackDump(0);
  MyStack.push("A");
  MyStack.push("B");
  MyStack.push("C");
  MyStack.push("D");

  MyStack.StackDump(0);
  MyStack.StackEmpty();

  cout << "test01 - Thats it!" << endl;

  return 0;
}

static int string_test02 ( void )
{
  // Sign on
  cout << "test02 - Stack overflow" << endl;

  Stack<string> overload(2);
  overload.push("1");
  overload.push("2");
  overload.push("f");  // Fail here
  overload.StackDump(0);

  cout << "test02 - Thats it!" << endl;

  return 0;
}

static int string_test03 ( void )
{
  cout << "test03 - Stack underflow" << endl;

  Stack<string> overload(2);
  overload.push("a");
  overload.push("b");

  overload.pop();
  overload.pop();
  overload.pop();       // Fail here

  overload.StackDump(0);
  overload.StackEmpty();

  return 0;
}

static int string_test04 ( void )
{
  cout << "test04 - iSEmpty unit test" << endl;

  Stack<string> empty(3);

  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  empty.push("!");
  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  cout << "test04 - Thats it!" << endl;

  return 0;
}

static int string_test05 ( void )
{
  cout << "test05 - peeking" << endl;

  Stack<string> peekme(3);
  cout << "Peeking with nothing there " << peekme.peek() << endl;

  peekme.push("1");
  peekme.push("2");
  peekme.push("3");

  peekme.StackDump(0);
  cout << "Peeking with something there " << peekme.peek() << endl;

  return 0;
}

static int string_test06 ( void )
{
  cout << "test06 - Stack Display" << endl;

  Stack<string> overload(5);

  overload.push("1");
  overload.StackDump(0);
  overload.push("2");
  overload.StackDump(0);
  overload.push("3");
  overload.StackDump(0);
  overload.push("4");
  overload.StackDump(0);

  overload.pop();
  overload.StackDump(0);
  overload.pop();
  overload.StackDump(0);

  cout << "test06 - Thats it!" << endl;

  return 0;
}

static int string_test07 ( void )
{
  cout << "test07 - StackEmpty" << endl;

  Stack<string> S(2);

  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  
  S.push("h");
  S.push("e");
  S.StackDump(0);

  cout << "test07 - Setting stack to empty" << endl;
  S.StackEmpty();
  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  S.push("next");
  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  

  cout << "test07 - Thats it!" << endl;

  return 0;
}

int test_run_strings( void ) {
  int error_code = 0;

#if defined(EXCEPTION)
  try {
#endif
    error_code  = string_test01();    /* Run one of the tests */
    error_code |= string_test02();    /* Run one of the tests */
    error_code |= string_test03();    /* Run one of the tests */
    error_code |= string_test04();    /* Run one of the tests */
    error_code |= string_test05();    /* Run one of the tests */
    error_code |= string_test06();    /* Run one of the tests */
    error_code |= string_test07();    /* Run one of the tests */
#if defined(EXCEPTION)
    } catch(int e) {
    cout << "ouch something bad went on = " << e << endl;
  }
#endif

  return error_code;
}

//
// Fin
//
  
