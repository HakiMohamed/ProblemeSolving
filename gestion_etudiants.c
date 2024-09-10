#include <stdio.h>
#include <string.h>
#include "gestion_etudiants.h"

#define MAX_ETUDIANTS 100

Etudiant etudiants[MAX_ETUDIANTS];
int nombreEtudiants = 0;

void ajouterEtudiant() {
    if (nombreEtudiants >= MAX_ETUDIANTS) {
        printf("Impossible d'ajouter plus d'étudiants.\n");
        return;
    }

    Etudiant etudiant;
    etudiant.id = nombreEtudiants + 1;
    printf("Entrez le prénom: ");
    scanf("%s", etudiant.prenom);
    printf("Entrez le nom: ");
    scanf("%s", etudiant.nom);
    printf("Entrez le département: ");
    scanf("%s", etudiant.departement);
    printf("Entrez la note générale: ");
    scanf("%f", &etudiant.note_generale);

    etudiants[nombreEtudiants] = etudiant;
    nombreEtudiants++;
    printf("Étudiant ajouté avec succès!\n");
}

void modifierEtudiant() {
    int id;
    printf("Entrez l'ID de l'étudiant à modifier: ");
    scanf("%d", &id);

    if (id < 1 || id > nombreEtudiants) {
        printf("ID invalide.\n");
        return;
    }

    printf("Modifier les informations de l'étudiant:\n");
    printf("Entrez le nouveau prénom: ");
    scanf("%s", etudiants[id - 1].prenom);
    printf("Entrez le nouveau nom: ");
    scanf("%s", etudiants[id - 1].nom);
    printf("Entrez le nouveau département: ");
    scanf("%s", etudiants[id - 1].departement);
    printf("Entrez la nouvelle note générale: ");
    scanf("%f", &etudiants[id - 1].note_generale);

    printf("Étudiant modifié avec succès!\n");
}

void supprimerEtudiant() {
    int id;
    printf("Entrez l'ID de l'étudiant à supprimer: ");
    scanf("%d", &id);

    if (id < 1 || id > nombreEtudiants) {
        printf("ID invalide.\n");
        return;
    }

    for (int i = id - 1; i < nombreEtudiants - 1; i++) {
        etudiants[i] = etudiants[i + 1];
    }
    nombreEtudiants--;
    printf("Étudiant supprimé avec succès!\n");
}

void afficherEtudiants() {
    printf("\nListe des étudiants:\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("ID: %d, Nom: %s %s, Département: %s, Note: %.2f\n",
               etudiants[i].id, etudiants[i].prenom, etudiants[i].nom, etudiants[i].departement, etudiants[i].note_generale);
    }
}

void afficherEtudiant() {
    int id;
    printf("Entrez l'ID de l'étudiant: ");
    scanf("%d", &id);

    if (id < 1 || id > nombreEtudiants) {
        printf("ID invalide.\n");
        return;
    }

    printf("ID: %d, Nom: %s %s, Département: %s, Note: %.2f\n",
           etudiants[id - 1].id, etudiants[id - 1].prenom, etudiants[id - 1].nom, etudiants[id - 1].departement, etudiants[id - 1].note_generale);
}

void afficherEtudiantsDepartement() {
    char departement[50];

    printf("Entrez le nom du département: ");
    scanf("%s", departement);

    printf("Étudiants du département %s:\n", departement);
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            printf("%s %s - Note: %.2f\n", etudiants[i].prenom, etudiants[i].nom, etudiants[i].note_generale);
        }
    }
}
