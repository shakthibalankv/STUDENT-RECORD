#include"header.h"

void stud_exit(struct st *ptr)
{
    char choice;

    printf("***ENTER THE OPTION***\n");
    printf("+---------------------------------+\n");
    printf("|    S/s  :  Save and Exit        |\n");
    printf("|    E/e  :  Exit Without Saving  |\n");
    printf("+---------------------------------+\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch(choice|32)
    {
        case 's':
            stud_save(ptr);
            exit(0);
            break;

        case 'e':
            printf("Exiting without saving.!\n");
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}
