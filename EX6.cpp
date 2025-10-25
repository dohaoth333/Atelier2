#include <iostream>
using namespace std;

// ========== MÉTHODE 1 : TRANSMISSION PAR ADRESSE (pointeurs) ==========

// Fonction incrementer avec pointeur
void incrementer_pointeur(int *p) {
    (*p)++;  // Incrémente la valeur pointée
}

// Fonction permuter avec pointeurs
void permuter_pointeur(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main() {
    cout << "===== TEST MÉTHODE 1 : TRANSMISSION PAR ADRESSE (pointeurs) =====" << endl << endl;
    
    // Test incrementer avec pointeur
    int a = 10;
    cout << "Avant incrementer_pointeur : a = " << a << endl;
    incrementer_pointeur(&a);  // On passe l'adresse de a
    cout << "Après incrementer_pointeur : a = " << a << endl;
    cout << endl;
    
    // Test permuter avec pointeurs
    int x = 5, y = 20;
    cout << "Avant permuter_pointeur : x = " << x << ", y = " << y << endl;
    permuter_pointeur(&x, &y);  // On passe les adresses
    cout << "Après permuter_pointeur : x = " << x << ", y = " << y << endl;
    cout << endl;
    
    cout << "===== TEST MÉTHODE 2 : TRANSMISSION PAR RÉFÉRENCE =====" << endl << endl;
    
    
    return 0;
}