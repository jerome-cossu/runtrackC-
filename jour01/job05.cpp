#include <iostream>

int main(){
    double num1, num2, product;
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;
    std::cout << "Entrez le deuxieme nombre: ";
    std::cin >> num2;
    product = num1 * num2;
    std::cout << "Le produit de " << num1 << " et " << num2 << " est: " << product << std::endl;
    return 0;
}