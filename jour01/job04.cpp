#include <iostream>

int main(){
    double num1, num2, somme;
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;
    std::cout << "Entrez le deuxieme nombre: ";
    std::cin >> num2;
    somme = num1 + num2;
    std::cout << "La somme de " << num1 << " et " << num2 << " est: " << somme << std::endl;
    return 0;
}