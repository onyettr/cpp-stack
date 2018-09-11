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
  cout << "test01a - create <int> stack" << endl;

  Stack<int>   MyStack(5);

  MyStack.push(100);
  MyStack.push(200);
  MyStack.push(300);
  MyStack.push(700);

  MyStack.StackDump(0);

  cout << "test01b - create <char> stack" << endl;

  Stack<char>  MyCharStack(5);

  MyCharStack.push('A');
  MyCharStack.push('B');
  MyCharStack.push('C');
  MyCharStack.push('D');

  MyCharStack.StackDump(0);
  MyCharStack.StackEmpty();

  cout << "test01c - create <float> stack" << endl;

  Stack<float>  MyFloatStack(5);

  MyFloatStack.push(1.2);
  MyFloatStack.push(2.3);
  MyFloatStack.push(3.4);
  MyFloatStack.push(4.5);

  MyFloatStack.StackDump(0);
  MyFloatStack.StackEmpty();

  cout << "test01c - pop <int> stack" << endl;
  MyStack.pop();
  MyStack.pop();
  MyStack.pop();
  MyStack.StackDump(0);

  cout << "test01 - Thats it!" << endl;

  return 0;
}

int test04 ( void )
{
  cout << "test04 - iSEmpty unit test" << endl;

  Stack<int> empty(3);

  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;

  empty.push(111);
  cout << "Empty = " << (empty.isEmpty() == true ? "TRUE" : "FALSE") << endl;


  return 0;
}

int test05 ( void )
{
  cout << "test05 - peeking" << endl;

  Stack<int> peekme(3);
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

  cout << "test06 - Thats it!" << endl;

  return 0;
}

int test07 ( void )
{
  cout << "test07 - StackEmpty" << endl;

  Stack<int> S(2);

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

int test_run_integer( void ) {
  int error_code = 0;

#if defined(EXCEPTION)
  try {
#endif
    error_code  = test01();    /* Run one of the tests */
    error_code |= test02();    /* Run one of the tests */
    error_code |= test03();    /* Run one of the tests */
    error_code |= test04();    /* Run one of the tests */
    error_code |= test05();    /* Run one of the tests */
    error_code |= test06();    /* Run one of the tests */
    error_code |= test07();    /* Run one of the tests */
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
  
