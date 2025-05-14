#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int mystere, proposition;
    const int MAX_TENTATATIVES = 7; 
    int tentatives = 0;

    srand(time(0));
    mystere = rand() % 101;

    cout << "Je pense a un nombre entre 0 et 100. A vous de deviner !" << endl;
    cout << "Vous avez " << MAX_TENTATATIVES << " tentatives." << endl;

    while (tentatives < MAX_TENTATATIVES){
        cout << "\nTentative n " << tentatives + 1 << ": ";
        cin >> proposition;
    
        if (proposition == mystere) {
            cout << "Bravo ! Vous avez trouve le nombre mystere !" << endl;
            return 0;
        } else if (proposition < mystere) {
            cout << "Trop petit ! Essayez encore." << endl;
        } else {
            cout << "Trop grand ! Essayez encore." << endl;
        }
        tentatives++;
    }
    cout << "Desole, vous avez epuise vos tentatives. Le nombre mystere etait " << mystere << "." << endl;
    return 0;

}