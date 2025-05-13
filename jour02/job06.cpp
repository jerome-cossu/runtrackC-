#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Pingouin {
private:
    std::string nom;

public:
    Pingouin(const std::string& n) : nom(n) {}

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << " .\n";
    }

    static std::vector<std::string> lieux;

    static void ajouterLieu(const std::string& lieu) {
        if (std::find(lieux.begin(), lieux.end(), lieu) == lieux.end()) {
            lieux.push_back(lieu);
            std::cout << "Lieu ajoute : " << lieu << "\n";
        } else {
            std::cout << "Le lieu \"" << lieu << "\" existe deja.\n";
        }
    }

    static void retirerLieu(const std::string& lieu) {
        auto it = std::remove(lieux.begin(), lieux.end(), lieu);
        if (it != lieux.end()) {
            lieux.erase(it, lieux.end());
            std::cout << "Lieu retire : " << lieu << "\n";
        } else {
            std::cout << "Le lieu \"" << lieu << "\" n'a pas ete trouve.\n";
        }
    }

    static void afficherLieux() {
        std::cout << "\nLieux de rencontre des pingouins :\n";
        if (lieux.empty()) {
            std::cout << "Aucun lieu enregistre.\n";
        } else {
            for (const auto& lieu : lieux) {
                std::cout << "- " << lieu << "\n";
            }
        }
    }
};

std::vector<std::string> Pingouin::lieux;

int main() {
    Pingouin p1("Pingu");
    Pingouin p2("Pinga");

    p1.sePresenter();
    p2.sePresenter();

    Pingouin::ajouterLieu("Lac");
    Pingouin::ajouterLieu("Glacier");
    Pingouin::ajouterLieu("Banquise");
    Pingouin::ajouterLieu("Volcan"); 

    Pingouin::afficherLieux();

    Pingouin::retirerLieu("Glacier");
    Pingouin::retirerLieu("Volcan"); 

    Pingouin::afficherLieux();

    return 0;
}
