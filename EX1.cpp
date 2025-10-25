#include <iostream>

void compterAppels() {
    static int compteur = 0;  // Variable statique qui conserve sa valeur entre les appels
    compteur++;
    std::cout << "appel numéro " << compteur << std::endl;
}

int main() {
    // Exemples d'appels
    compterAppels();  // affiche: appel numéro 1
    compterAppels();  // affiche: appel numéro 2
    compterAppels();  // affiche: appel numéro 3
    return 0;
}