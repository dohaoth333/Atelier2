#include <iostream>
using namespace std;

// Fonction qui vérifie si un nombre est multiple de 2
int estMultipleDe2(int n) {
    if (n % 2 == 0) {
        return 1;  
    }
    return 0;  
}

// Fonction qui vérifie si un nombre est multiple de 3
int estMultipleDe3(int n) {
    if (n % 3 == 0) {
        return 1;  
    }
    return 0;  
}

int main() {
    int nombre;
    
    cout << "donnez un entier : ";
    cin >> nombre;
    
    // Vérification des multiples
    int multipleDe2 = estMultipleDe2(nombre);
    int multipleDe3 = estMultipleDe3(nombre);
    
    if (multipleDe2) {
        cout << "il est pair" << endl;
    }
    
    if (multipleDe3) {
        cout << "il est multiple de 3" << endl;
    }
    
    if (multipleDe2 && multipleDe3) {
        cout << "il est divisible par 6" << endl;
    }
    
    return 0;
}