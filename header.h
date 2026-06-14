#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
	int roll;
	char name[100];
	float percentage;
	struct st *next;
};

void stud_add(struct st **);
static int get_next_roll(struct st *);
void stud_show(struct st *);
void stud_save(struct st *);
void stud_load(struct st **);
void stud_del(struct st **);
void del_by_roll(struct st **);
void del_by_name(struct st **);
void del_by_roll_direct(struct st **, int );
void stud_exit(struct st *);
void del_all(struct st **);
void stud_mod(struct st **);
void mod_by_roll(struct st **);
void mod_by_name(struct st **);
void mod_field(struct st *);
void stud_sort(struct st **);
void sort_by_name(struct st **);
void sort_by_percentage(struct st **);
void stud_rev(struct st **);
struct st *clone_list(struct st *);
void free_list(struct st *);

