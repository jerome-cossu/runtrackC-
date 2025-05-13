#include <iostream>

int main() {
    int nombre;
    double somme = 0;

    std::cout <<"Entrez 5 entiers : " << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> nombre;
        somme += nombre;
    }

    double moyenne = somme / 5;
    std::cout << "La moyenne est : " << moyenne << std::endl;

    return 0;
}