#include <iostream>
using namespace std;

class Complexe {
private:
    float reel;
    float imaginaire;

public:
    // Constructeur par défaut
    Complexe(float r = 0, float i = 0) {
        reel = r;
        imaginaire = i;
    }
    
    // Méthode pour saisir un nombre complexe
    void saisir() {
        cout << "Entrez la partie reelle : ";
        cin >> reel;
        cout << "Entrez la partie imaginaire : ";
        cin >> imaginaire;
    }
    
    // Méthode pour afficher un nombre complexe
    void afficher() {
        if (imaginaire >= 0) {
            cout << reel << " + " << imaginaire << "i";
        } else {
            cout << reel << " - " << (-imaginaire) << "i";
        }
    }
    
    // Test d'égalité
    bool egal(Complexe c) {
        return (reel == c.reel && imaginaire == c.imaginaire);
    }
    
    // Addition
    Complexe addition(Complexe c) {
        Complexe resultat;
        resultat.reel = reel + c.reel;
        resultat.imaginaire = imaginaire + c.imaginaire;
        return resultat;
    }
    
    // Soustraction
    Complexe soustraction(Complexe c) {
        Complexe resultat;
        resultat.reel = reel - c.reel;
        resultat.imaginaire = imaginaire - c.imaginaire;
        return resultat;
    }
    
    // Multiplication
    Complexe multiplication(Complexe c) {
        Complexe resultat;
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        resultat.reel = (reel * c.reel) - (imaginaire * c.imaginaire);
        resultat.imaginaire = (reel * c.imaginaire) + (imaginaire * c.reel);
        return resultat;
    }
    
    // Division
    Complexe division(Complexe c) {
        Complexe resultat;
        float denominateur = (c.reel * c.reel) + (c.imaginaire * c.imaginaire);
        
        if (denominateur == 0) {
            cout << "Erreur : Division par zero !" << endl;
            return resultat;
        }
        
        // (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
        resultat.reel = ((reel * c.reel) + (imaginaire * c.imaginaire)) / denominateur;
        resultat.imaginaire = ((imaginaire * c.reel) - (reel * c.imaginaire)) / denominateur;
        return resultat;
    }
};

// Fonction pour afficher le menu
void afficherMenu() {
    cout << "\n========== MENU OPERATIONS COMPLEXES ==========" << endl;
    cout << "1. Tester l'egalite" << endl;
    cout << "2. Addition" << endl;
    cout << "3. Soustraction" << endl;
    cout << "4. Multiplication" << endl;
    cout << "5. Division" << endl;
    cout << "6. Quitter" << endl;
    cout << "===============================================" << endl;
    cout << "Votre choix : ";
}

int main() {
    Complexe c1, c2, resultat;
    int choix;
    
    cout << "=== Saisie du premier nombre complexe ===" << endl;
    c1.saisir();
    
    cout << "\n=== Saisie du deuxieme nombre complexe ===" << endl;
    c2.saisir();
    
    cout << "\nNombres complexes saisis :" << endl;
    cout << "c1 = "; c1.afficher(); cout << endl;
    cout << "c2 = "; c2.afficher(); cout << endl;
    
    do {
        afficherMenu();
        cin >> choix;
        cout << endl;
        
        switch(choix) {
            case 1:
                cout << "=== TEST D'EGALITE ===" << endl;
                cout << "c1 = "; c1.afficher(); cout << endl;
                cout << "c2 = "; c2.afficher(); cout << endl;
                if (c1.egal(c2)) {
                    cout << "Resultat : c1 et c2 sont EGAUX" << endl;
                } else {
                    cout << "Resultat : c1 et c2 sont DIFFERENTS" << endl;
                }
                break;
                
            case 2:
                cout << "=== ADDITION ===" << endl;
                resultat = c1.addition(c2);
                cout << "("; c1.afficher(); cout << ") + ("; c2.afficher(); cout << ") = ";
                resultat.afficher(); cout << endl;
                break;
                
            case 3:
                cout << "=== SOUSTRACTION ===" << endl;
                resultat = c1.soustraction(c2);
                cout << "("; c1.afficher(); cout << ") - ("; c2.afficher(); cout << ") = ";
                resultat.afficher(); cout << endl;
                break;
                
            case 4:
                cout << "=== MULTIPLICATION ===" << endl;
                resultat = c1.multiplication(c2);
                cout << "("; c1.afficher(); cout << ") * ("; c2.afficher(); cout << ") = ";
                resultat.afficher(); cout << endl;
                break;
                
            case 5:
                cout << "=== DIVISION ===" << endl;
                resultat = c1.division(c2);
                cout << "("; c1.afficher(); cout << ") / ("; c2.afficher(); cout << ") = ";
                resultat.afficher(); cout << endl;
                break;
                
            case 6:
                cout << "Au revoir !" << endl;
                break;
                
            default:
                cout << "Choix invalide ! Veuillez reessayer." << endl;
        }
        
        cout << endl;
        
    } while(choix != 6);
    
    return 0;
}