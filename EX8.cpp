#include <iostream>
#include <string>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    // 1. Constructeur par défaut
    Voiture() {
        marque = "Inconnue";
        modele = "Inconnu";
        annee = 2000;
        kilometrage = 0.0;
        vitesse = 0.0;
    }
    
    // 2. Constructeur avec paramètres
    Voiture(string m, string mod, int a, float km, float v) {
        marque = m;
        modele = mod;
        annee = a;
        kilometrage = km;
        vitesse = v;
    }
    
    // 3. Méthode accelerer
    void accelerer(float valeur) {
        vitesse += valeur;
        cout << "Acceleration de " << valeur << " km/h" << endl;
    }
    
    // 4. Méthode freiner
    void freiner(float valeur) {
        vitesse -= valeur;
        if (vitesse < 0) {
            vitesse = 0;
        }
        cout << "Freinage de " << valeur << " km/h" << endl;
    }
    
    // 5. Méthode afficherInfo
    void afficherInfo() {
        cout << "===== Informations de la voiture =====" << endl;
        cout << "Marque      : " << marque << endl;
        cout << "Modele      : " << modele << endl;
        cout << "Annee       : " << annee << endl;
        cout << "Kilometrage : " << kilometrage << " km" << endl;
        cout << "Vitesse     : " << vitesse << " km/h" << endl;
        cout << "======================================" << endl;
    }
    
    // 6. Méthode avancer
    void avancer(float distance) {
        kilometrage += distance;
        cout << "Distance parcourue : " << distance << " km" << endl;
    }
    
    // 7. Destructeur
    ~Voiture() {
        cout << "La voiture " << marque << " " << modele << " est detruite" << endl;
    }
};

// Programme principal pour tester
int main() {
    cout << "=== Creation voiture 1 (constructeur par defaut) ===" << endl;
    Voiture voiture1;
    voiture1.afficherInfo();
    cout << endl;
    
    cout << "=== Creation voiture 2 (constructeur avec parametres) ===" << endl;
    Voiture voiture2("Toyota", "Corolla", 2020, 15000.0, 0.0);
    voiture2.afficherInfo();
    cout << endl;
    
    cout << "=== Test des methodes sur voiture2 ===" << endl;
    voiture2.accelerer(50.0);
    voiture2.accelerer(30.0);
    cout << endl;
    
    voiture2.afficherInfo();
    cout << endl;
    
    voiture2.freiner(20.0);
    cout << endl;
    
    voiture2.avancer(100.0);
    voiture2.avancer(50.5);
    cout << endl;
    
    voiture2.afficherInfo();
    cout << endl;
    
    cout << "=== Test freinage excessif ===" << endl;
    voiture2.freiner(200.0);
    voiture2.afficherInfo();
    cout << endl;
    
    cout << "=== Fin du programme ===" << endl;
    
    return 0;
}
