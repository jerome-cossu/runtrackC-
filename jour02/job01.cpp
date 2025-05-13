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
    
};

class Terrestre {
protected:
    double vitesse_marche;
public:
    Terrestre(double v = 0) : vitesse_marche(v) {}
    virtual void marche(){
        std::cout << "Je marche a " << vitesse_marche << " m/s" << std::endl;
    }
};

class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
public:
    Pingouin(std::string n, double v_nage, double v_marche) 
        : nom(n), Aquatique(v_nage), Terrestre(v_marche) {}
    
    void sePresenter() {
        std::cout << "Je suis un pingouin, mon nom est " << nom << std::endl;
    }
    void nage() override {
        std::cout << "Je nage a " << vitesse_nage << " m/s" << std::endl;
    }
    void marche() override {
        std::cout << "Et je marche a " << vitesse_marche << " m/s" << std::endl;
    }
};
int main() {
    Pingouin p("Pingu", 2.0, 1.0);
    p.sePresenter();
    p.nage();
    p.marche();
    
    return 0;
}