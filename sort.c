#include"header.h"

struct st *clone_list(struct st *src)
{
    struct st *head = 0;
    struct st *tail = 0;

    while(src != 0)
    {
        struct st *node = (struct st *)malloc(sizeof(struct st));
        node->roll       = src->roll;
        strcpy(node->name, src->name);
        node->percentage = src->percentage;
        node->next       = 0;

        if(head == 0)
            head = tail = node;
        else
        {
            tail->next = node;
            tail       = node;
        }
        src = src->next;
    }
    return head;
}

void free_list(struct st *ptr)
{
    struct st *tmp;
    while(ptr != 0)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

/* ---------- menu ---------- */

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

/* ---------- sort by name (on a copy) ---------- */

void sort_by_name(struct st **ptr)
{
    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    struct st *copy = clone_list(*ptr);

    struct st *i, *j;
    int   troll;
    char  tname[100];
    float tpct;

    for(i = copy; i != 0; i = i->next)
    {
        for(j = i->next; j != 0; j = j->next)
        {
            if(strcmp(i->name, j->name) > 0)
            {
                troll = i->roll;  strcpy(tname, i->name);  tpct = i->percentage;
                i->roll = j->roll; strcpy(i->name, j->name); i->percentage = j->percentage;
                j->roll = troll;  strcpy(j->name, tname);  j->percentage = tpct;
            }
        }
    }

    printf("(Showing sorted view \n");
    stud_show(copy);
    free_list(copy);
}

/* ---------- sort by percentage (on a copy) ---------- */

void sort_by_percentage(struct st **ptr)
{
    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    struct st *copy = clone_list(*ptr);

    struct st *i, *j;
    int   troll;
    char  tname[100];
    float tpct;

    for(i = copy; i != 0; i = i->next)
    {
        for(j = i->next; j != 0; j = j->next)
        {
            if(i->percentage < j->percentage)
            {
                troll = i->roll;  strcpy(tname, i->name);  tpct = i->percentage;
                i->roll = j->roll; strcpy(i->name, j->name); i->percentage = j->percentage;
                j->roll = troll;  strcpy(j->name, tname);  j->percentage = tpct;
            }
        }
    }

    printf("(Showing sorted view \n");
    stud_show(copy);
    free_list(copy);
}
