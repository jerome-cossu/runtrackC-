#include <iostream>
using namespace std;

int main(){
    const int taille_max = 100;
    char tab[taille_max];

    cout << "Entrer une chaine de caracteres : " << endl;
    cin.getline(tab, taille_max);

    int i = 0;
    while (tab[i] != '\0'){
        i++;
    }

    tab[i] = '\0';
    cout << "Contenu du tableau : "<< tab << endl;

    return 0;
}