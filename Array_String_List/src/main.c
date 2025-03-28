/***************************************************************************************************
*                                        INCLUDE FILES
***************************************************************************************************/
#include "main.h"

/***************************************************************************************************
*                         LOCAL TYPEDEFS (DEFINE, STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


/***************************************************************************************************
*                                      GLOBAL VARIABLES
***************************************************************************************************/
uint8_t arr[100];

/***************************************************************************************************
*                                    DEFINITIONS
***************************************************************************************************/


/***************************************************************************************************
*                                   FUNCTIONS DEFINITIONS
***************************************************************************************************/



#if(MODE == ARRAY)

int main()
{
    uint8_t choice;
    uint8_t value;
    uint8_t index;
    do 
    {
        menu();
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                Array_InputArray(arr);
                break;
            case 2:
                Array_Print(arr);
                break;
            case 3:
                Array_SortAscending(arr);
                break;
            case 4:
                Array_SortDescending(arr);
                break;
            case 5:
                printf("Gia tri muon tim kiem: ");
                scanf("%d", &value);
                Array_FindElement(arr, value);
                break;
            case 6:
                printf("Gia tri muon thay the: ");
                scanf("%d", &value);
                printf("Vi tri muon thay the: ");
                scanf("%d", &index);
                Array_ReplaceElement(arr, index, value);
                break;
            case 7:
                printf("Vi tri muon xoa: ");
                scanf("%d", &index);
                Array_DeleteElement(arr, index);
                break;
            case 8:
                Array_Reverse(arr);
                break;
            case 9:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ, vui lòng thử lại.\n");
                break;
        }
    } while (choice != 9);
}

void menu() 
{
    printf("\n===== MENU =====\n");
    printf("1. Tao Mang \n");
    printf("2. In Mang \n");
    printf("3. Sap xep tang dan \n");
    printf("4. Sap xep giam dan \n");
    printf("5. Tim kiem trong mang \n");
    printf("6. Thay the trong mang \n");
    printf("7. Xoa phan tu trong mang \n");
    printf("8. Dao nguoc mang \n");
    printf("9. Thoat \n");
    printf("Lựa chọn của bạn: ");
}

#elif(MODE == STRING)

uint8_t string_src[MAX_LENGTH]    = "HoangDC3@fpt.com";
uint8_t string_dest[MAX_LENGTH]   = "HaiNV233@fpt.com";
uint8_t string_empty[MAX_LENGTH];

int main()
{

    uint8_t choice;
    uint8_t *string_ptr;
    uint8_t value;
    uint8_t index;
    do 
    {
        menu();
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Ket qua so sanh: %d\n", String_Compare(string_src, string_dest));
                break;
            case 2:
                String_Connect(string_src, string_dest);
                printf("Chuoi sau khi noi: ");
                String_Print(string_dest);
                break;
            case 3:
                String_Copy(string_src, string_empty);
                printf("Chuoi sau khi sao chep: ");
                String_Print(string_empty);
                break;
            case 4:
                string_ptr = choiceString();
                String_ToUpper(string_src);
                printf("Chuoi in hoa: ");
                String_Print(string_src);
                break;
            case 5:
                string_ptr = choiceString();
                String_ToLower(string_ptr);
                printf("Chuoi in thuong: ");
                String_Print(string_ptr);
                break;
            case 6:
                string_ptr = choiceString();
                printf("Chuoi hien tai: ");
                String_Print(string_ptr);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
                break;
        }
    } while (choice != 7);
}

void menu()
{
    printf("\n===== MENU =====\n");
    printf("1. So sanh chuoi\n");
    printf("2. Noi chuoi\n");
    printf("3. Sao chep chuoi\n");
    printf("4. In hoa chuoi\n");
    printf("5. In thuong chuoi\n");
    printf("6. In chuoi\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}


uint8_t* choiceString()
{
    uint8_t value;
    printf("chon chuoi muon thao tac: \n");
    printf("1 string_src \n2 string_dest \n3 string_empty \nLua chon: ");
    scanf("%d", &value);
    if(value == 1)
    {
        return string_src;
    }
    else if (value == 2)
    {
        return string_dest;
    }
    else
    {
        return string_empty;
    }
} 

#else

int main()
{
    uint8_t choice;
    uint8_t value;
    uint8_t index;
    uint8_t toan, ly, hoa;
    uint8_t position;    
    node* head = NULL;
    do 
    {
        menu();
        scanf("%hhu", &choice);
        switch (choice) 
        {
            case 1:
                printf("Nhap diem Toan, Ly, Hoa: ");
                scanf("%hhu %hhu %hhu", &toan, &ly, &hoa);
                List_AddHead(&head, toan, ly, hoa);
                break;
            case 2:
                printf("Nhap diem Toan, Ly, Hoa: ");
                scanf("%hhu %hhu %hhu", &toan, &ly, &hoa);
                List_AddTail(&head, toan, ly, hoa);
                break;
            case 3:
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                printf("Nhap diem Toan, Ly, Hoa: ");
                scanf("%hhu %hhu %hhu", &toan, &ly, &hoa);
                List_AddAt(&head, toan, ly, hoa, position);
                break;
            case 4:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                List_DeleteAt(&head, position);
                break;
            case 5:
                printf("Danh sach diem:\n");
                List_PrintList(head);
                break;
            case 6:
                printf("Giai phong danh sach va thoat.\n");
                List_Free(&head);
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
                break;
        }
    } while (choice != 6);
}

void menu()
{
    printf("\n===== MENU =====\n");
    printf("1. Them vao dau danh sach\n");
    printf("2. Them vao cuoi danh sach\n");
    printf("3. Them vao vi tri bat ky\n");
    printf("4. Xoa node theo vi tri\n");
    printf("5. In danh sach\n");
    printf("6. Giai phong danh sach va thoat\n");
    printf("Lua chon cua ban: ");
}

#endif

