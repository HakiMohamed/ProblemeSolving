#include <stdio.h>
#include "gestion_etudiants.h"
#include "statistiques.h"
#include "tri_recherche.h"

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
