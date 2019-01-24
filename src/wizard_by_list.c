/* Andre Augusto Giannotti Scota Tool Box Library.
 * andre.scota@gmail.com
 *
 * Public Domain
 *
 */


/* wizard_by_list.c
 * This file implement the 'run_functions_in_a_list' facillity.
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include "wizard_by_list.h"


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */


/* *** LOCAL PROTOTYPES **************************************************************** */


/* *** EXTERNS / LOCAL GLOBALS ********************************************************* */



/* *** INTERFACES / PROTOTYPES ********************************************************* */
/* int a2gs_ToolBox_WizardValue(a2gs_ToolBox_FunctionListValue_t *fList, void *data, int erroCode, unsigned int *fListStep)
 *
 * It runs functions in a list of function pointers. Stops when one function return the same value of
 * erroCode (or the last sucefull return function code).
 * All functions must have the same prototype:
 *  int functionX(void *)   Return a int and get a void * (what you want)
 *
 * INPUT:
 *  fList - Pointer to the pointer function list. Last pointer must be NULL.
 *  data - Data passed through functions in list.
 *  erroCode - The value that the functions' returns must be different (to continue the list's executation).
 * OUTPUT:
 *  fListStep - Index of fList[] showing what would be the next function executation.
 *  The return is the same of last function executed in fList.
 */
int a2gs_ToolBox_WizardValue(a2gs_ToolBox_FunctionListValue_t *fList, void *data, int erroCode, unsigned int *fListStep)
{
   int ret;

   for(*fListStep = 0, ret = ~erroCode; (fList[*fListStep] != NULL) && (ret != erroCode); (*fListStep)++)
      ret = fList[*fListStep](data);

   return(ret);
}
