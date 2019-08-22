/**
 *	@file    infixexp.cpp
 *	@brief   simple c++ infix expresssion example
 *	@author  ronyett
 *	@note    *,/,+, - are the expression operators
 *               integers are value
 *               E.g. 2 + 3
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string>
#include <stdlib.h>
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
Stack<int>  InFixStack(10);
Stack<char> operandStack(10);

/**
 * @brief     test for arithmetic op code
 * @fn        bool isOperator(char op) 
 * @param[in] op input operator
 * @return    true if op code found, false otherwise
 * @note
 */
bool isOperator(char op) {
  if (op == '+' || op == '-' || op == '/' || op == '*') {
    return true;
  }

  return false;
}

/**
 * @brief     Execute the op code
 * @fn        int OperandExecute(int value1, int value2, char operand) {
 * @param[in] value1 
 * @param[in] value2
 * @return    true if op code found, false otherwise
 * @note
 */
int OperandExecute(int value1, int value2, char operand) {
  int result;

  switch (operand) {
    case '+': {
      result = value1 + value2;
      break;
    }
    case '-': {
      result = value1 - value2;
      break;
    }
    case '/': {
      result = value1 / value2;
      break;
    }
    case '*': {
      result = value1 * value2;
      break;
    }
    default: break;
  }

  return result;
}

 int main ( void ) {
   cout << "infix Expression Example" << endl;
   string commandline;
   int numberCount = 0;
   int result;
   
   cout << "> ";
   getline(cin, commandline);   

   for (int i=0; i < (int)commandline.length(); i++) {
     if (isdigit(commandline[i])) {                          /* Its a digit(s)  */
       int intvalue = 0;

       while (i < (int)commandline.length() && isdigit(commandline[i])){
	 intvalue = (intvalue * 10) + (commandline[i] -'0');
	 i++;
       }

       InFixStack.push(intvalue);
       numberCount++;
     } else if (commandline[i] == '(' || commandline[i] == ')') {
       if (commandline[i] == ')') {
	 int value1 = InFixStack.pop();
	 int value2 = InFixStack.pop();
         char operand = operandStack.pop();

         result = OperandExecute(value1, value2, operand);
	 InFixStack.push(result);
	 break;
       }
     } else if (isOperator(commandline[i])) {                 /* Operand seen */
	 operandStack.push(commandline[i]);
     }
   }

   try {
     cout << "Result = " << (InFixStack.isEmpty() == false ? InFixStack.peek() : 0) << endl;
   }catch (std::runtime_error &e) {
     cout << "Exception: " << e.what() << endl;     
   }

   exit(0);
}
