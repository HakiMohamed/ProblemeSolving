#ifndef GESTION_ETUDIANTS_H
#define GESTION_ETUDIANTS_H

#define NOTE_REUSSITE 10

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char departement[50];
    float note_generale;
} Etudiant;

extern Etudiant etudiants[];
extern int nombreEtudiants;

void ajouterEtudiant();
void modifierEtudiant();
void supprimerEtudiant();
void afficherEtudiants();
void afficherEtudiant();
void afficherEtudiantsDepartement();

#endif
