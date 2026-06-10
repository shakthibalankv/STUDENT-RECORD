#include"header.h"

void stud_show(struct st *ptr)
{
    if(ptr == 0)
    {
        printf("List is empty.\n");
        return;
    }

    printf("***LIST OF STUDENTS***");

    printf("\n+--------+----------------------+------------+\n");
    printf("| %-6s | %-20s | %-10s |\n", "Rollno", "Name", "Percentage");
    printf("+--------+----------------------+------------+\n");

    while(ptr != 0)
    {
        printf("| %-6d | %-20s | %-10.2f |\n",
               ptr->roll, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }

    printf("+--------+----------------------+------------+\n\n");
}
