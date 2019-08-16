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

int ParenthesisMatch(char *CheckString) {
  char *pString = CheckString;
  int Check = 1;
  
  while ( *pString != 0 ) {
    if (*pString == '(') {
      MyStack.push(*pString);
    } else if (!MyStack.isEmpty() && (*pString == ')') && MyStack.peek() == ')') {
      MyStack.pop();
    } else {
      Check = 0;
    }
    pString++;
  }

  if (Check && MyStack.isEmpty()) {
    return 0;
  } else {
    return 1;
  }
}

int main ( void ) {
  cout << "Parenthesis Checker" << endl;

  char Exp1[] = "()";
  cout << Exp1 << " " << (ParenthesisMatch(Exp1) == 1 ? "Balanced" : "Not Balanced") << endl;   
  
  char Exp2[] = "(())";
  cout << Exp2 << " " << (ParenthesisMatch(Exp2) == 1 ? "Balanced" : "Not Balanced") << endl;   

  char Exp5[] = "(()";
  cout << Exp5 << " " << (ParenthesisMatch(Exp5) == 1 ? "Balanced" : "Not Balanced") << endl;   
  
  char Exp3[] = "(((((())))))";
  cout << Exp3 << " " << (ParenthesisMatch(Exp3) == 1 ? "Balanced" : "Not Balanced") << endl;   

  char Exp4[] = "(";
  cout << Exp4 << " " << (ParenthesisMatch(Exp4) == 1 ? "Balanced" : "Not Balanced") << endl;   

  char Exp6[] = "(()))";
  cout << Exp6 << " " << (ParenthesisMatch(Exp6) == 1 ? "Balanced" : "Not Balanced") << endl;   

  char Exp7[] = "(((((((((()))";
  cout << Exp7 << " " << (ParenthesisMatch(Exp7) == 1 ? "Balanced" : "Not Balanced") << endl;   
  
  exit(0);
}
