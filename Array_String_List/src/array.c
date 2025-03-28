/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/***************************************************************************************************
*                         LOCAL TYPEDEFS (DEFINE, STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


/***************************************************************************************************
*                                      GLOBAL VARIABLES
***************************************************************************************************/

uint8_t array_exist = 0;
uint8_t number_of_element;

/***************************************************************************************************
*                                    DEFINITIONS
***************************************************************************************************/


/***************************************************************************************************
*                                   FUNCTIONS DEFINITIONS
***************************************************************************************************/


void swap(uint8_t *a, uint8_t *b)
{
    uint8_t c;
    c = *a;
    *a = *b;
    *b = c;
}

void Array_InputArray(uint8_t* arr)
{
    uint8_t count;
    uint8_t choise = 0;

    if(array_exist == 1)
    {
        printf("da co mang ton tai ban co muon tao mang moi an 1 de tao mang moi an 0 de huy thao tac: ");
        scanf("%d", &choise);
    }

    if(choise == 0)
    {
        printf("nhap so phan tu cua mang: ");
        scanf("%d", &number_of_element);

        for(count = 0; count < number_of_element; count++)
        {
            printf("nhap gia tri phan tu [%d]: ", count);
            scanf("%d", &arr[count]);
        }

        array_exist = 1;
        return arr;
    }
}

void Array_Print(uint8_t* arr)
{
    uint8_t count;
    for(count = 0; count < number_of_element; count++)
    {
        printf("gia tri phan tu [%d] = %d\n", count, arr[count]);
    }
}

void Array_SortAscending(uint8_t* arr)
{
    for (uint8_t i = 0; i < number_of_element - 1; i++)
    {
        for (uint8_t j = 0; j < number_of_element - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void Array_SortDescending(uint8_t* arr)
{
    for (uint8_t i = 0; i < number_of_element - 1; i++)
    {
        for (uint8_t j = 0; j < number_of_element - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int Array_FindElement(uint8_t* arr, uint8_t value)
{
    uint8_t count;
    for (count = 0; count < number_of_element; count++)
    {
        if (arr[count] == value)
        {
            printf("phan tu arr[%d] == %d\n", count, value);
            return 0;
        }
    }
    printf("khong tim thay phan tu\n");
    return 1;
}

void Array_ReplaceElement(uint8_t* arr, uint8_t index, uint8_t newValue)
{
    if (index < number_of_element)
    {
        arr[index] = newValue;
    }
    else
    {
        printf("Vi tri khong hop le!\n");
    }
}

void Array_DeleteElement(uint8_t* arr, uint8_t index)
{
    if (index < number_of_element)
    {
        arr[index] = 0;
    }
    else
    {
        printf("Vi tri khong hop le!\n");
    }
}

void Array_Reverse(uint8_t* arr)
{
    for (uint8_t i = 0, j = number_of_element - 1; i < j; i++, j--)
    {
        swap(&arr[i], &arr[j]);
    }
}
