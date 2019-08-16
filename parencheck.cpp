/**
 *	@file    parencheck.cpp
 *	@brief   simple c++ parenthesis check using Stack
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
Stack<char> MyStack(10);

bool ParenthesisMatch(char *CheckString) {
  char *pString = CheckString;
  int Check = 1;
  int charpos = 0;
  
  while ( *pString != 0 ) {
    if (*pString == '(') {
      MyStack.push(*pString);
    } else if (!MyStack.isEmpty() && ((*pString == ')') && MyStack.peek() == '(')) {
      MyStack.pop();
    } else {
      Check = 0;
      break;
    }
    pString++;
    charpos++;
  }

  if (Check && MyStack.isEmpty()) {
    return true;
  } else {
    //    cout << charpos << endl;
    cout << endl;
    cout << CheckString << endl;
    for (int i=0; i < charpos-1; i++) {
      cout << " ";
    }
    cout << "^" << endl;
    
    return false;
  }
}

int main ( void ) {
  cout << "Parenthesis Checker" << endl;

  char Exp1[] = "()";
  cout << Exp1 << " " << ParenthesisMatch(Exp1) << endl;   
  
  char Exp2[] = "(())";
  cout << Exp2 << " " << ParenthesisMatch(Exp2) << endl;   

  char Exp3[] = "(((((())))))";
  cout << Exp3 << " " << ParenthesisMatch(Exp3) << endl;   

  char Exp4[] = "(";
  cout << Exp4 << " " << ParenthesisMatch(Exp4) << endl;   

  char Exp5[] = "(()";
  cout << Exp5 << " " << ParenthesisMatch(Exp5) << endl;   

  char Exp6[] = "(()))";
  cout << Exp6 << " " << ParenthesisMatch(Exp6)  << endl;   

  char Exp7[] = "(((((((()))";
  cout << Exp7 << " " << ParenthesisMatch(Exp7)  << endl;   

  char Exp8[] = "())))))))";
  cout << Exp8 << " " << ParenthesisMatch(Exp8)  << endl;   
  
  exit(0);
}
