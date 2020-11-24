#include "tab.h"
#include <stdio.h> 

#define TAILLEINITIALE 100
#define TAILLEAJOUT 50

int main() {
	int MyTab1[10];
	int* MyTab2;
	MyTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int));
	int TAB2SIZE = TAILLEINITIALE;

	initTab(MyTab1, 10);         //Tests des fonctions sur MyTab1
	afficheTab(MyTab1, 10, 10);

	if (MyTab2 != NULL) {
		initTab(MyTab2, TAB2SIZE); //Test de la fonction initTab sur MyTab2
	}
	else {
		printf("mémoire insuffisante");
		return(-1);
	}

	for (int i = 0; i < TAILLEINITIALE; i++) {   //on remplie les 20 premières valeurs du tableau de 1 à 20
		*(MyTab2 + i) = i + 1;
	}

	afficheTab(MyTab2, TAB2SIZE, 20);  //On affiche les valeurs de MyTab2

	free(MyTab2);//On libère la mémoire

}