#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 10;
    int tableau[TAILLE] = {1, 8, 12, 4, 3, 8, 19, 5, 7, 2};
    int somme = 0;

    for (int i = 0; i < TAILLE; i++){
        if (tableau[i] % 2 == 0){
            somme += tableau[i];
        }
    }

    cout << "La somme des nombres pairs est : " << somme << endl;
    return 0;
}