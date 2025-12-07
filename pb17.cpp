#include<iostream>
#include<string>
#include <exception>
using namespace std;


class ExceptieCustom : public exception {
public:
    
    const char* what() const noexcept override {
        return "Pretul este prea mic!";
    }
};

class Produs {
private:
    const int id;
    string denumire;
    float pret;
    static int nrProduse;

    static const float PRET_MINIM;  
    
public:
    Produs(int idP, string denumireP, float pretP) 
        : id(idP), denumire(denumireP), pret(pretP) {
        nrProduse++;
        
        if (pret < PRET_MINIM) {
            throw ExceptieCustom();  
        }
    }
    
    
    static int getNrProduse() {
        return nrProduse;
    }
    
    bool operator>(const Produs& altul) {
        return this->pret > altul.pret;
    }
    
    friend ostream& operator<<(ostream& out, const Produs& p) {
        out << p.denumire << " - " << p.pret << " lei";
        return out;
    }
};


int Produs::nrProduse = 0;
const float Produs::PRET_MINIM = 1; 

int main() {
    try {
        cout << "Nr produse initial: " << Produs::getNrProduse() << endl;
        
        Produs p1(1, "Laptop", 5000);
        Produs p2(2, "Telefon", 3000);
        
        cout << "Nr produse dupa creare: " << Produs::getNrProduse() << endl;
        
        cout << p1 << endl;
        cout << p2 << endl;
        
        if (p1 > p2) {
            cout << "Laptopul e mai scump\n";
        }
        
        
        Produs p4(3, "ProdusIeftin", 0.5);
        
    } 
    catch (const ExceptieCustom& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    
    return 0;
}