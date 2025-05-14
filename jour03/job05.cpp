#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char saisie[10];

    printf("Entrez une heure au format XXhXX : ");
    fgets(saisie, sizeof(saisie), stdin);
    saisie[strcspn(saisie, "\n")] = '\0';

    saisie[strcspn(saisie, "\n")] = '\0';

    if (strlen(saisie) == 5 &&
        isdigit(saisie[0]) &&
        isdigit(saisie[1]) &&
        saisie[2] == 'h' or 'H' &&
        isdigit(saisie[3]) &&
        isdigit(saisie[4])) {
        printf("Heure valide\n");
    } else {
        printf("Heure invalide\n");
    }
    return 0;
}