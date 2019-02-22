/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * Public Domain
 *
 */


/* wizard_by_list.h
 *
 * A pattern to follow a list of function, in sequence until a error.
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 *          |            |
 */


#ifndef __A2GS_TOOLBOX_WIZARDLIST_H__
#define __A2GS_TOOLBOX_WIZARDLIST_H__


/* *** INCLUDES ************************************************************************ */


/* *** DEFINES ************************************************************************* */


/* *** DATA TYPES ********************************************************************** */
typedef int (*a2gs_ToolBox_WizardListFunc_t)(void *);


/* *** INTERFACES / PROTOTYPES ********************************************************* */
/* int a2gs_ToolBox_WizardList(a2gs_ToolBox_WizardListFunc_t *funcsList, void *data, int erroCode, unsigned int *fListStep)
 *
 * It runs functions in a list of function pointers. Stops when one function return the same value of
 * erroCode (or the last function' return code (sucefull)).
 * All functions must have the same prototype:
 *  int functionX(void *)   Return a int and get a void * (what you want)
 *
 * INPUT:
 *  funcsList - Pointer to the pointer function list. Last pointer must be NULL.
 *  data - Data passed through functions in list.
 *  erroCode - The value that the functions' returns must be different to continue the list's executation. 
 * OUTPUT:
 *  fListStep - Index of funcsList[] showing what would be the next function executation.
 *  The return is the same of last function executed in funcsList.       
 */
int a2gs_ToolBox_WizardList(a2gs_ToolBox_WizardListFunc_t *funcsList, void *data, int erroCode, unsigned int *fListStep);


/* *** EXAMPLE ************************************************************************* */
#if 0
	#include <stdio.h>
	#include "wizard_by_list.h"

	int f1(void *a){
	   /* do some thing... */
	   printf("[%s]\n", (char *)a);
	   return(1); 
	}

	int f2(void *a){
	   /* do some thing... */
	   return(1);  
	}

	int f3(void *a){
	   /* do some thing... */
	   return(-1); /* ERROR Here */
	}

	int f4(void *a){
	   /* do some thing... */
	   return(-1); 
	}

	int main(){
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
#endif

#endif
