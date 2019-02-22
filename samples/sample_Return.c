	#include <stdio.h>
#include "wizard_by_return.h"

	a2gs_ToolBox_WizardReturnFunc_t func1(void *data);
	a2gs_ToolBox_WizardReturnFunc_t func2(void *data);
	a2gs_ToolBox_WizardReturnFunc_t func3(void *data);
	a2gs_ToolBox_WizardReturnFunc_t func4(void *data);

	a2gs_ToolBox_WizardReturnFunc_t func1(void *data)
	{
		a2gs_ToolBox_WizardReturnFunc_t ret = NULL;
		int x = *((int *) data);

		printf("func 1: [%d]\n", x);
		return(ret);
	}

	a2gs_ToolBox_WizardReturnFunc_t func2(void *data)
	{
		a2gs_ToolBox_WizardReturnFunc_t ret = NULL;
		int x = *((int *) data);

		printf("func 2: [%d]\n", x);
		return(ret);
	}

	a2gs_ToolBox_WizardReturnFunc_t func3(void *data)
	{
		a2gs_ToolBox_WizardReturnFunc_t ret = func4;
		int x = *((int *) data);

		printf("func 3: [%d]\n", x);
		return(ret);
	}

	a2gs_ToolBox_WizardReturnFunc_t func4(void *data)
	{
		a2gs_ToolBox_WizardReturnFunc_t ret = func1;
		int x = *((int *) data);

		printf("func 4: [%d]\n", x);
		return(ret);
	}

	int main(int argc, char *argv[])
	{
		int x = 13;

		a2gs_ToolBox_WizardReturn(func3, (void *)&x);

		return(0);
	}
