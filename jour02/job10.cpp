#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <memory>
#include <algorithm>
#include <list>
#include <set>

class Pingouin : public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;

    std::map<std::string, int> competences;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;
    std::multiset<double> tempsCompetitions;  // 🆕 Multiset des temps

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

    void ajouterTemps(double temps) {
        tempsCompetitions.insert(temps);
        std::cout << "Temps ajoute pour " << nom << " : " << temps << " s\n";
    }

    void afficherTemps() const {
        std::cout << "\nTemps de competition pour " << nom << " ordre croissant :\n";
        if (tempsCompetitions.empty()) {
            std::cout << "Aucun temps enregistre.\n";
        } else {
            for (double t : tempsCompetitions) {
                std::cout << "- " << t << " s\n";
            }
        }
    }

};

int main() {
    auto p1 = std::make_shared<Pingouin>("Pingu");

    p1->ajouterTemps(12.3);
    p1->ajouterTemps(11.7);
    p1->ajouterTemps(13.0);
    p1->ajouterTemps(11.7); 

    p1->afficherTemps();

    return 0;
}
