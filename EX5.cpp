#include <iostream>
using namespace std;

int main() {
    // 1. Déclaration d'un entier a (non initialisé)
    int a=23;
    
    // 2. Déclaration d'une référence vers cet entier
    int &ref_a = a;
    
    // 3. Déclaration d'un pointeur vers cet entier
    int *p_a = &a;
    
    cout << "=== Affichage des variables ===" << endl << endl;
    
    // 4. Affichage des variables, leurs adresses et valeurs
    
    cout << "Variable a :" << endl;
    cout << "  Valeur de a       : " << a << endl;
    cout << "  Adresse de a      : " << &a << endl;
    cout << endl;
    
    cout << "Reference ref_a :" << endl;
    cout << "  Valeur de ref_a   : " << ref_a << endl;
    cout << "  Adresse de ref_a  : " << &ref_a << endl;
    cout << endl;
    
    cout << "Pointeur p_a :" << endl;
    cout << "  Valeur de p_a (adresse stockee) : " << p_a << endl;
    cout << "  Adresse de p_a                  : " << &p_a << endl;
    cout << "  Valeur pointee par p_a (*p_a)   : " << *p_a << endl;
    cout << endl;
    
    // Vérification
    cout << "=== Verification ===" << endl;
    cout << "a, ref_a et *p_a pointent vers la meme adresse ? ";
    if (&a == &ref_a && &a == p_a) {
        cout << "OUI" << endl;
    }
    
    return 0;
}
