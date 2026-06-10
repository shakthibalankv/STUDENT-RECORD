#include"header.h"

void del_all(struct st **ptr)
{
    char confirm;

    printf("\nAre you sure to delete all records? (Y/y to confirm): ");
    scanf(" %c", &confirm);

    switch(confirm|32)
    {
        case 'y':
        {
            struct st *cur = *ptr;
            struct st *tmp;

            while(cur != 0)
            {
                tmp = cur->next;
                free(cur);
                cur = tmp;
            }

            *ptr = 0;
            printf("All records deleted.\n");
            break;
        }

        default:
            printf("Deletion cancelled.\n");
            break;
    }
}
