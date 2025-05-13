#include <iostream>

int main(){
    double prixHT;
    double quantite;
    double tvaPourcentage;

    std::cout << "Entrez le prix HT : ";
    std::cin >> prixHT;
    std::cout << "Entrez la quantite : ";
    std::cin >> quantite;
    std::cout << "Entrez le pourcentage de TVA : ";
    std::cin >> tvaPourcentage;

    double totalHT = prixHT * quantite;

    double tva = tvaPourcentage / 100;

    double totalTTC = totalHT * (1 + tva);
    std::cout << "Le total TTC est : " << totalTTC << " EUR " << std::endl;

    return 0;
}