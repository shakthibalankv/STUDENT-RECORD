#include"header.h"

void stud_rev(struct st **ptr)
{
    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    struct st *start = *ptr;
    struct st *end   = *ptr;

    while(end->next != 0)
        end = end->next;

    
    while(start != end && start->next != end)
    {
        /* swap roll */
        int troll       = start->roll;
        start->roll     = end->roll;
        end->roll       = troll;

        /* swap name */
        char tname[100];
        strcpy(tname,       start->name);
        strcpy(start->name, end->name);
        strcpy(end->name,   tname);

        /* swap percentage */
        float tpct        = start->percentage;
        start->percentage = end->percentage;
        end->percentage   = tpct;

        start = start->next;

        struct st *temp = *ptr;
        while(temp->next != end)
            temp = temp->next;
        end = temp;
    }

    /* swap middle two elements if even number of nodes */
    if(start->next == end)
    {
        int troll       = start->roll;
        start->roll     = end->roll;
        end->roll       = troll;

        char tname[100];
        strcpy(tname,       start->name);
        strcpy(start->name, end->name);
        strcpy(end->name,   tname);

        float tpct        = start->percentage;
        start->percentage = end->percentage;
        end->percentage   = tpct;
    }

    printf("List reversed.\n");
    stud_show(*ptr);
}
