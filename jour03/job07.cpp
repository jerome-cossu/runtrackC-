#include <iostream>
using namespace std;

int main(){
    const int taille = 11;
    int T[taille];
    int max = 0;
    int indice_max = 0;

    cout << "Entrez 10 entiers : " << endl;
    for (int i = 1; i < taille; i++) {
        cout << "Entier n " << i << ": ";
        cin >> T[i];

        if (T[i] > max) {
            max = T[i];
            indice_max = i;
        }
        else if (T[i] > max) {
            max = T[i];
            indice_max = i;
        }
    }

    cout << "L'indice du plus grand element est : " << indice_max << endl;
    return 0;
}