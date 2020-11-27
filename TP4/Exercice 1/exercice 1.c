#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "tp4.h"

int main() {
	HEURE HeureDebut = { 12, 30 };
	HEURE HeureFin;
	HEURE Duree = { 0, 45 };
	HeureFin.minute = (HeureDebut.minute + Duree.minute)%60;
	HeureFin.heure = (HeureDebut.minute + Duree.minute) / 60+ HeureDebut.heure+Duree.heure;
	printf("L'heure de fin est : %d H %d", HeureFin.heure, HeureFin.minute);
}
