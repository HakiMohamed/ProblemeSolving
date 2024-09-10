#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100
#define NOTE_REUSSITE 10.0



//----------------------------------------declaration de struct ----------------------------------------


typedef struct {
    int id;
    char prenom[50];
    char nom[50];
    char departement[50];
    float note_generale;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nombreEtudiants = 0;


//----------------------------------------declaration de functions----------------------------------------


void ajouterEtudiant();
void modifierEtudiant();
void supprimerEtudiant();
void afficherEtudiants();
void afficherEtudiant();
void rechercherEtudiant();
void afficherEtudiantsDepartement();
void trierEtudiants();
void calculerMoyenneGenerale();
void afficherStatistiques();



//----------------------------------------function main--------------------------------------------------------

int main() {
    int choix;

    do {
        printf("\nMenu de Gestion des Étudiants\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Modifier un étudiant\n");
        printf("3. Supprimer un étudiant\n");
        printf("4. Afficher tous les étudiants\n");
        printf("5. Afficher un étudiant\n");
        printf("6. Rechercher un étudiant par nom\n");
        printf("7. Afficher les étudiants d'un département\n");
        printf("8. Trier les étudiants\n");
        printf("9. Calculer la moyenne générale\n");
        printf("10. Afficher les statistiques\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterEtudiant(); break;
            case 2: modifierEtudiant(); break;
            case 3: supprimerEtudiant(); break;
            case 4: afficherEtudiants(); break;
            case 5: afficherEtudiant(); break;
            case 6: rechercherEtudiant(); break;
            case 7: afficherEtudiantsDepartement(); break;
            case 8: trierEtudiants(); break;
            case 9: calculerMoyenneGenerale(); break;
            case 10: afficherStatistiques(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide, réessayez.\n");
        }
    } while (choix != 0);

    return 0;
}



//----------------------------------------Fonction pour ajouter un étudiant----------------------------------------



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

//----------------------------------------Fonction pour modifier un étudiant----------------------------------------

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

//----------------------------------------Fonction pour supprimer un étudiant----------------------------------------


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

//----------------------------------------Fonction pour afficher tous les étudiants----------------------------------------


void afficherEtudiants() {
    printf("\nListe des étudiants:\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("ID: %d, Nom: %s %s, Département: %s, Note: %.2f\n",
               etudiants[i].id, etudiants[i].prenom, etudiants[i].nom, etudiants[i].departement, etudiants[i].note_generale);
    }
}


//----------------------------------------Fonction pour afficher un étudiant spécifique----------------------------------------

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


//----------------------------------------Fonction pour rechercher un étudiant par nom----------------------------------------


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


//----------------------------------------Fonction pour afficher les étudiants d'un département spécifique----------------------------------------

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



//----------------------------------------Fonction pour trier les étudiants----------------------------------------


void trierEtudiants() {
    int choix;
    Etudiant temp;

    printf("Choisissez le type de tri:\n");
    printf("1. Tri alphabétique par nom (A à Z)\n");
    printf("2. Tri alphabétique par nom (Z à A)\n");
    printf("3. Tri par moyenne générale (du plus élevé au plus faible)\n");
    printf("4. Tri par moyenne générale (du plus faible au plus élevé)\n");
    printf("5. Tri selon le statut de réussite (moyenne >= %.2f)\n", NOTE_REUSSITE);
    scanf("%d", &choix);

    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = i + 1; j < nombreEtudiants; j++) {
            if (choix == 1 && strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 2 && strcmp(etudiants[i].nom, etudiants[j].nom) < 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 3 && etudiants[i].note_generale < etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 4 && etudiants[i].note_generale > etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 5 && (etudiants[i].note_generale >= NOTE_REUSSITE && etudiants[j].note_generale < NOTE_REUSSITE)) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Étudiants triés avec succès!\n");
}



//----------------------------------------Fonction pour calculer la moyenne générale de la classe----------------------------------------



void calculerMoyenneGenerale() {
    float somme = 0;
    for (int i = 0; i < nombreEtudiants; i++) {
        somme += etudiants[i].note_generale;
    }

    float moyenne = (nombreEtudiants > 0) ? somme / nombreEtudiants : 0;
    printf("La moyenne générale de la classe est: %.2f\n", moyenne);
}





//----------------------------------------Fonction pour afficher les statistiques----------------------------------
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
