#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <algorithm>

class Pingouin {
private:
    std::string nom;
    double vitesse_glisse;
    double vitesse_marche;
    double vitesse_nage;

    Pingouin(std::string n, double glisse, double marche, double nage)
        : nom(n), vitesse_glisse(glisse), vitesse_marche(marche), vitesse_nage(nage) {}

public:
    static std::vector<std::weak_ptr<Pingouin>> colony;

    static std::shared_ptr<Pingouin> create(const std::string& nom, double glisse, double marche, double nage) {
        auto p = std::shared_ptr<Pingouin>(new Pingouin(nom, glisse, marche, nage));
        colony.push_back(p);
        trierColony();
        return p;
    }

    double calculerTempsParcours() const {
        if (vitesse_glisse <= 0 || vitesse_marche <= 0 || vitesse_nage <= 0) {
            std::cerr << "Erreur : vitesses invalides.\n";
            return -1;
        }
        return (15.0 / vitesse_glisse) + (35.0 / vitesse_marche) + (50.0 / vitesse_nage);
    }

    const std::string& getNom() const {
        return nom;
    }

    static void afficherTempsTous() {
        std::cout << "\nTemps de parcours du plus rapide au plus lent :\n";
        for (const auto& weak_p : colony) {
            if (auto p = weak_p.lock()) { 
                double t = p->calculerTempsParcours();
                if (t >= 0)
                    std::cout << std::fixed << std::setprecision(2)
                              << p->getNom() << " : " << t << " sec\n";
            }
        }
    }

private:
    static void trierColony() {
        colony.erase(std::remove_if(colony.begin(), colony.end(),
            [](const std::weak_ptr<Pingouin>& wp) { return wp.expired(); }),
            colony.end());

        std::sort(colony.begin(), colony.end(),
            [](const std::weak_ptr<Pingouin>& a, const std::weak_ptr<Pingouin>& b) {
                auto pa = a.lock();
                auto pb = b.lock();
                if (!pa || !pb) return false; 
                return pa->calculerTempsParcours() < pb->calculerTempsParcours();
            });
    }
};

std::vector<std::weak_ptr<Pingouin>> Pingouin::colony;

int main() {
    auto p1 = Pingouin::create("Pingu", 3.0, 1.5, 2.0);
    auto p2 = Pingouin::create("Pinga", 2.5, 1.0, 1.8);
    auto p3 = Pingouin::create("Pingi", 4.0, 2.0, 3.0);

    Pingouin::afficherTempsTous();

    return 0;
}
