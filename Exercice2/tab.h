#include <stdlib.h>
#include <stdio.h>
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;	//le tableau d'entiers
	int size;	// la taille de ce tableau d’entiers
	int eltsCount;	//le nombre d'elements dans le tableau
} TABLEAU;

TABLEAU newArray() {
	TABLEAU tab;                                           //On crée le tableau
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));  //On allout la mémoire
	tab.size = TAILLEINITIALE;                             //On initialise la taille
	tab.eltsCount = 0;                                     //On initialise le nombre d'éléments
	for (int i = 0; i < tab.size; i++) {	               //On initialise les valeurs du tableau à 0
		*(tab.elt + i) = 0;
	}
	return(tab);
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));  
	for (int i = tab->size; i < tab->size + incrementValue; i++) {
		*(tab->elt + i) = 0;		//On initialise à 0
	}
	tab->size = tab->size + incrementValue;
	if (tab->elt == NULL) {  //Si pointeur null
		return(-1);
	}
	else {                   //Sinon
		return(tab->size);
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (tab->elt == NULL) {		//Si pointeur NULL
		return(0);
	}
	else {                      //Sinon
		if (pos > tab->size) {  //S'il est en dehors du tableau
			incrementArraySize(tab, pos - tab->size);
			for (int i = tab->size; i <= pos - tab->size; i++) {
				*(tab->elt + i) = 0;
			}
			tab->size += (pos - tab->size);
		}
		if (*(tab->elt + pos - 1) == 0) {  // Si 
			tab->eltsCount += 1;
		}
		*(tab->elt + pos - 1) = element;
		return(pos);
	}
}

