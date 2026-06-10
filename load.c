#include"header.h"


void stud_load(struct st **ptr)
{
    FILE *fp;
    fp = fopen("students.txt", "r");
    if(fp == 0)
    {
        printf("No saved data found.\n");
        return;
    }

    struct st *temp;
    struct st *last = 0;
    int   r;
    char  name[100];
    float pct;

    while(fscanf(fp, "%d|%[^|]|%f\n", &r, name, &pct) == 3)
    {
        temp             = (struct st *)malloc(sizeof(struct st));
        temp->roll       = r;
        strcpy(temp->name, name);
        temp->percentage = pct;
        temp->next       = 0;

        if(*ptr == 0)
        {
            *ptr = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last       = temp;
       }
    }

    fclose(fp);
    printf("data loaded successfully.\n");
}
