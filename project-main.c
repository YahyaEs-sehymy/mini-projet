#include <stdio.h>

#define MAX 100

char titres[MAX][50];
char auteurs[MAX][50];
float prix[MAX];
int quantite[MAX];

int nomberliver = 0;

void ajouterLivre() {
    if (nomberliver < MAX) {
        printf("Titre du livre : ");
        scanf("%s", titres[nomberliver]);  

        printf("Auteur du livre : ");
        scanf("%s", auteurs[nomberliver]);  

        printf("Prix du livre : ");
        scanf("%f", &prix[nomberliver]);

        printf("Quantite en stock : ");
        scanf("%d", &quantite[nomberliver]);

        nomberliver++;
        printf(" Livre ajoute avec succes !\n");
    } else {
        printf(" Stock plein.\n");
    }
}

void afficherLivres() {
    if (nomberliver == 0) {
        printf(" Aucun livre en stock.\n");
    } else {
        for (int i = 0; i < nomberliver; i++) {
            printf("%d. titre: %s | Auteur: %s | Prix: %.2f dh | Quantite: %d\n",
                   i+1, titres[i], auteurs[i], prix[i], quantite[i]);
        }
    }
}

int main() {
    int choix;
    do {
        printf("\n== MENU ==\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}
