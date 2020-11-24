#include <stdio.h> 
#include "tab.h"
#define TAILLEINITIALE 100

int main() {
	TABLEAU MyTab;
	displayElements(&MyTab, 1, TAILLEINITIALE);

	incrementArraySize(&MyTab, 1);
	displayElements(&MyTab, 1, TAILLEINITIALE + 1);

	setElement(&tab, 9, 12);
	displayElements(&tab, 9, TAILLEINITIALE +1);

	deleteElements(&tab, 9, 10);
	displayElements(&tab, 1, TAILLEINITIALE);

	free(tab.elt);
}