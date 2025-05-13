#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <cstdlib>
#include <ctime>   

class Pingouin : public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    std::unordered_set<std::string> tresorsTrouves;

public:
    static std::unordered_map<std::string, std::string> lieuxEtTresors;

    Pingouin(const std::string& nom) : nom(nom) {
        std::srand(std::time(nullptr)); 
    }

    ~Pingouin() {
        std::cout << "Destruction du pingouin : " << nom << "\n";
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << " .\n";
    }

    void visiterLieu(const std::string& lieu) {
        std::cout << nom << " visite le lieu : " << lieu << "\n";

        auto it = lieuxEtTresors.find(lieu);
        if (it != lieuxEtTresors.end()) {
            std::string tresor = it->second;

            if (std::rand() % 2 == 0) {
                std::cout << nom << " a trouve le tresor : " << tresor << " !\n";
                tresorsTrouves.insert(tresor);
            } else {
                std::cout << "Pas de tresor cette fois.\n";
            }
        } else {
            std::cout << "Aucun tresor n'est connu pour ce lieu.\n";
        }
    }

    void afficherTresorsTrouves() const {
        std::cout << "Tresors de " << nom << " : ";
        if (tresorsTrouves.empty()) {
            std::cout << "aucun.\n";
        } else {
            for (const auto& t : tresorsTrouves) {
                std::cout << t << " ";
            }
            std::cout << "\n";
        }
    }
};

std::unordered_map<std::string, std::string> Pingouin::lieuxEtTresors = {
    {"glacier", "perle de givre"},
    {"grotte mysterieuse", "amulette oubliee"},
    {"epave", "coquillage en or"},
    {"volcan gele", "cristal maudit"}
};

int main() {
    auto tux = std::make_shared<Pingouin>("Pingu");

    tux->sePresenter();

    tux->visiterLieu("glacier");
    tux->visiterLieu("epave");
    tux->visiterLieu("foret gelee"); 

    tux->afficherTresorsTrouves();

    return 0;
}
