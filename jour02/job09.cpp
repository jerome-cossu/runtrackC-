#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <memory>
#include <algorithm>

class Pingouin : public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;

    std::map<std::string, int> competences;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;  // 🆕 journal : date => evenement

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

    void ajouterCompetence(const std::string& nom, int niveau) {
        competences[nom] = niveau;
    }

    void ajouterAmi(std::shared_ptr<Pingouin> autre) {
        if (autre.get() == this) {
            std::cout << "Un pingouin ne peut pas être son propre ami !\n";
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

    void ajouterEvenement(const std::string& date, const std::string& description) {
        journal[date] = description;
        std::cout << "Evenement ajoute pour " << nom << " a la date " << date << "\n";
    }

    void modifierEvenement(const std::string& date, const std::string& nouvelleDescription) {
        if (journal.find(date) != journal.end()) {
            journal[date] = nouvelleDescription;
            std::cout << "Evenement modifie a la date " << date << "\n";
        } else {
            std::cout << "Aucun evenement trouve a la date " << date << "\n";
        }
    }

    void supprimerEvenement(const std::string& date) {
        if (journal.erase(date)) {
            std::cout << "Evenement supprime pour la date " << date << "\n";
        } else {
            std::cout << "Aucun evenement a supprimer pour la date " << date << "\n";
        }
    }

    void afficherJournal() const {
        std::cout << "\nJournal de " << nom << " :\n";
        if (journal.empty()) {
            std::cout << "Aucune entree dans le journal.\n";
        } else {
            for (const auto& [date, description] : journal) {
                std::cout << "- " << date << " : " << description << "\n";
            }
        }
    }
};

int main() {
    auto p1 = std::make_shared<Pingouin>("Tux");

    p1->ajouterEvenement("2025-05-13", "Un nouveau glacier a etait decouvert.");
    p1->ajouterEvenement("2025-05-14", "Glissade spectaculaire !");
    p1->afficherJournal();

    p1->modifierEvenement("2025-05-14", "Glissade record de 50m !");
    p1->supprimerEvenement("2025-05-13");

    p1->afficherJournal();

    return 0;
}
