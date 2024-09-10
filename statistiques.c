#include <stdio.h>
#include "statistiques.h"
#include "gestion_etudiants.h"

void calculerMoyenneGenerale() {
    float somme = 0;
    for (int i = 0; i < nombreEtudiants; i++) {
        somme += etudiants[i].note_generale;
    }

    float moyenne = (nombreEtudiants > 0) ? somme / nombreEtudiants : 0;
    printf("La moyenne générale de la classe est: %.2f\n", moyenne);
}

void afficherStatistiques() {
    int reussis = 0, echoues = 0;

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].note_generale >= NOTE_REUSSITE) {
            reussis++;
        } else {
            echoues++;
        }
    }

    printf("Nombre d'étudiants réussis: %d\n", reussis);
    printf("Nombre d'étudiants échoués: %d\n", echoues);
}
