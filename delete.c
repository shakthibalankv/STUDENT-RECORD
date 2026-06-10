#include"header.h"

void stud_del(struct st **ptr)
{
	char d;
	printf("  ***DELETE A STUDENT RECORD***   \n");
	printf("+--------------------------------+\n");
	printf("|  R/r: Enter Roll no to Delete  |\n");
	printf("|                                |\n");
	printf("|  N/n: Enter name to Delete     |\n");
	printf("+--------------------------------+\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &d);

        switch(d|32)
	{
		case 'r': del_by_roll(ptr);
                          break;
		case 'n': del_by_name(ptr);
			  break;
		default : printf("INVALID CHOICE\n");
			  break;
	}
}

void del_by_roll(struct st **ptr)
{
    int roll;
    printf("Enter roll no: ");
    scanf("%d", &roll);

    struct st *cur  = *ptr;
    struct st *prev = 0;

    while(cur != 0 && cur->roll != roll)
    {
        prev = cur;
        cur  = cur->next;
    }

    switch(cur == 0)
    {
        case 1:
            printf("Roll no %d not found.\n", roll);
            break;

        case 0:
            /* show data in box */
            printf("\n+--------+----------------------+------------+\n");
            printf("| %-6s | %-20s | %-10s |\n","Rollno", "Name", "Percentage");
            printf("+--------+----------------------+------------+\n");
            printf("| %-6d | %-20s | %-10.2f |\n", cur->roll, cur->name, cur->percentage);
            printf("+--------+----------------------+------------+\n");

            /* confirm deletion */
            char confirm;
            printf("\nDo you want to delete this data? (Y/y to confirm): ");
            scanf(" %c", &confirm);

            switch(confirm|32)
            {
                case 'y':
                    if(prev == 0)
                        *ptr = cur->next;
                    else
                        prev->next = cur->next;

                    printf("Deleted: Roll No %d | %s\n", cur->roll, cur->name);
                    free(cur);
                    break;

                default:
                    printf("Deletion cancelled.\n");
                    break;
            }
            break;
    }
}

/* *****delete by name******* */

void del_by_name(struct st **ptr)
{
    char name[100];
    printf("Enter name: ");
    scanf(" %[^\n]",name);

    int count = 0;
    struct st *cur = *ptr;
    while(cur != 0)
    {
        if(strcmp(cur->name, name) == 0)
            count++;
        cur = cur->next;
    }

    if(count == 0)
    {
        printf("Name '%s' not found.\n", name);
        return;
    }

    /* step 2: if duplicates found, show all matches */
    if(count > 1)
    {
        printf("\nMultiple records found with name '%s':\n", name);
        printf("+--------+----------------------+------------+\n");
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

        /* ask user to pick roll no */
        int roll;
        printf("Enter roll no to delete: ");
        scanf("%d", &roll);



        del_by_roll_direct(ptr, roll);
    }
    else
    {
        /* only one match — delete directly */
        struct st *cur  = *ptr;
        struct st *prev = 0;

        while(cur != 0 && strcmp(cur->name, name) != 0)
        {
            prev = cur;
            cur  = cur->next;
        }

        if(prev == 0)
            *ptr = cur->next;
        else
            prev->next = cur->next;

        printf("Deleted: Roll No %d | %s\n", cur->roll, cur->name);
        free(cur);
    }
}


/*del_by_name when duplicate found */

void del_by_roll_direct(struct st **ptr, int roll)
{
    struct st *cur  = *ptr;
    struct st *prev = 0;

    while(cur != 0 && cur->roll != roll)
    {
        prev = cur;
        cur  = cur->next;
    }

    switch(cur == 0)
    {
        case 1:
            printf("Roll no %d not found.\n", roll);
            break;

        case 0:
            /* show data in box */
            printf("\n+--------+----------------------+------------+\n");
            printf("| %-6s | %-20s | %-10s |\n", "Roll", "Name", "Percentage");
            printf("+--------+----------------------+------------+\n");
            printf("| %-6d | %-20s | %-10.2f |\n",
                    cur->roll, cur->name, cur->percentage);
            printf("+--------+----------------------+------------+\n");

            /* confirm deletion */
            char confirm;
            printf("\nDo you want to delete this data? (Y/y to confirm): ");
            scanf(" %c", &confirm);

            switch(confirm|32)
            {
                case 'y':
                    if(prev == 0)
                        *ptr = cur->next;
                    else
                        prev->next = cur->next;

                    printf("Deleted: Roll No %d | %s\n", cur->roll, cur->name);
                    free(cur);
                    break;

                default:
                    printf("Deletion cancelled.\n");
                    break;
            }
            break;
    }
}

