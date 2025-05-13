#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

class Pingouin {
private:
    std::string nom;
    double vitesse_glisse;
    double vitesse_marche;
    double vitesse_nage;

    Pingouin(std::string n, double glisse, double marche, double nage)
        : nom(n), vitesse_glisse(glisse), vitesse_marche(marche), vitesse_nage(nage) {}

public:
    static std::vector<std::weak_ptr<Pingouin>> liste_pingouins;

    static std::shared_ptr<Pingouin> create(const std::string& nom, double glisse, double marche, double nage) {
        auto p = std::shared_ptr<Pingouin>(new Pingouin(nom, glisse, marche, nage));
        liste_pingouins.push_back(p);
        return p;
    }

    double calculerTempsParcours() const {
        if (vitesse_glisse <= 0 || vitesse_marche <= 0 || vitesse_nage <= 0) {
            std::cerr << "Erreur : les vitesses doivent être > 0.\n";
            return -1;
        }

        double temps_glisse = 15.0 / vitesse_glisse;
        double temps_marche = (20.0 + 15.0) / vitesse_marche;
        double temps_nage = 50.0 / vitesse_nage;

        return temps_glisse + temps_marche + temps_nage;
    }

    const std::string& getNom() const {
        return nom;
    }

    static void afficherTempsTous() {
        std::cout << "\nTemps de parcours des pingouins :\n";
        for (const auto& weak_p : liste_pingouins) {
            if (auto p = weak_p.lock()) {
                double temps = p->calculerTempsParcours();
                if (temps >= 0)
                    std::cout << std::fixed << std::setprecision(2)
                              << p->getNom() << " : " << temps << " secondes\n";
            }
        }
    }
};

std::vector<std::weak_ptr<Pingouin>> Pingouin::liste_pingouins;

int main() {
    auto p1 = Pingouin::create("Pingu", 3.0, 1.5, 2.0);
    auto p2 = Pingouin::create("Pinga", 2.5, 1.0, 1.8);
    auto p3 = Pingouin::create("Pingi", 4.0, 2.0, 3.0);

    Pingouin::afficherTempsTous();

    return 0;
}
