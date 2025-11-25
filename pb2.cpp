#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
class Inventar {
private:
    string numeDepozit;
    vector<T> elemente;
    int capacitateMaxima;
    
public:
    Inventar(string nume, int capacitate) 
        : numeDepozit(nume), capacitateMaxima(capacitate) {}
    
    void adaugaElement(const T& element) {
        if (elemente.size() >= capacitateMaxima) {
            throw exception("Capacitate depozit depasita!");
        }
        elemente.push_back(element);
        cout << "Element adaugat in " << numeDepozit << endl;
    }
    
    void eliminaElement(int index) {
        if (index < 0 || index >= elemente.size()) {
            throw exception("Index invalid!");
        }
        elemente.erase(elemente.begin() + index);
        cout << "Element eliminat" << endl;
    }
    
    void afiseazaInventar() {
        cout << "\n=== INVENTAR " << numeDepozit << " ===" << endl;
        cout << "Capacitate: " << elemente.size() << "/" << capacitateMaxima << endl;
        for (int i = 0; i < elemente.size(); i++) {
            cout << i + 1 << ". " << elemente[i] << endl;
        }
    }
    
    int getNumarElemente() { return elemente.size(); }
    bool estePlin() { return elemente.size() >= capacitateMaxima; }
};

// Specializare pentru string
template<>
class Inventar<string> {
private:
    string numeDepozit;
    vector<string> elemente;
    int capacitateMaxima;
    
public:
    Inventar(string nume, int capacitate) 
        : numeDepozit(nume), capacitateMaxima(capacitate) {}
    
    void adaugaElement(const string& element) {
        if (elemente.size() >= capacitateMaxima) {
            throw exception("Capacitate depozit depasita!");
        }
        elemente.push_back(element);
        cout << "Document adaugat: " << element << endl;
    }
    
    void afiseazaInventar() {
        cout << "\n=== DOCUMENTE " << numeDepozit << " ===" << endl;
        for (int i = 0; i < elemente.size(); i++) {
            cout << "📄 " << elemente[i] << endl;
        }
    }
};

class Produs {
private:
    string nume;
    double pret;
    int cantitate;
    
public:
    Produs(string n, double p, int c) : nume(n), pret(p), cantitate(c) {}
    
    friend ostream& operator<<(ostream& os, const Produs& p) {
        os << p.nume << " - " << p.pret << " RON x" << p.cantitate;
        return os;
    }
};

void main() {
    try {
        // Inventar pentru numere
        Inventar<int> inventarNumere("Numere", 5);
        inventarNumere.adaugaElement(10);
        inventarNumere.adaugaElement(20);
        inventarNumere.afiseazaInventar();
        
        // Inventar pentru produse
        Inventar<Produs> inventarProduse("Produse", 3);
        inventarProduse.adaugaElement(Produs("Laptop", 5000, 2));
        inventarProduse.adaugaElement(Produs("Mouse", 150, 10));
        inventarProduse.afiseazaInventar();
        
        // Inventar specializat pentru string-uri
        Inventar<string> inventarDocumente("Documente", 10);
        inventarDocumente.adaugaElement("Contract vanzare.pdf");
        inventarDocumente.adaugaElement("Factura 123.docx");
        inventarDocumente.afiseazaInventar();
        
    } catch (exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }
}