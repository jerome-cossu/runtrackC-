#include <iostream>
#include <string>
using namespace std;

bool estPalindrome(string mot) {
    int debut = 0;
    int fin = mot.length() - 1;

    while (debut < fin) {
        if (mot[debut] != mot[fin]) {
            return false;
        }
        debut++;
        fin--;
    }
    return true;
}
int main(){
    string tab[5] = {"kayak", "radar", "hello", "world", "level"};
    int taille = sizeof(tab) / sizeof(tab[0]);
    cout << "Les mots palindromes sont : ";
    for (int i = 0; i < taille; i++) {
        if (estPalindrome(tab[i])) {
            cout << tab[i] << " ";
        }
    }
    return 0;
}