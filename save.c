#include"header.h"

void stud_save(struct st *ptr)
{
    FILE *fp;
    fp = fopen("students.txt", "w");
    if(fp == 0)
    {
        printf("Error opening file!\n");
        return;
    }

    while(ptr != 0)
    {
        fprintf(fp, "%d|%s|%.2f\n",ptr->roll, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }

    fclose(fp);
    printf("Data saved to students.txt\n");
}
