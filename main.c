#include"header.h"

int main()
{
	struct st *hptr=0;	
	char c;
	stud_load(&hptr);
	while(1)
	{
	printf("\t\t+-------------------------------------+\t\t\n");
	printf("\t\t|*********STUDENT RECORD MENU*********|\t\t\n");
	printf("\t\t+-------------------------------------+\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        A/a : Add New Record         |\t\t\n");
	printf("\t\t|	                              |\t\t\n");
	printf("\t\t|        D/d : Delete A Record        |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        S/s : Show the List          |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        M/m : Modify A Record        |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        V/v : Save                   |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        E/e : Exit                   |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        T/t : Sort the List          |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        L/l : Delete All the Records |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t|        R/r : Reverse the List       |\t\t\n");
	printf("\t\t|                                     |\t\t\n");
	printf("\t\t+-------------------------------------+\t\t\n");

	printf("ENTER THE OPTION FROM MENU: ");
	scanf(" %c",&c);
	switch(c|32)
	{
		case 'a': stud_add(&hptr);
			  break ;
		case 's': stud_show(hptr);
			  break;
		case 'v': stud_save(hptr);
			  break;
		case 'd': stud_del(&hptr);
			  break;
		case 'e': stud_exit(hptr);
			  break;
		case 'l': del_all(&hptr);
			  break;
		case 'm': stud_mod(&hptr);
			  break;
		case 't': stud_sort(&hptr);
			  break;
	        case 'r': stud_rev(&hptr); 
			  break;


	}
	}

}

