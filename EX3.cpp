#include <iostream>
using namespace std;

int main() {
    int tableau[10];
    int i;
    
    // Lecture des 10 nombres
    cout << "Entrez 10 nombres entiers :" << endl;
    for (i = 0; i < 10; i++) {
        cout << "Nombre " << (i + 1) << " : ";
        cin >> tableau[i];
    }
    
    // Initialisation avec le premier élément
    int max = tableau[0];
    int min = tableau[0];
    
    // Recherche du min et max
    for (i = 1; i < 10; i++) {
        if (tableau[i] > max) {
            max = tableau[i];
        }
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }
    
    // Affichage des résultats
    cout << "\nLe plus grand nombre est : " << max << endl;
    cout << "Le plus petit nombre est : " << min << endl;
    
    return 0;
}
