#include <iostream>
#include <string>
#include <unordered_set>
#include <memory>

class Pingouin : public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    std::unordered_set<std::string> emplacementsTreso; 

public:
    Pingouin(const std::string& n) : nom(n) {}
    ~Pingouin() {
        std::cout << "Destruction du pingouin : " << nom << "\n";
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << " .\n";
    }

    void ajouterEmplacementTreso(const std::string& lieu) {
        if (emplacementsTreso.insert(lieu).second) {
            std::cout << "Emplacement ajoute : " << lieu << "\n";
        } else {
            std::cout << "Lieu dejà present : " << lieu << "\n";
        }
    }

    void supprimerEmplacementTreso(const std::string& lieu) {
        if (emplacementsTreso.erase(lieu)) {
            std::cout << "Emplacement supprime : " << lieu << "\n";
        } else {
            std::cout << "Lieu non trouve : " << lieu << "\n";
        }
    }

    void listerEmplacementsTreso() const {
        std::cout << "\nEmplacements de tresor pour " << nom << " :\n";
        if (emplacementsTreso.empty()) {
            std::cout << "Aucun emplacement enregistre.\n";
        } else {
            for (const auto& lieu : emplacementsTreso) {
                std::cout << "- " << lieu << "\n";
            }
        }
    }
};

int main() {
    auto p = std::make_shared<Pingouin>("Pingu");

    p->sePresenter();

    p->ajouterEmplacementTreso("Grotte secrete");
    p->ajouterEmplacementTreso("Glacier abandonne");
    p->ajouterEmplacementTreso("Epave engloutie");

    p->listerEmplacementsTreso();

    p->supprimerEmplacementTreso("Glacier abandonne");

    p->listerEmplacementsTreso();

    return 0;
}
