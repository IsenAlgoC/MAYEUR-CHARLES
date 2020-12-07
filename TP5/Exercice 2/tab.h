#include <stdlib.h>
#include <stdio.h>
#define TAILLEINITIALE 10

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
			incrementArraySize(tab, pos - tab->size);    //Augmente la taille du tableau pour pouvoir le mettre
			for (int i = tab->size; i <= pos - tab->size; i++) {     //On mets des 0 pour chaque élément entre la fin du tableau et le nouveau
				*(tab->elt + i) = 0;
			}
			tab->size += (pos - tab->size);   //Augmente size
		}
		if (*(tab->elt + pos - 1) == 0) {  // Si on ne remplace pas d'élément
			tab->eltsCount += 1;
		}
		*(tab->elt + pos - 1) = element; //On ajoute l'élément
		return(pos);
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	
	if (tab->elt == NULL) { //Si pas d'élément
		return(-1);
	}
	else {
		int tmp;
		if (startPos > endPos) {        //Si positions mal rangées on les range dans l'ordre croissant
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (tmp = startPos - 1; tmp < endPos; tmp++) { //On affiche les éléments du tableau
			printf_s("%d", *(tab->elt + tmp));
		}
		return(0);
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int tmp;
	if (tab->elt == NULL) {                     //Si pas d'élément dans le tableau
		return(-1);
	}
	else {                                      //Sinon
		if (startPos > endPos) {            //Si les positions sont mal rangées entre elles, on les range dans l'ordre croissant
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (tmp = 0; tmp < tab->size - endPos; tmp++) {                                //On supprime les éléments des positions startPos jusque endPos
			*(tab->elt + startPos - 1 + tmp) = *(tab->elt + endPos + tmp);
		}
		tab->elt = (int*)realloc(tab->elt, (tab->size - endPos + startPos) * sizeof(int));
		tab->size = tab->size - endPos + startPos;
		return(tab->size);
	}
}
