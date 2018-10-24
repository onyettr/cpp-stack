/**
 *	@file    poortool.c
 *	@brief   simple command line monitor
 *	@author
 *	@note	
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

/*
******************************************************************************
Private Constants
******************************************************************************
*/
#ifndef TESTTOOL
#define parse_t char
#endif
#ifndef BOOL
#define BOOL int
#endif

#define SEPARATORS       " \t\n\r,;"
#define HEAP_DEBUG       // Define to see the heap parition
#define TRUE             1
#define FALSE            0
#define INT_MEMSTART     0x80000140
#define INT_MEMEND       0x80002000

#define KEY_BACKSP       0x8   /* backspace */
#define KEY_UP           0x9   /* ctrl-i */
#define KEY_DOWN         0xF   /* ctrl-o */
#define KEY_RIGHT        0x10  /* ctrl-p */
#define KEY_LEFT         0x15  /* ctrl-u */
#define UNIX_KEY_DOWN    0xA   /* ctrl-o on Unix */
#define UNIX_KEY_BACKSP  0x7F  /* backspace on Unix */

/*
******************************************************************************
Private Types
*****************************************************************************
*/

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/
static int base = 10;                /* Radix for numbers         */
// Stack  *gStack = (Stack*)NULL;

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
static int pollkey(void);
static int io_read(unsigned char* prompt, char* buffer,long buflen);
static BOOL match(char *str1,const char *str2);
static void GetCommandLine(char *Buffer, int *cargc,char *cargv[]);
static BOOL Eval(char string[], long int *result);
static void tt_help (int argc, char *argv[]);
static BOOL GetCLI(void);
void poortool_Init(void);

/**
 * @fn        static int pollkey(void)
 *
 * @brief     test for a keypress
 *
 * @return    int
 *
 * @note      Waits for [ENTER] to be pressed
 */
static int pollkey(void)
{
  char key;
#if 0
  long int numkeys;

  numkeys = debugpollkey(&key);

  if ( numkeys == DEBUG_FN_REENTERED )
  {
    return 0;
  }

  if (numkeys > 0 )
  {
    return (int)key;
  }
#endif
  cin.get(key);   // Wait here for [ENTER]

  return key;
}

/**
 * @fn         static int io_read(uint8_t* prompt, char* buffer,long buflen)
 *
 * @brief      read input buffer from keyboard
 *
 * @param[in]  *prompt  - String containing the prompt
 * @param[out] *buffer  - Return string containing keypress entries
 * @param[in]  buflen   - length of return buffer
 *
 * @return    cnt of characters
 *
 * @note      Gathers the keypresses
 */
static int io_read(unsigned char* prompt, char* buffer,long buflen)
{
  int cnt = 0;

  cout << (char *)prompt;
  fflush(stdout);
  
  fgets(buffer, (size_t)buflen, stdin);

  return(cnt);
}

/**
 * @fn         static BOOL match(uint8_t *str1,const uint8_t *str2)
 *
 * @brief      match two strings
 *
 * @param[in]  *str1    - First string to compare agaisnt str2
 * @param[in]  *str2    - Compare to str1
 *
 * @return     TRUE if there is a match, FALSE if not
 *
 * @note       Compares str1 with str2
 */
static BOOL match(char *str1,const char *str2)
{
  int i;

  for (i=0; i < (int)strlen(str2); i++)
  {
    if (str1[i] != str2[i] )
    {
      return FALSE;
    }
  }

  return(!(strncmp(str1,str2, strlen(str1))));
}

/**
 * @fn         static void GetCommandLine(char *Buffer, int *cargc,char *cargv[])
 *
 * @brief      Get the command line from a string 
 *
 * @param[in]  *Buffer  - Raw command line to parse
 * @param[out] *cargc   - Return the number of arguments found
 * @param[out] *cargv[] - Each argument is placed into an entry
 *
 * @return     None
 *
 * @note       Takes a raw "command line" (buffer) and breaks it (tokenizes) into a set of arguments
 */
static void GetCommandLine(char *Buffer, int *cargc, char *cargv[])
{
  char *Token;
  char *bPtr;

  *cargc = 0;

  bPtr = Buffer;

  Token = strtok ( (char *)bPtr, SEPARATORS );   // Convert to arguments
  while ( Token != NULL )
  {
      cargv[*cargc] = (char *)(Token);    // Copy Tokenised data into Array
      (*cargc)++;
      Token = strtok ( NULL, SEPARATORS );
  }
}

/**
 * @fn         static BOOL Eval(char string[], long int *result)
 *
 * @brief      Convert the text string into dec, bin or hex.
 *
 * @param[in]  string  - Raw command line to convert
 * @param[out] *result - Returned numeric value
 *
 * @return     BOOL
 *
 * @note       Assumes base 16. Change to 10,2 for Dec/Bin, set the radix via the 'base' variable
 */
static BOOL Eval(char string[], long int *result)
{
  int i = 0;
  int Ptr;
  int offset = 0;

  *result = 0L;
  base = 10;  /* 10 assumes DEC, 16 Assumes HEX Mode */

  /* Skip any white space */
  for (Ptr=0; isspace(string[Ptr]); Ptr++);

  /* Validate input */
  switch ( string[Ptr] )
  {
     case '$':        /* HEX Mode */
     {
         i = Ptr+1;
         for (Ptr=0; isspace(string[Ptr]); Ptr++);
         Ptr++;

	 while ( string[Ptr] != '\0' )
         {
             if ( isxdigit(string[Ptr]) == 0 )
             {
                return FALSE;
	     }
             Ptr++;
	 }
	 break;
     }
  }

  /*
  -- Convert String into integer value
  */
  while ( string[i] != '\0' )
  {
      int temp;
      temp = string[i]-'0';
      if (string[i] >= 'A') temp -= ('A'-'9'-1);
      if (string[i] >= 'a') temp -= ('a' - 'A');
      if ((temp < base) && (temp >=0))
      {
          *result = (*result * base) + temp;
      }
      i++;
  }

  *result = *result + offset;

  return TRUE;
}

static void tt_push (int argc, char *argv[])
{
  long int data;
#if 0
  if ( argc == 1 ) {
    Eval ( argv[0], &data);
    cout << "PUSH " << data << endl;

    if ( gStack != NULL) {
      gStack->push(data);
    } else {
    	cout << "PUSH Fail no create called" << endl;
    }
  }
  else {
    cout << "PUSH what?" << endl;
  }
#endif
}

static void tt_create (int argc, char *argv[])
{
  long int size;

  if ( argc == 1 ) {
    Eval ( argv[0], &size);

    if ( gStack == NULL ) {
      gStack = new Stack(size);
      cout << "CREATE " << size << endl;      
    } else {
      cout << "DELETE current stack please!" << endl;
    }
  }
  else {
    cout << "create a stack: No size provided, didnt create" << endl;
  }
}

static void tt_delete (int argc, char *argv[])
{
  cout << "delete a stack" << endl;
  gStack->StackEmpty();

  delete[] gStack;
}

static void tt_dump   (int argc, char *argv[])
{
  if ( gStack != NULL ) {
    gStack->StackDump(0);
    cout << "dump a stack" << endl;
  }
}

static void tt_peek   (int argc, char *argv[])
{ 
  if ( gStack != NULL) {
    int result = gStack->peek();
    cout << "peek " << result << endl;
  }
}

static void tt_pop (int argc, char *argv[])
{
  if (gStack != NULL ) {
    long int handle = gStack->pop();
    cout << "POP " << handle << endl;
  }
}

/*
------------------------------------------------------------------------------
 Name   : static void fHelp(int argc, char *argv[])
 Purpose: Show all commands
 In     : int  argc
          char *argv[]
 Out    :
 Errors :
 Note   :
------------------------------------------------------------------------------
*/
static void tt_help(int argc, char *argv[])
{
  printf("**** PoorTool ****\n");
  printf("push <int>                push to stack                 \n");
  printf("pop                       pop  the stack                \n"); 
  printf("peek                      peek the stack                \n");
  printf("create                    create a stack - return handle\n");
  printf("delete <handle>           delete a stack                \n");
  printf("dump                      Show Stack                    \n");
  printf("exit                      Quit from Monitor             \n");
}

/*
------------------------------------------------------------------------------
 Name   : static BOOL GetCLI(void)
 Purpose: Command Line Processor 
 In     : None.
 Out    : None.
 Errors :
 Note   : This routine runs until the EXIT command is entered and it will go
          back into looking for the next keypress 
------------------------------------------------------------------------------
*/
static BOOL GetCLI(void)
{
  static char *Cargv[6];                /* Argument buffer for Commands */
  static int  Cargc = 0;                /* Argument count for Commands  */
  static char Buffer[30];               /* Buffer for parsing CLI       */
  BOOL Going = TRUE;                    /* Continue until EXIT          */

  while ( Going )
  {
    io_read((unsigned char *)"poortool>", Buffer, sizeof(Buffer));
    GetCommandLine(Buffer, &Cargc, Cargv);
    
    /*
     * Match up the commands
     */
    if      (match(Cargv[0],"help"       )) tt_help  ( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"push"       )) tt_push  ( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"peek"       )) tt_peek  ( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"pop"        )) tt_pop   ( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"create"     )) tt_create( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"delete"     )) tt_delete( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"dump"       )) tt_dump  ( Cargc-1, &Cargv[1]);
    else if (match(Cargv[0],"exit"       )) Going = FALSE;
    else printf ("??\n");
  }

  return FALSE;
}

/*
------------------------------------------------------------------------------
 Name   : void Poortool_Init(void)
 Purpose: Visible entry point for PoorTool.
 In     : 
 Out    : 
 Errors :
 Note   : Waits for keypress and enters into PoorTool world.
------------------------------------------------------------------------------
*/
void poortool_init(void)
{
  BOOL Going = true;

  printf("Press [ENTER] key for Poortool\n");
  
  while (Going)
  {
    int ip_char = 0;

   /*
    * Test for any keypress to enter the mode
    */
    while (ip_char == 0) {
      for (int i = 0; i < 10000; i++);
      ip_char = pollkey();
    }
    Going = GetCLI();                         /* Execute the Command Line */
  }
}

/*
 * Fin
 */
