#ifndef _MAIN_H_
#define _MAIN_H_

/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.h"
#include "string.h"
#include "list.h"


/***************************************************************************************************
*                         LOCAL TYPEDEFS (DEFINE, STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


/***************************************************************************************************
*                                      GLOBAL VARIABLES
***************************************************************************************************/


/***************************************************************************************************
*                                    DEFINITIONS
***************************************************************************************************/

#define ARRAY           0
#define STRING          1
#define LINKER_LIST     2

#define MODE    LINKER_LIST

/***************************************************************************************************
*                                   PROTOTYPE
***************************************************************************************************/

void menu();
uint8_t* choiceString();


#endif // _MAIN_H_
