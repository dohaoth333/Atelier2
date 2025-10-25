#include <iostream>
using namespace std;

// Fonction pour échanger deux caractères
void echanger(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Fonction récursive pour afficher toutes les permutations
void permutations(char chaine[], int debut, int fin) {
    // Cas de base : si on arrive à la fin, afficher la permutation
    if (debut == fin) {
        cout << chaine << endl;
    }
    else {
        // Parcourir tous les caractères à partir de 'debut'
        for (int i = debut; i <= fin; i++) {
            
            echanger(chaine[debut], chaine[i]);
            permutations(chaine, debut + 1, fin);
            echanger(chaine[debut], chaine[i]);
        }
    }
}
int main() {
    char chaine[100];
    
    cout << "Entrez une chaine de caracteres : ";
    cin >> chaine;
    
    // Calculer la longueur de la chaîne
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    
    cout << "\nToutes les permutations de \"" << chaine << "\" :" << endl;
    permutations(chaine, 0, longueur - 1);
    
    return 0;
}