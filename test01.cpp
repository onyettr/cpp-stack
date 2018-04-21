/**
 *	@file    test01.cpp
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

int test01 ( void )
{
  cout << "test01 - create stack" << endl;

  Stack MyStack(5);

  MyStack.StackDump(0);
  MyStack.push(100);
  MyStack.push(200);
  MyStack.push(300);
  MyStack.push(700);

  MyStack.StackDump(0);
  MyStack.StackEmpty();

  cout << "test01 - Thats it!" << endl;

  return 0;
}

int test02 ( void )
{
  // Sign on
  cout << "test02 - Stack overflow" << endl;

  Stack overload(2);
  overload.push(100);
  overload.push(200);
  overload.push(300);  // Fail here
  overload.StackDump(0);

  cout << "test02 - Thats it!" << endl;

  return 0;
}

int test03 ( void )
{
  cout << "test03 - Stack underflow" << endl;

  Stack overload(2);
  overload.push(101);
  overload.push(202);

  overload.pop();
  overload.pop();
  overload.pop();       // Fail here

  overload.StackDump(0);
  overload.StackEmpty();

  return 0;
}

int test04 ( void )
{
  cout << "test04 - iSEmpty unit test" << endl;

  Stack empty(3);

  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  empty.push(111);
  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  cout << "test04 - Thats it!" << endl;

  return 0;
}

int test05 ( void )
{
  cout << "test05 - peeking" << endl;

  Stack peekme(3);
  cout << "Peeking with nothing there " << peekme.peek() << endl;

  peekme.push(2001);
  peekme.push(2002);
  peekme.push(2003);

  peekme.StackDump(0);
  cout << "Peeking with something there " << peekme.peek() << endl;

  return 0;
}

int test06 ( void )
{
  cout << "test06 - Stack Display" << endl;

  Stack overload(5);

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

  cout << "test06 - Thats it!" << endl;

  return 0;
}

int test07 ( void )
{
  cout << "test07 - StackEmpty" << endl;

  Stack S(2);

  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  
  S.push(222);
  S.push(333); 
  S.StackDump(0);

  cout << "test07 - Setting stack to empty" << endl;
  S.StackEmpty();
  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  
  S.push(444);
  S.StackDump(0);
  cout << "Empty = " << (S.isEmpty() == true ? "TRUE" : "FALSE") << endl;  

  cout << "test07 - Thats it!" << endl;

  return 0;
}

int test_run ( void ) {
  int error_code = 0;

#if defined(EXCEPTION)
  try {
#endif
    error_code = test01();    /* Run one of the tests */
    error_code |= test02();    /* Run one of the tests */
    error_code |= test03();    /* Run one of the tests */
    error_code |= test04();    /* Run one of the tests */
    error_code |= test05();    /* Run one of the tests */
    error_code |= test06();    /* Run one of the tests */
    error_code |= test07();    /* Run one of the tests */
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
  
