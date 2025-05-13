#include <iostream>
#include <cmath>

int main() {
    int N;
    long long somme = 0;

    std::cout << "Entrez un entier Nv(>=5) : ";
    std::cin >> N;

    if (N < 5){
        std::cout << "Erreur: N doit etre superieur ou egal a 5." << std::endl;
        return 1;
    }

    for (int i = 5; i <= N; i++) {
        somme += std::pow(i, 3);
    }

    std::cout << "La somme des cubes de 5^3 a " << N << "^3 est : " << somme << std::endl;

    return 0;
}