#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;

public:
    // Constructeur avec valeurs par défaut
    vecteur3d(float vx = 0, float vy = 0, float vz = 0) {
        x = vx;
        y = vy;
        z = vz;
    }
    
    // Fonction d'affichage
    void afficher() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    // ========== SITUATION 1 : RETOUR PAR VALEUR ==========
    
    // Somme de 2 vecteurs (retour par valeur)
    vecteur3d somme(vecteur3d v) {
        vecteur3d resultat;
        resultat.x = x + v.x;
        resultat.y = y + v.y;
        resultat.z = z + v.z;
        return resultat;
    }
    
    // Produit scalaire (retour par valeur)
    float produitScalaire(vecteur3d v) {
        return (x * v.x + y * v.y + z * v.z);
    }
    
    // Fonction coincide (retour par valeur)
    bool coincide(vecteur3d v) {
        return (x == v.x && y == v.y && z == v.z);
    }
    
    // Norme du vecteur
    float norme() {
        return sqrt(x * x + y * y + z * z);
    }
    
    // Normax par valeur
    vecteur3d normax(vecteur3d v) {
        if (this->norme() >= v.norme()) {
            return *this;
        } else {
            return v;
        }
    }
    
    // ========== SITUATION 2 : RETOUR PAR ADRESSE ==========
    
    // Somme par adresse
    vecteur3d* somme_adr(vecteur3d* v) {
        vecteur3d* resultat = new vecteur3d();
        resultat->x = x + v->x;
        resultat->y = y + v->y;
        resultat->z = z + v->z;
        return resultat;
    }
    
    // Produit scalaire par adresse
    float* produitScalaire_adr(vecteur3d* v) {
        float* resultat = new float;
        *resultat = (x * v->x + y * v->y + z * v->z);
        return resultat;
    }
    
    // Fonction coincide par adresse
    bool* coincide_adr(vecteur3d* v) {
        bool* resultat = new bool;
        *resultat = (x == v->x && y == v->y && z == v->z);
        return resultat;
    }
    
    // Normax par adresse
    vecteur3d* normax_adr(vecteur3d* v) {
        if (this->norme() >= v->norme()) {
            return this;
        } else {
            return v;
        }
    }
    
    // ========== SITUATION 3 : RETOUR PAR RÉFÉRENCE ==========
    
    // Somme par référence (stockage dans un vecteur externe)
    void somme_ref(vecteur3d& v, vecteur3d& resultat) {
        resultat.x = x + v.x;
        resultat.y = y + v.y;
        resultat.z = z + v.z;
    }
    
    // Produit scalaire par référence
    void produitScalaire_ref(vecteur3d& v, float& resultat) {
        resultat = (x * v.x + y * v.y + z * v.z);
    }
    
    // Fonction coincide par référence
    void coincide_ref(vecteur3d& v, bool& resultat) {
        resultat = (x == v.x && y == v.y && z == v.z);
    }
    
    // Normax par référence
    vecteur3d& normax_ref(vecteur3d& v) {
        if (this->norme() >= v.norme()) {
            return *this;
        } else {
            return v;
        }
    }
};

// Programme principal pour tester
int main() {
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(4, 5, 6);
    vecteur3d v3(1, 2, 3);
    
    cout << "=== VECTEURS INITIAUX ===" << endl;
    cout << "v1 = "; v1.afficher(); cout << endl;
    cout << "v2 = "; v2.afficher(); cout << endl;
    cout << "v3 = "; v3.afficher(); cout << endl;
    cout << endl;
    
    // ========== TEST SITUATION 1 : PAR VALEUR ==========
    cout << "=== SITUATION 1 : RETOUR PAR VALEUR ===" << endl;
    
    vecteur3d somme1 = v1.somme(v2);
    cout << "v1 + v2 = "; somme1.afficher(); cout << endl;
    
    float ps1 = v1.produitScalaire(v2);
    cout << "v1 . v2 = " << ps1 << endl;
    
    bool coin1 = v1.coincide(v3);
    cout << "v1 coincide avec v3 ? " << (coin1 ? "OUI" : "NON") << endl;
    
    cout << "Norme de v1 = " << v1.norme() << endl;
    
    vecteur3d max1 = v1.normax(v2);
    cout << "Vecteur de norme max entre v1 et v2 = "; max1.afficher(); cout << endl;
    cout << endl;
    
    // ========== TEST SITUATION 2 : PAR ADRESSE ==========
    cout << "=== SITUATION 2 : RETOUR PAR ADRESSE ===" << endl;
    
    vecteur3d* somme2 = v1.somme_adr(&v2);
    cout << "v1 + v2 = "; somme2->afficher(); cout << endl;
    
    float* ps2 = v1.produitScalaire_adr(&v2);
    cout << "v1 . v2 = " << *ps2 << endl;
    
    bool* coin2 = v1.coincide_adr(&v3);
    cout << "v1 coincide avec v3 ? " << (*coin2 ? "OUI" : "NON") << endl;
    
    vecteur3d* max2 = v1.normax_adr(&v2);
    cout << "Vecteur de norme max entre v1 et v2 = "; max2->afficher(); cout << endl;
    
    // Libération de la mémoire
    delete somme2;
    delete ps2;
    delete coin2;
    cout << endl;
    
    // ========== TEST SITUATION 3 : PAR RÉFÉRENCE ==========
    cout << "=== SITUATION 3 : RETOUR PAR REFERENCE ===" << endl;
    
    vecteur3d somme3;
    v1.somme_ref(v2, somme3);
    cout << "v1 + v2 = "; somme3.afficher(); cout << endl;
    
    float ps3;
    v1.produitScalaire_ref(v2, ps3);
    cout << "v1 . v2 = " << ps3 << endl;
    
    bool coin3;
    v1.coincide_ref(v3, coin3);
    cout << "v1 coincide avec v3 ? " << (coin3 ? "OUI" : "NON") << endl;
    
    vecteur3d& max3 = v1.normax_ref(v2);
    cout << "Vecteur de norme max entre v1 et v2 = "; max3.afficher(); cout << endl;
    cout << endl;
    
    return 0;
}
