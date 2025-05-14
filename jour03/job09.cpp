#include <iostream>
#include <string>
using namespace std;

bool estincluse (const string& petite, const string& grande){
    return grande.find(petite) != string::npos;
}

int main(){
    string chaine1, chaine2;
    cout << "Entrer la premiere chaine de caracteres : ";
    getline(cin, chaine1);
    cout << "Entrer la deuxieme chaine de caracteres : ";
    getline(cin, chaine2);
    if (estincluse(chaine1, chaine2)){
        cout << "La premiere chaine est incluse dans la deuxieme." << endl;
    } else {
        cout << "La premiere chaine n'est pas incluse dans la deuxieme." << endl;
    }

    return 0;
}
