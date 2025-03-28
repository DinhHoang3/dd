#ifndef _LIST_H_
#define _LIST_H_

/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/


/***************************************************************************************************
*                          TYPEDEFS (DEFINE, STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef struct DIEM 
{
    uint8_t toan;
    uint8_t ly;
    uint8_t hoa;
}diem;

typedef struct NODE node;
struct NODE
{
    node *next;
    diem data;
};


/***************************************************************************************************
*                                      GLOBAL VARIABLES
***************************************************************************************************/


/***************************************************************************************************
*                                    DEFINITIONS
***************************************************************************************************/


/***************************************************************************************************
*                                   PROTOTYPE
***************************************************************************************************/

node* List_CreateNode(uint8_t toan, uint8_t ly, uint8_t hoa);
void List_AddHead(node** head, uint8_t toan, uint8_t ly, uint8_t hoa);
void List_AddTail(node** head, uint8_t toan, uint8_t ly, uint8_t hoa);
void List_AddAt(node** head, uint8_t toan, uint8_t ly, uint8_t hoa, int position);
void List_DeleteAt(node** head, int position);
void List_PrintList(node* head);
void List_Free(node** head);
void menu();

#endif // _LIST_H_
