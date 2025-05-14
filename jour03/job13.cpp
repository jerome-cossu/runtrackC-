#include <iostream>
using namespace std;

int main(){
    int tab1[] = {1, 13, 9, 4, 6};
    int tab2[] = {12, 2, 7, 11, 10};
    const int TAILLE = sizeof(tab1) / sizeof(tab1[0]);
    const int TAILLE2 = sizeof(tab2) / sizeof(tab2[0]);
    int fusion[TAILLE + TAILLE2];

    int i = 0, j = 0, k = 0;

    while (i < TAILLE && j < TAILLE2) {
        if (tab1[i] < tab2[j]) {
            fusion[k++] = tab1[i++];
        } else {
            fusion[k++] = tab2[j++];
        }
    }
    while (i < TAILLE) {
        fusion[k++] = tab1[i++];
    }
    while (j < TAILLE2) {
        fusion[k++] = tab2[j++];
    }
    cout << "Tableau fusionne : ";
    for (int l = 0; l < TAILLE + TAILLE2; l++){
        cout << fusion[l] << " ";
    }
    cout << endl;
    return 0;
}