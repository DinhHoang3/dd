/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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


/***************************************************************************************************
*                                   FUNCTIONS DEFINITIONS
***************************************************************************************************/

node* List_CreateNode(uint8_t toan, uint8_t ly, uint8_t hoa) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode) 
    {
        newNode->data.toan = toan;
        newNode->data.ly = ly;
        newNode->data.hoa = hoa;
        newNode->next = NULL;
    }
    return newNode;
}

void List_AddHead(node** head, uint8_t toan, uint8_t ly, uint8_t hoa) {
    node* newNode = List_CreateNode(toan, ly, hoa);
    if (newNode) 
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void List_AddTail(node** head, uint8_t toan, uint8_t ly, uint8_t hoa) {
    node* newNode = List_CreateNode(toan, ly, hoa);
    if (!*head) 
    {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp->next) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void List_AddAt(node** head, uint8_t toan, uint8_t ly, uint8_t hoa, int position) {
    if (position == 0) 
    {
        List_AddHead(head, toan, ly, hoa);
        return;
    }
    node* newNode = List_CreateNode(toan, ly, hoa);
    node* temp = *head;
    for (int i = 0; temp && i < position - 1; i++) 
    {
        temp = temp->next;
    }
    if (temp) 
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void List_DeleteAt(node** head, int position) {
    if (!*head) return;
    node* temp = *head;
    if (position == 0) 
    {
        *head = temp->next;
        free(temp);
        return;
    }
    node* prev = NULL;
    for (int i = 0; temp && i < position; i++) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp) 
    {
        prev->next = temp->next;
        free(temp);
    }
}

void List_PrintList(node* head) {
    while (head) 
    {
        printf("Toan: %d, Ly: %d, Hoa: %d\n", head->data.toan, head->data.ly, head->data.hoa);
        head = head->next;
    }
}

void List_Free(node** head) {
    node* temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


