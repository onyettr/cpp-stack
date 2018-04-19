/*
 *****************************************************************************
 * COPYRIGHT (C) STMicroelectronics 1997,1998,1999,2000,2001,2002
 * 
 * MODULE: C++ Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * NAME: Richard Onyett (STMicroelectronics,San Jose)
 * EMAIL: richard.onyett@st.com
 *
 * PURPOSE: 
 * Header file for simple String class
 * 
 * $Revision:$
 * $History: $
 *
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "sclass.h"

/*
******************************************************************************
Private Constants
******************************************************************************
*/
const int X_SIZE = 10;   // Max X size
const int Y_SIZE = 20;

#define NORMAL "\033[0m"
#define RED    "\033[1;32m"
#define YELLOW "\033[1;33m"
#define GREEN  "\033[1;32m"
#define CYAN   "\033[1;36m"
#define BLUE   "\033[1;34m"
#define WHITE  "\033[1;37m"

typedef enum e_colour {
  c_normal = 0,
  c_red, 
  c_green, 
  c_yellow, 
  c_blue, 
  c_cyan, 
  c_white
} e_colour_t;

class Screen
{
  private:
    int XAxis;                          // MAX X axis
    int YAxis;                          // MAX Y axis
    char bgColour;                      // Background Colour
    char fgColour;                      // Foreground Colour
    e_colour_t txtColour;               // Plotting colour
    StringClass cName;                  // Include other class
    char DisplayArea[X_SIZE][Y_SIZE];   // Dummy area to draw in
  public:
    ~Screen();                          // dtor
    Screen(char *);                     // ctors
    Screen(int x, int y, char c, char *);
    Screen(int x, int y, char *);
    Screen(char, char * );

  // Member functions
  void PrintScreenAttribs(void);
  void PlotPoint  (int x, int y, char p);
  void SetColour  (e_colour_t); 
  void Display    (void);
  void DisplayGrid(void);  
  void ClearScreen(char);
};

#endif

//
// Fin
//
