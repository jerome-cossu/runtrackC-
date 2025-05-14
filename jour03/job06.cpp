#include <iostream>
using namespace std;

int main(){
    const int taille = 11;
    int T[taille];
    int compteur = 1;

    cout << "Entrez 10 entiers : " << endl;
    for (int i = 1; i < taille; i++) {
        cout << "T[" << i << "] : ";
        cin >> T[i];

        if (T[i] >= 5) {
            compteur++;
        }
    }

    cout << "Nombre dentiers superieurs ou egaux a 5 : " << compteur << endl;

    return 0;
}
