#include"header.h"

void stud_rev(struct st **ptr)
{
    if(*ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    struct st *copy = clone_list(*ptr);

    /* reverse by relinking the cloned list */
    struct st *prev = 0;
    struct st *cur  = copy;
    struct st *next = 0;

    while(cur != 0)
    {
        next      = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = next;
    }
    copy = prev;   /* new head */

    printf("(Showing reversed view \n");
    stud_show(copy);
    free_list(copy);
}
