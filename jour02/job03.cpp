#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Aquatique {
protected:
    double vitesse_nage;
public:
    Aquatique(double v_nage = 0.0) : vitesse_nage(v_nage) {}
    virtual void nage() const {
        std::cout << "Je nage a " << vitesse_nage << " m/s." << std::endl;
    }
    void setVitesseNage(double v) { vitesse_nage = v; }
    virtual ~Aquatique() {}
};

class Terrestre {
protected:
    double vitesse_marche;
public:
    Terrestre(double v_marche = 0.0) : vitesse_marche(v_marche) {}
    virtual void marche() const {
        std::cout << "Je marche a " << vitesse_marche << " m/s." << std::endl;
    }
    void setVitesseMarche(double v) { vitesse_marche = v; }
    virtual ~Terrestre() {}
};

class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesse_glisse;
public:
    static std::vector<std::weak_ptr<Pingouin>> tous_les_pingouins;

    Pingouin(std::string n, double v_nage = 0.0, double v_marche = 0.0, double v_glisse = 0.0)
        : Aquatique(v_nage), Terrestre(v_marche), nom(n), vitesse_glisse(v_glisse) {}

    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesse_nage),
          Terrestre(autre.vitesse_marche),
          nom(autre.nom),
          vitesse_glisse(autre.vitesse_glisse) {}

    void sePresenter() const {
        std::cout << "Bonjour, je suis " << nom << "." << std::endl;
    }

    void glisse() const {
        std::cout << "Je glisse a " << vitesse_glisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }

    static std::shared_ptr<Pingouin> creer(const std::string& nom, double v_nage, double v_marche, double v_glisse) {
        auto p = std::shared_ptr<Pingouin>(new Pingouin(nom, v_nage, v_marche, v_glisse));
        tous_les_pingouins.push_back(p);
        return p;
    }

    ~Pingouin() {
        std::cout << "Destruction du pingouin : " << nom << std::endl;
    }

    static void nettoyerPingouins() {
        tous_les_pingouins.erase(
            std::remove_if(
                tous_les_pingouins.begin(),
                tous_les_pingouins.end(),
                [](const std::weak_ptr<Pingouin>& wp) { return wp.expired(); }
            ),
            tous_les_pingouins.end()
        );
    }
};

std::vector<std::weak_ptr<Pingouin>> Pingouin::tous_les_pingouins;

int main() {
    {
        auto p1 = Pingouin::creer("Pingu", 2.5, 1.0, 3.0);
        auto p2 = Pingouin::creer("Pinga", 2.0, 0.8, 2.5);

        std::cout << "\nListe des pingouins vivants :\n";
        for (const auto& weak_p : Pingouin::tous_les_pingouins) {
            if (auto p = weak_p.lock()) {
                p->sePresenter();
            }
        }

        std::cout << "\nLes pingouins vont etre detruits automatiquement...\n";
    }

    Pingouin::nettoyerPingouins();

    std::cout << "\nListe après destruction :\n";
    for (const auto& weak_p : Pingouin::tous_les_pingouins) {
        if (auto p = weak_p.lock()) {
            p->sePresenter(); 
        }
    }

    return 0;
}
