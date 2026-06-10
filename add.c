#include"header.h"

static int get_next_roll(struct st *ptr)
{
    int candidate=1;

    struct st *cur;
    int found;

    while(1)
    {
        found = 0;
        cur   = ptr;
        while(cur != 0)
        {
            if(cur->roll == candidate)
            {
                found = 1;
                break;
            }
            cur = cur->next;
        }
        if(!found)
            return candidate;
        candidate++;
    }
}

void stud_add(struct st **ptr)
{
    struct st *temp;
    temp = (struct st *)malloc(sizeof(struct st));
    temp->next = 0;

    printf("\n");
    printf("***SELECTED ADD STUDENT FROM THE MENU***\n");

    /* User inputs name and percentage only */
    printf("Enter name       : ");
    scanf(" %[^\n]",temp->name);
    printf("Enter percentage : ");
    scanf("%f",&temp->percentage);

    if(*ptr == 0)                        
    {
        temp->roll = 1;
        *ptr       = temp;
    }
    else                                 
    {
        struct st *last = *ptr;
        while(last->next != 0)          
            last = last->next;

        temp->roll = get_next_roll(*ptr); 
        last->next = temp;               
    }

    printf("STUDENT DATA ADDED SUCCESSFULLY..!!\n");

}
