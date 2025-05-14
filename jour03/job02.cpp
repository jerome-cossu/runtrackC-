#include <stdio.h>

int voyelle(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
int main(){
    char phrase [] = "vive la plateforme";
    char resultat [100];
    int j = 0;

    for (int i = 0; phrase[i] != '\0'; i++){
        if (!voyelle(phrase[i])){
            resultat[j] = phrase[i];
            j++;
        }
    }
    resultat[j] = '\0';
    printf("Phrase sans voyelles : %s\n", resultat);
}