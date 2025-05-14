#include <iostream>
#include <string>
using namespace std;

int main() {
    string string, string2 = "Bonjour";
    cout << "Entrer une chaine de caracteres : ";
    getline(cin, string);

    cout << "Chaine de caracteres dans l'ordre alphabetique : " << endl;

    if (string < string2){
        cout << string << endl;
        cout << string2 << endl;
    } else {
        cout << string2 << endl;
        cout << string << endl;
    }
    return 0;
}