	#include <stdio.h>
	#include "wizard_by_jumptable.h"

	/* func3
	 * func4
	 * func1 ---> NULL
	 * func2
	 */

	char * func1(void *data)
	{
		printf("Na funcao 1\n");

		if(*(int *)data == 8)
			return("END");
		else
			return("FUNCAO2");
	}

	char * func2(void *data)
	{
		printf("Na funcao 2\n");
		return("END");
	}

	char * func3(void *data)
	{
		printf("Na funcao 3 [%d]\n", *(int *)data);
		*(int *)data = 8;

		return("FUNCAO4");
	}

	char * func4(void *data)
	{
		printf("Na funcao 4 [%d]\n", *(int *)data);

		return("FUNCAO1");
	}

	int main(int argc, char *argv[])
	{
		int data = 13;
		a2gs_ToolBox_WizardJumpTable_t jumpTable[] = {{func1, "FUNCAO1"}, {func2, "FUNCAO2"}, {func3, "FUNCAO3"}, {func4, "FUNCAO4"}, {NULL, "END"}};

		if(a2gs_ToolBox_WizardJumpTable(jumpTable, "FUNCAO3", &data) == -1){
			printf("Seguencia de funcao problematica (existe uma funcao nao cadastrada)!\n");
			return(-1);
		}

		return(0);
	}
