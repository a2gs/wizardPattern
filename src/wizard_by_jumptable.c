/* Andre Augusto Giannotti Scota Tool Box Library.
 * andre.scota@gmail.com
 *
 * MIT License
 *
 */


/* wizard_by_jumptable.c
 *
 * This pattern facilites the sequence called by a flow chart: Each function return the name of the next function's name.
 * The user register a matrix with single function pointer and its name. A start function is definead.
 * All functions are able to receives a void *data to work with any datatype desired.
 * There is only one name reserved to finish the flow chart: 'END'. Returning this name (string), the wizard pattern stops.
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <string.h>
#include "wizard_by_jumptable.h"


/* *** INTERFACES / PROTOTYPES ********************************************************* */
/* a2gs_ToolBox_WizardJumpTableFunc_t searchFuncJunpTable(funcJT *jumpTable, char *nameFunc)
 *
 * This function search the function by 'nameFunc' and return yours address.
 * INPUT:
 * 	nameFunc - (string) Function name to be searched. A "END" name will return NULL (should not be requested by,
 * 	           see wizard_by_return() function).
 * OUTPUT:
 * 	Address of corresponding function or NULL if not located
 */
a2gs_ToolBox_WizardJumpTableFunc_t a2gs_ToolBox_searchFuncJumpTable(a2gs_ToolBox_WizardJumpTable_t *jumpTable, char *nameFunc)
{
	unsigned int i = 0;

	for(i = 0; strcmp(jumpTable->name, "END") != 0; i++){
		if(strcmp(nameFunc, jumpTable[i].name) == 0)
			return(jumpTable[i].func);
	}

	return((a2gs_ToolBox_WizardJumpTableFunc_t) NULL);
}

int a2gs_ToolBox_WizardJumpTable(a2gs_ToolBox_WizardJumpTable_t *jumpTable, char *initFunc, void *data)
{
	char *func = initFunc;
	a2gs_ToolBox_WizardJumpTableFunc_t call = NULL;

	while(strcmp(func, "END") != 0){
		call = a2gs_ToolBox_searchFuncJumpTable(jumpTable, func);

		if(call == (a2gs_ToolBox_WizardJumpTableFunc_t)NULL)
			return(-1);

		func = call(data);
	}

	return(0);
}
