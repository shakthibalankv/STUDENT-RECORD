#include"header.h"

void stud_mod(struct st **ptr)
{
    char choice;

    printf("\nEnter which record to search for modification\n\n");
    printf("+-------------------------------------+\n");
    printf("|    R/r  :  To search Rollno         |\n");
    printf("|    N/n  :  To search Name           |\n");
    printf("+-------------------------------------+\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch(choice|32)
    {
        case 'r':
            mod_by_roll(ptr);
            break;

        case 'n':
            mod_by_name(ptr);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}

/*MODIFY BY ROLL NUMBER*/

void mod_by_roll(struct st **ptr)
{
    int roll;
    printf("Enter roll no: ");
    scanf("%d", &roll);

    struct st *cur = *ptr;
    while(cur != 0 && cur->roll != roll)
        cur = cur->next;

    switch(cur == 0)
    {
        case 1:
            printf("Roll no %d not found.\n", roll);
            break;

        case 0:
            /* show current data */
            printf("\n+--------+----------------------+------------+\n");
            printf("| %-6s | %-20s | %-10s |\n", "Roll", "Name", "Percentage");
            printf("+--------+----------------------+------------+\n");
            printf("| %-6d | %-20s | %-10.2f |\n",
                    cur->roll, cur->name, cur->percentage);
            printf("+--------+----------------------+------------+\n");

            mod_field(cur);
            break;
    }
}

/*MODIFY BY NAME*/


void mod_by_name(struct st **ptr)
{
    char name[100];
    printf("Enter name: ");
    scanf(" %[^\n]", name);

    int count    = 0;
    struct st *cur = *ptr;
    while(cur != 0)
    {
        if(strcmp(cur->name, name) == 0)
            count++;
        cur = cur->next;
    }

    switch(count)
    {
        case 0:
            printf("Name '%s' not found.\n", name);
            break;

        case 1:
        {
            cur = *ptr;
            while(cur != 0 && strcmp(cur->name, name) != 0)
                cur = cur->next;

            /* show current data */
            printf("\n+--------+----------------------+------------+\n");
            printf("| %-6s | %-20s | %-10s |\n", "Roll", "Name", "Percentage");
            printf("+--------+----------------------+------------+\n");
            printf("| %-6d | %-20s | %-10.2f |\n",
                    cur->roll, cur->name, cur->percentage);
            printf("+--------+----------------------+------------+\n");

            mod_field(cur);
            break;
        }

        default:
        {
            /* multiple matches — show all, ask roll no */
            printf("\nMultiple records found with name '%s':\n", name);
            printf("\n+--------+----------------------+------------+\n");
            printf("| %-6s | %-20s | %-10s |\n", "Roll", "Name", "Percentage");
            printf("+--------+----------------------+------------+\n");

            cur = *ptr;
            while(cur != 0)
            {
                if(strcmp(cur->name, name) == 0)
                    printf("| %-6d | %-20s | %-10.2f |\n",
                           cur->roll, cur->name, cur->percentage);
                cur = cur->next;
            }
            printf("+--------+----------------------+------------+\n");

            int roll;
            printf("Enter roll no to modify: ");
            scanf("%d", &roll);

            cur = *ptr;
            while(cur != 0 && cur->roll != roll)
                cur = cur->next;

            switch(cur == 0)
            {
                case 1:
                    printf("Roll no %d not found.\n", roll);
                    break;
                case 0:
                    mod_field(cur);
                    break;
            }
            break;
        }
    }
}

/***MODIFY CODE***/

void mod_field(struct st *cur)
{
    char choice;

    printf("\nEnter which record to modification\n\n");
    printf("+-------------------------------------+\n");
    printf("|         N/n  :  Name                |\n");
    printf("|         P/p  :  Percentage          |\n");
    printf("+-------------------------------------+\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch(choice|32)
    {
        case 'n':
            printf("Enter new name: ");
            scanf(" %[^\n]", cur->name);
            printf("Name updated successfully.\n");
            break;

        case 'p':
            printf("Enter new percentage: ");
            scanf("%f", &cur->percentage);
            printf("Percentage updated successfully.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    /* show updated data */
    printf("\n+--------+----------------------+------------+\n");
    printf("| %-6s | %-20s | %-10s |\n", "Roll", "Name", "Percentage");
    printf("+--------+----------------------+------------+\n");
    printf("| %-6d | %-20s | %-10.2f |\n",
            cur->roll, cur->name, cur->percentage);
    printf("+--------+----------------------+------------+\n");
}
