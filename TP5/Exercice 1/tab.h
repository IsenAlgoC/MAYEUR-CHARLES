#include <stdlib.h>

#define TAILLEINITIALE 100
#define TAILLEAJOUT 50

int initTab(int* tab, int size) {
	if (tab == NULL || size < 0) {  //Si on ne peut pas initialiser le tableau
		return(-1);
	}

	else {                                      //Si on peut
		for (int i = 0; i < size; i++) {         //on initialise à 0
			*(tab + i) = 0;
		}
		return(size);
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL || size < 0 || size < nbElts) { //Si on ne peut pas afficher
		return(-1);
	}
	else {
		for (int i = 0; i < nbElts; i++) {   //On affiche chaque élément
			printf(" %d", *(tab + i));        //un par un
		}
		return(0);
	}
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL) {  //Pointeur nul
		return(-1);
	}
	else {
		if (*size < nbElts) {		//Si le tableau est trop petit 
			*size = *size + TAILLEAJOUT;	//On l'agrandit
			tab = (int*)realloc(tab, *size);  //On réallout
		}
		else {
			*(tab + *nbElts) = element;	//On ajoute les nouveaux termes
			*nbElts = *nbElts + 1; // On actualise le nombre d'elements
			return(*nbElts);  //On retourne le nombre d'éléments
		}

	}
}
