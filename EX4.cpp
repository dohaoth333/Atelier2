#include <iostream>
using namespace std;

int main() {
    int taille;
    int *tableau1;
    int *tableau2;
    
    // Demander la taille du tableau
    cout << "Entrez la taille du tableau : ";
    cin >> taille;
    
    // 1. Allocation dynamique du premier tableau
    tableau1 = new int[taille];
    
    // Lecture des nombres entiers
    cout << "Entrez " << taille << " nombres entiers :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "Nombre " << (i + 1) << " : ";
        cin >> tableau1[i];
    }
    
    // Affichage du premier tableau
    cout << "\nPremier tableau :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << tableau1[i] << " ";
    }
    cout << endl;
    
    // 2. Création dynamique du second tableau pour les carrés
    tableau2 = new int[taille];
    
    // Calcul des carrés
    for (int i = 0; i < taille; i++) {
        tableau2[i] = tableau1[i] * tableau1[i];
    }
    
    // 3. Suppression du premier tableau
    delete[] tableau1;
    tableau1 = nullptr;  // Bonne pratique
    
    // Affichage du second tableau (les carrés)
    cout << "\nTableau des carres :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << tableau2[i] << " ";
    }
    cout << endl;
    
    // Suppression du second tableau
    delete[] tableau2;
    tableau2 = nullptr;  // Bonne pratique
    
    cout << "\nMemoire liberee avec succes !" << endl;
    
    return 0;
}
