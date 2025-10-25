#include <iostream>
using namespace std;

int main() {
    int tableau[10];
    int *ptr;
    int i;
    
    // Lecture des 10 nombres avec pointeur
    cout << "Entrez 10 nombres entiers :" << endl;
    ptr = tableau;  // ptr pointe sur le début du tableau
    for (i = 0; i < 10; i++) {
        cout << "Nombre " << (i + 1) << " : ";
        cin >> *(ptr + i);  // Équivalent à tableau[i]
    }
    
    // Initialisation avec le premier élément
    ptr = tableau;
    int max = *ptr;  
    int min = *ptr;
    
    // Recherche du min et max avec pointeur
    for (i = 1; i < 10; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }
    
    // Affichage des résultats
    cout << "\nLe plus grand nombre est : " << max << endl;
    cout << "Le plus petit nombre est : " << min << endl;
    
    return 0;
}