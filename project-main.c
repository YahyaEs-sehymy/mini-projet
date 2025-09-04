#include <stdio.h>
#include <string.h>

#define MAX 100

char titres[MAX][50];
char auteurs[MAX][50];
float prix[MAX];
int quantite[MAX];

int nomberliver = 0;

// Ajouter un Livre 
void ajouterLivre() {   
    if (nomberliver < MAX) {
        printf("Titre du livre : ");
        scanf(" %[^\n]", titres[nomberliver]);  

        printf("Auteur du livre : ");
        scanf(" %[^\n]", auteurs[nomberliver]);

        printf("Prix du livre : ");
        scanf("%f", &prix[nomberliver]);

        printf("Quantite en stock : ");
        scanf("%d", &quantite[nomberliver]);

        nomberliver++;
        printf("Livre ajoute avec succes !\n");
    } else {
        printf("Stock plein.\n");
    }
}

// Afficher Tous les Livres 
void afficherLivres() {
    if (nomberliver == 0) {
        printf("Aucun livre en stock.\n");
    } else {
        for (int i = 0; i < nomberliver; i++) {
            printf("%d. Titre: %s | Auteur: %s | Prix: %.2f dh | Quantite: %d\n",
                   i+1, titres[i], auteurs[i], prix[i], quantite[i]);
        }
    }
}

// Rechercher un Livre 
void rechercherLivre() {
    char titre[50];
    printf("Titre a rechercher : ");
    scanf(" %[^\n]", titre);   

    for (int i = 0; i < nomberliver; i++) {
        if (strcmp(titres[i], titre) == 0) {
            printf("Livre trouve : %s | %s | %.2f dh | Quantite: %d\n",
                   titres[i], auteurs[i], prix[i], quantite[i]);
            return;
        }
    }
    printf("Livre non trouve.\n");
}

// Mettre à Jour 
void mettreAJour() {
    char titre[50];
    int quntite;
    float prixn;

    printf("Titre a mettre a jour : ");
    scanf(" %[^\n]", titre);

    for (int i = 0; i < nomberliver; i++) {
        if (strcmp(titres[i], titre) == 0) {
            printf("Nouvelle quantite : ");
            scanf("%d", &quntite);
            quantite[i] = quntite;

            printf("Nouveau prix : ");
            scanf("%f", &prixn);
            prix[i] = prixn;

            printf("Quantite et prix mis a jour.\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}

// Supprimer
void supprimerLivre() {
    char titre[50];
    printf("Titre a supprimer : ");
    scanf(" %[^\n]", titre);

    for (int i = 0; i < nomberliver; i++) {
        if (strcmp(titres[i], titre) == 0) {
            for (int j = i; j < nomberliver - 1; j++) {
                strcpy(titres[j], titres[j+1]);
                strcpy(auteurs[j], auteurs[j+1]);
                prix[j] = prix[j+1];
                quantite[j] = quantite[j+1];
            }
            nomberliver--;
            printf("Livre supprime.\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}

void afficherNombreLivres() {
    int total = 0;
    for (int i = 0; i < nomberliver; i++) {
        total += quantite[i];
    }
    printf("Nombre total de livres en stock : %d\n", total);
}


int main() {
    int choix;
    do {
        printf("\n== MENU ==\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Mettre a jour un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 3: rechercherLivre(); break;
            case 4: mettreAJour(); break;
            case 5: supprimerLivre(); break;
            case 6: afficherNombreLivres(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}
