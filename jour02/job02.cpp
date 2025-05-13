#include <iostream>
#include <string>

class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double v = 0) : vitesse_nage(v) {}
    virtual void nage(){
        std::cout << "Je nage a " << vitesse_nage << " m/s" << std::endl;
    }
    void setVitesseNage(double v) {
        vitesse_nage = v;
    }
};
class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double v = 0) : vitesse_marche(v) {}
    virtual void marche(){
        std::cout << "Je marche a " << vitesse_marche << " m/s" << std::endl;
    }
    void setVitesseMarche(double v) {
        vitesse_marche = v;
    }
};
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesse_glisse;
public:
    Pingouin(std::string n, double v_nage, double v_marche, double v_glisse)
        : nom(n), Aquatique(v_nage), Terrestre(v_marche), vitesse_glisse(v_glisse) {}
    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesse_nage), Terrestre(autre.vitesse_marche), nom(autre.nom), vitesse_glisse(autre.vitesse_glisse) {}
    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }
    void sePresenter() {
        std::cout << "Je suis un pingouin, mon nom est " << nom << std::endl;
    }
    void nage() override {
        std::cout << "Je nage a " << vitesse_nage << " m/s" << std::endl;
    }
    void marche() override {
        std::cout << "Je marche a " << vitesse_marche << " m/s" << std::endl;
    }
    void glisse() {
        std::cout << "Et je peux glisse a " << vitesse_glisse << " m/s" << std::endl;
    }
};
int main() {
    Pingouin p("Pingu", 2.0, 1.0, 3.0);
    p.sePresenter();
    p.nage();
    p.marche();
    p.glisse();

    Pingouin p2("Pinga", 3.0, 1.5, 4.0);
    p2.sePresenter();
    p2.setVitesseGlisse(4.5);
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}
