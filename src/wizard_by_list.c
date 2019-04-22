/* Andre Augusto Giannotti Scota Tool Box Library.
 * andre.scota@gmail.com
 *
 * MIT License
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
int a2gs_ToolBox_WizardList(a2gs_ToolBox_WizardListFunc_t *funcsList, void *data, int erroCode, unsigned int *fListStep)
{
   int ret;

   for(*fListStep = 0, ret = ~erroCode; (funcsList[*fListStep] != NULL) && (ret != erroCode); (*fListStep)++)
      ret = funcsList[*fListStep](data);

   return(ret);
}
