/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/***************************************************************************************************
*                         LOCAL TYPEDEFS (DEFINE, STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


/***************************************************************************************************
*                                      GLOBAL VARIABLES
***************************************************************************************************/


/***************************************************************************************************
*                                    DEFINITIONS
***************************************************************************************************/


/***************************************************************************************************
*                                   FUNCTIONS DEFINITIONS
***************************************************************************************************/

int String_Compare(uint8_t* str1, uint8_t* str2)
{
    uint8_t count = 0;
    if(sizeof(str1) != sizeof(str2))
    {
        return 0;
    }
    for(count = 0; count < sizeof(str1); count++)\
    {
        if(str1[count] != str2[count])
        {
           return 0;
        }
    }
    return 1;
}

int String_Length(uint8_t* str)
{
    uint8_t count = 0;
    while(str[count] != '\0')
    {
        count++;
    }
    return count;
}

void String_ToUpper(uint8_t* str)
{
    uint8_t count = 0;
    while(str[count] != '\0')
    {
        if(str[count] >= 0x61 && str[count] <= 0x7A)
        {
            str[count] = str[count] - 0x20;
        }
        count++;
    }
}

void String_ToLower(uint8_t* str)
{
    uint8_t count = 0;
    while(str[count] != '\0')
    {
        if(str[count] >= 0x41 && str[count] <= 0x5A)
        {
            str[count] = str[count] + 0x20;
        }
        count++;
    }
}

int String_Connect(uint8_t* src, uint8_t* dest)
{
    uint8_t count = 0;
    uint8_t lenght_src = String_Length(src);
    uint8_t lenght_dest = String_Length(dest);
    if((lenght_src + lenght_dest) < MAX_LENGTH)
    {
        while(src[count] != '\0')
        {
            dest[count + lenght_dest] = src[count];
            count++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void String_Copy(uint8_t* src, uint8_t* dest)
{
    uint8_t count = 0;
    while(src[count] != '\0')
    {
        dest[count] = src[count];
        count++;
    }
}

void String_Print(uint8_t* str)
{
    uint8_t count = 0;
    while(str[count] != '\0')
    {
        printf("%c", str[count]);
        count++;
    }
}