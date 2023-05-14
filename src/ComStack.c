#include <Diagnostic.h>
#include <stdio.h>
#include <stdlib.h>
#include "DiagnosticTimer.h"
#include "DiagnosticIf.h"
#include "DiagnosticInit.h"



int main(void) {
	Diagnostic_Init_Config();

	while(1)
	{
		Diagnostic_Proc();
	}
	return 1;
}
