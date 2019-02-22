/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * Public Domain
 *
 */


/* wizard_by_jumptable.h
 *
 * A pattern to follow a list of function, in a flow chart.
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 *          |            |
 */


#ifndef __A2GS_TOOLBOX_WIZARDJUMPTABLE_H__
#define __A2GS_TOOLBOX_WIZARDJUMPTABLE_H__


/* *** INCLUDES ************************************************************************ */


/* *** DEFINES ************************************************************************* */


/* *** DATA TYPES ********************************************************************** */
typedef char * (*a2gs_ToolBox_WizardJumpTableFunc_t) (void *);

typedef struct _a2gs_ToolBox_WizardJumpTable_t{
	a2gs_ToolBox_WizardJumpTableFunc_t func;
	char *name;
}a2gs_ToolBox_WizardJumpTable_t;


/* *** INTERFACES / PROTOTYPES ********************************************************* */
/* int a2gs_ToolBox_WizardJumpTable(funcJT *jumpTable, char *initFuncName, void *data);
 *
 * This function processes the wizard pattern. This follow a sequence of functions defined by user: a flow chart.
 *
 * INPUT:
 *     jumpTable - A matrix of 'funcJT' filled by the name and address of functions (function of type 'funcAddr_t').
 *                 ATTENTION: The last element MUST be {NULL, "END"}};
 *     initFuncName - The name of start function
 *     data - Data that will be goes through all function flow chat (can be any kind of datatype)
 * OUTPUT:
 * 	-1 - A error was found: a function name not registred into 'jumpTable' matrix
 * 	 0 - All flow chat was complete and termineted at a "END" correctly
 */
int a2gs_ToolBox_WizardJumpTable(a2gs_ToolBox_WizardJumpTable_t *jumpTable, char *initFuncName, void *data);


/* *** EXAMPLE ************************************************************************* */
#if 0
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
#endif

#endif
