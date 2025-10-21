#include <iostream>
using namespace std;

class Cerc {
private:
    double raza;
    
public:
    // Constructor
    Cerc(double r) {
        raza = r;
    }
    
    // Metodă pentru calculul ariei
    double calculeazaArie() {
        return 3.14159 * raza * raza;
    }
    
    // Metodă pentru calculul perimetrului
    double calculeazaPerimetru() {
        return 2 * 3.14159 * raza;
    }
    
    // Metodă pentru afișare informații
    void afiseazaInformatii() {
        cout << "Cerc cu raza: " << raza << endl;
        cout << "Arie: " << calculeazaArie() << endl;
        cout << "Perimetru: " << calculeazaPerimetru() << endl;
    }
};

int main() {
    // Creăm un cerc cu raza 5
    Cerc cerc1(5.0);
    
    // Afișăm informațiile despre cerc
    cerc1.afiseazaInformatii();
    
    cout << "\n--- Alt cerc ---" << endl;
    
    // Alt cerc cu raza 2.5
    Cerc cerc2(2.5);
    cerc2.afiseazaInformatii();
    
    return 0;
}