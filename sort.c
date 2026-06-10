#include"header.h"

void stud_sort(struct st **ptr)
{
    char choice;

    printf("+-------------------------------------+\n");
    printf("|    N/n  :  Sort with Name           |\n");
    printf("|    P/p  :  Sort with percentage     |\n");
    printf("+-------------------------------------+\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch(choice | 32)
    {
        case 'n':
            sort_by_name(ptr);
            break;

        case 'p':
            sort_by_percentage(ptr);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}

void sort_by_name(struct st **ptr)
{
    struct st *i;
    struct st *j;
    int   troll;
    char  tname[100];
    float tpct;

    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    for(i = *ptr; i != 0; i = i->next)
    {
        for(j = i->next; j != 0; j = j->next)
        {
            if(strcmp(i->name, j->name) > 0)
            {
                /* swap data */
                troll      = i->roll;
                strcpy(tname, i->name);
                tpct       = i->percentage;

                i->roll       = j->roll;
                strcpy(i->name, j->name);
                i->percentage = j->percentage;

                j->roll       = troll;
                strcpy(j->name, tname);
                j->percentage = tpct;
            }
        }
    }

    printf("List sorted by name.\n");
    stud_show(*ptr);
}

void sort_by_percentage(struct st **ptr)
{
    struct st *i;
    struct st *j;
    int   troll;
    char  tname[100];
    float tpct;

    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    for(i = *ptr; i != 0; i = i->next)
    {
        for(j = i->next; j != 0; j = j->next)
        {
            if(i->percentage < j->percentage)
            {
                /* swap data */
                troll      = i->roll;
                strcpy(tname, i->name);
                tpct       = i->percentage;

                i->roll       = j->roll;
                strcpy(i->name, j->name);
                i->percentage = j->percentage;

                j->roll       = troll;
                strcpy(j->name, tname);
                j->percentage = tpct;
            }
        }
    }

    printf("List sorted by percentage.\n");
    stud_show(*ptr);
}
