#include <stdio.h>
#include <string.h>
#include "tri_recherche.h"
#include "gestion_etudiants.h"

void rechercherEtudiant() {
    char nom[50];
    int trouve = 0;

    printf("Entrez le nom de l'étudiant à rechercher: ");
    scanf("%s", nom);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].nom, nom) == 0) {
            printf("Étudiant trouvé: %s %s - Note: %.2f\n", etudiants[i].prenom, etudiants[i].nom, etudiants[i].note_generale);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun étudiant avec ce nom n'a été trouvé.\n");
    }
}

void trierEtudiants() {
    int choix;
    Etudiant temp;

    printf("Choisissez le type de tri:\n");
    printf("1. Tri alphabétique par nom (A à Z)\n");
    printf("2. Tri alphabétique par nom (Z à A)\n");
    printf("3. Tri par moyenne générale (du plus élevé au plus faible)\n");
    printf("4. Tri par moyenne générale (du plus faible au plus élevé)\n");
    printf("5. Tri par statut de réussite\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = i + 1; j < nombreEtudiants; j++) {
            int swap = 0;
            switch (choix) {
                case 1: swap = strcmp(etudiants[i].nom, etudiants[j].nom) > 0; break;
                case 2: swap = strcmp(etudiants[i].nom, etudiants[j].nom) < 0; break;
                case 3: swap = etudiants[i].note_generale < etudiants[j].note_generale; break;
                case 4: swap = etudiants[i].note_generale > etudiants[j].note_generale; break;
                case 5: swap = (etudiants[i].note_generale < NOTE_REUSSITE) && (etudiants[j].note_generale >= NOTE_REUSSITE); break;
                default: printf("Choix invalide.\n"); return;
            }
            if (swap) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Étudiants triés avec succès!\n");
}
