#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>

class Pingouin : public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    std::map<std::string, int> competences;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;

public:
    Pingouin(const std::string& n) : nom(n) {}
    ~Pingouin() {
        std::cout << "Destruction du pingouin : " << nom << "\n";
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << " .\n";
    }

    std::string getNom() const {
        return nom;
    }

    void ajouterAmi(std::shared_ptr<Pingouin> autre) {
        if (autre.get() == this) {
            std::cout << "Un pingouin ne peut pas etre son propre ami !\n";
            return;
        }

        amis.insert(autre);
        std::cout << nom << " est maintenant ami avec " << autre->nom << "\n";
    }

    void retirerAmi(std::shared_ptr<Pingouin> autre) {
        auto it = amis.find(autre);
        if (it != amis.end()) {
            amis.erase(it);
            std::cout << nom << " est plus ami avec " << autre->nom << "\n";
        } else {
            std::cout << autre->nom << " est pas un ami de " << nom << "\n";
        }
    }

    void afficherAmis() const {
        std::cout << "\nAmis de " << nom << " :\n";
        if (amis.empty()) {
            std::cout << "Aucun ami.\n";
        } else {
            for (const auto& ami_weak : amis) {
                if (auto ami = ami_weak.lock()) {
                    std::cout << "- " << ami->nom << "\n";
                }
            }
        }
    }
};

int main() {
    auto p1 = std::make_shared<Pingouin>("Pingi");
    auto p2 = std::make_shared<Pingouin>("Pingu");
    auto p3 = std::make_shared<Pingouin>("Pinga");

    p1->ajouterAmi(p2);
    p1->ajouterAmi(p3);
    p1->ajouterAmi(p1); 

    p1->afficherAmis();

    p1->retirerAmi(p3);
    p1->retirerAmi(p3); 

    p1->afficherAmis();

    return 0;
}
