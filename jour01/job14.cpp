#include <iostream>

int main() {
    int nombre, inverse = 0;
    std::cout << "Entrez un entier : ";
    std::cin >> nombre;

    int original = nombre;

    while (nombre != 0) {
        int chiffre = nombre % 10;
        inverse = inverse * 10 + chiffre;
        nombre /= 10;
    }
    std::cout << "L'inverse de " << original << " est : " << inverse << std::endl;

    return 0;
}