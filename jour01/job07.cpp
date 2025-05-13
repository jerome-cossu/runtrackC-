#include <iostream>

int main (){
    int nombre;
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;

    if (nombre % 2 == 0) {
        std::cout << nombre << " est un nombre pair." << std::endl;
    } else {
        std::cout << nombre << " est un nombre impair." << std::endl;
    }
    return 0;
}