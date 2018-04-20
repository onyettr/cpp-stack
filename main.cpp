/**
 *	@file    main.cpp
 *	@brief   simple c++ stack main harness
 *	@author
 *	@note	
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include "test.h"       /* Test harness entry point */

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
extern void poortool_init(void);

/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

/**
 * @function  int main(void)
 *
 * @brief     entry point
 *
 * @param[in] None
 *
 * @return    None
 *
 * @note      Entry point
 */
int main ( void )
{
  // Sign on
  cout << "C++ Examples Simple Stack Class" << endl; 

  test_run();  // Call out the test harness
  poortool_init();

}

//
// Fin
//
  
