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
  cout << "test01 <string> - create stack" << endl;

  Stack<string> MyStack(5);

  MyStack.StackDump(0);
  MyStack.push("test01-A");
  MyStack.push("test01-B");
  MyStack.push("test01-C");
  MyStack.push("test01-D");

  MyStack.StackDump(0);
  MyStack.StackEmpty();

  cout << "test01 - Thats it!" << endl;

  return 0;
}

static int string_test02 ( void )
{
  // Sign on
  cout << "test02 <string> - Stack overflow" << endl;

  Stack<string> overload(2);
  overload.push("test02-1");
  overload.push("test02-2");
  overload.push("test02-3");  // Fail here
  overload.StackDump(0);

  cout << "test02 - Thats it!" << endl;

  return 0;
}

static int string_test03 ( void )
{
  cout << "test03 <string> - Stack underflow" << endl;

  Stack<string> overload(2);
  overload.push("test03-1");
  overload.push("test03-2");

  overload.pop();
  overload.pop();
  overload.pop();       // Fail here

  overload.StackDump(0);
  overload.StackEmpty();

  return 0;
}

static int string_test04 ( void )
{
  cout << "test04 <string> - iSEmpty unit test" << endl;

  Stack<string> empty(3);

  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  empty.push("!");
  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  cout << "test04 - Thats it!" << endl;

  return 0;
}

static int string_test05 ( void )
{
  cout << "test05 <string> - peeking" << endl;

  Stack<string> peekme(3);
  cout << "Peeking with nothing there " << peekme.peek() << endl;

  peekme.push("test05-1");
  peekme.push("test05-2");
  peekme.push("test05-3");

  peekme.StackDump(0);
  cout << "Peeking with something there " << peekme.peek() << endl;

  return 0;
}

static int string_test06 ( void )
{
  cout << "test06 <string> - Stack Display" << endl;

  Stack<string> overload(5);

  overload.push("test06-1");
  overload.StackDump(0);
  overload.push("test06-22");
  overload.StackDump(0);
  overload.push("test06-3");
  overload.StackDump(0);
  overload.push("test06-4");
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
  cout << "test07 <string> - StackEmpty" << endl;

  Stack<string> S(2);

  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  
  S.push("test07-push01");
  S.push("test07-push02");
  S.StackDump(0);

  cout << "test07 - Setting stack to empty" << endl;
  S.StackEmpty();
  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  S.push("test07-next");
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
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }  
#endif

  return error_code;
}

//
// Fin
//
  
