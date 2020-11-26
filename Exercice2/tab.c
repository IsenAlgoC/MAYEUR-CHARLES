#include <stdio.h> 
#include "Test.h"
#define TAILLEINITIALE 10

void main() {
	//Création de tableau
	TABLEAU MyTab;
	MyTab = newArray();
	printf("Test d'affichage de 10 valeurs '0': \n");
	displayElements(&MyTab, 1, TAILLEINITIALE); 

	printf("\nTest d'augmentation de taille de 2 : \n");
	incrementArraySize(&MyTab, 2);
	displayElements(&MyTab, 1, TAILLEINITIALE + 2);

	printf("\nTest d'ajout de la valeur 5 a la position 9 : \n");
	setElement(&MyTab, 9, 5);
	displayElements(&MyTab, 1, TAILLEINITIALE + 2);

	printf("\nTest d'ajout de la valeur 4 a la position 10 : \n");
	setElement(&MyTab, 10, 4);
	displayElements(&MyTab, 1, TAILLEINITIALE + 2);

	printf("\nTest de suppression d'élément de la position 9 a 10: \n");
	deleteElements(&MyTab, 9, 10);
	displayElements(&MyTab, 1, TAILLEINITIALE);

	free(MyTab.elt);
}
