#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Pingouin {
private:
    std::string nom;
    std::map<std::string, int> competences;

public:
    Pingouin(const std::string& n) : nom(n) {}

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << " .\n";
    }

    void ajouterCompetence(const std::string& nom_comp, int niveau) {
        if (competences.find(nom_comp) == competences.end()) {
            competences[nom_comp] = niveau;
            std::cout << "Competence ajoutee : " << nom_comp << " (niveau " << niveau << ")\n";
        } else {
            std::cout << "La competence \"" << nom_comp << "\" existe dejà.\n";
        }
    }

    void modifierCompetence(const std::string& nom_comp, int nouveau_niveau) {
        auto it = competences.find(nom_comp);
        if (it != competences.end()) {
            it->second = nouveau_niveau;
            std::cout << "Competence modifiee : " << nom_comp << " niveau " << nouveau_niveau << "\n";
        } else {
            std::cout << "La competence \"" << nom_comp << "\" existe pas.\n";
        }
    }

    void supprimerCompetence(const std::string& nom_comp) {
        auto it = competences.find(nom_comp);
        if (it != competences.end()) {
            competences.erase(it);
            std::cout << "Competence supprimee : " << nom_comp << "\n";
        } else {
            std::cout << "Impossible de supprimer : \"" << nom_comp << "\" existe pas.\n";
        }
    }

    void afficherCompetences() const {
        std::cout << "\nCompetences de " << nom << " :\n";
        if (competences.empty()) {
            std::cout << "Aucune competence enregistree.\n";
        } else {
            for (const auto& [nom_comp, niveau] : competences) {
                std::cout << "- " << nom_comp << " : niveau " << niveau << "\n";
            }
        }
    }
};

int main() {
    Pingouin p1("Pingu");

    p1.sePresenter();

    p1.ajouterCompetence("plongee", 3);
    p1.ajouterCompetence("peche", 5);
    p1.ajouterCompetence("glissade", 4);

    p1.afficherCompetences();

    p1.modifierCompetence("plongee", 4);
    p1.supprimerCompetence("peche");

    p1.afficherCompetences();

    return 0;
}
