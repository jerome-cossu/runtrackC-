#include <stdio.h>
#include <string.h>

int main() {
    char chaine1[100];
    char chaine2[100];

    printf("Entrez la premiere chaine de caracteres : ");
    fgets(chaine1, sizeof(chaine1), stdin);

    printf("Entrez la deuxieme chaine de caracteres : ");
    fgets(chaine2, sizeof(chaine2), stdin);

    chaine1[strcspn(chaine1, "\n")] = '\0'; 
    chaine2[strcspn(chaine2, "\n")] = '\0';

    if (strcmp(chaine1, chaine2) == 0) {
        printf("Les chaines sont egales. Retour : 0\n");
        return 0;
    } else {
        printf("Les chaines sont differentes. Retour : 1\n");
        return 1;
    }

}