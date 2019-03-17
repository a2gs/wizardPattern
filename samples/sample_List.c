#include <stdio.h>
#include "wizard_by_list.h"

int f1(void *a)
{
	/* do some thing... */
	printf("[%s]\n", (char *)a);
	return(1); 
}

int f2(void *a)
{
	/* do some thing... */
	printf("[%s]\n", (char *)a);
	return(1);  
}

int f3(void *a)
{
	/* do some thing... */
	printf("[%s]\n", (char *)a);
	return(-1); /* ERROR Here!!! */
}

int f4(void *a)
{
	/* do some thing... */
	printf("[%s]\n", (char *)a);
	return(-1); 
}

int main(int argc, char *argv[])
{
	char buff[10] = "abc";
	unsigned int step = 0;
	int last_ret = 0;

	a2gs_ToolBox_WizardListFunc_t list[] = {f1, f2, f3, f4, NULL};

	last_ret = a2gs_ToolBox_WizardList(list, buff, -1, &step);

	if(list[step] == NULL)
		printf("Executed all functions\n");
	printf("Executation goes to step: [%d] and return [%d]\n", step, last_ret);

	return(1);
}
