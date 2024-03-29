/**
 *	@file    calculator.cpp
 *	@brief   simple c++ command line calculator expresssion example
 *	@author  ronyett
 *	@note    operators +,-,/,*,(,),=
 *               opreands are integers
 *               Q(uit)  exits
 *      E.g
 *      > 2 + 3 =
 *      > (2 + 3) =
 *      > Q
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
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
Stack<int>  operands(3);
Stack<char> operators(10);

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
 * @brief     skip over any leading spaces
 * @fn        std::string IgnoreLeadingSpaces(const std::string &str) {
 * @param[in] str the command line
 * @return    trimmed string
 * @note
 */
std::string IgnoreLeadingSpaces(const std::string &str) {
  auto start = str.begin();

  while (start != str.end() && std::isspace(*start)) {
    start++;
  }
  
  return std::string(start,str.end());
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

/**
 * @brief      build up an integer from multiple characters
 * @fn         int BuildInteger(string commandline, int *position) {
 * @param[in]  commandline string 
 * @param[out] *position return the updated character position
 * @return     the integer
 * @note
 */
int BuildInteger(string commandline, int *position) {
  int count = *position;
  int intvalue = 0;
  
  while (count < (int)commandline.length() && isdigit(commandline[count])){
    intvalue = (intvalue * 10) + (commandline[count] -'0');
    count++;
  }
  
  *position = count;

  return intvalue;
}

int main ( void ) {
   cout << "Command line calculator" << endl;
   std::string commandline;
   std::locale loc;
   bool running= true;
   int ErrorCode = 0;
   int i = 0;
   
   while (running) {
     i = 0;
     cout << "> ";
     getline(cin, commandline);
     commandline = IgnoreLeadingSpaces(commandline);

     cout << "Len = " << commandline.length() << endl;
     
     while (i < (int)commandline.length() && ErrorCode == 0)
     {
       //       cout << "parse " << i << " = " << commandline[i] << endl;

       /*
        * test for integer
        */
       if (isdigit(commandline[i])) {
	 int value = 0;

	 cout << "pos = " << i;	 
	 value = BuildInteger(commandline, &i);
	 cout << ",value = " << value << " pos = " << i << endl;

	 try {
	   operands.push(value);
	 }catch (std::runtime_error &e) {
	   cout << "Exception: " << e.what() << endl;     
	 }
       } else if (commandline[i] == '(') {
	 operators.push(commandline[i]);
       } else if (commandline[i] == ')') {
	 while (!operators.isEmpty() && operators.peek() != '(') {
	   OperandExecute(operands.pop(), operands.pop(),operators.pop());
	 }
       }
               
       /*
        * halt the parser
        */
       if (std::tolower(commandline[0],loc) == 'q') {
         running = false;
       }

       /*
	* dump the Stack
	*/
       if (std::tolower(commandline[0],loc) == 'd') {
	 operands.StackDump(0);
	 operators.StackDump(0);
       }

       i++;
     }
   }
   
   exit(0);
}
