#include<iostream>
#include<string>

using namespace std;

class Masina {
private:
    const int id;
    string marca;
    string model;
    int anFabricatie;
    double pret;
    static int nrMasini;
    
public:
    Masina(string marca, string model, int an, double pret) 
        : id(++nrMasini), marca(marca), model(model), anFabricatie(an), pret(pret) {}
    
    void afisare() const {
        cout << id << ". " << marca << " " << model << " (" << anFabricatie 
             << ") - " << pret << " EUR" << endl;
    }
    
    void aplicaReducere(double procent) {
        pret -= pret * procent / 100;
        cout << "Reducere aplicata! Pret nou: " << pret << " EUR" << endl;
    }
    
    string getMarca() const { return marca; }
    int getAn() const { return anFabricatie; }
    double getPret() const { return pret; }
    
    static int getNrMasini() { return nrMasini; }
};

int Masina::nrMasini = 0;

class ParcAuto {
private:
    Masina* masini[50];
    int numarMasini;
    
public:
    ParcAuto() : numarMasini(0) {
        for(int i=0; i<50; i++) masini[i] = nullptr;
    }
    
    void adaugaMasina(string marca, string model, int an, double pret) {
        if(numarMasini >= 50) return;
        masini[numarMasini] = new Masina(marca, model, an, pret);
        numarMasini++;
    }
    
    void afiseazaToateMasinile() {
        cout << "=== PARC AUTO ===" << endl;
        for(int i=0; i<numarMasini; i++) {
            masini[i]->afisare();
        }
    }
    
    void afiseazaMasiniDupaMarca(string marca) {
        cout << "=== MASINI " << marca << " ===" << endl;
        for(int i=0; i<numarMasini; i++) {
            if(masini[i]->getMarca() == marca) {
                masini[i]->afisare();
            }
        }
    }
    
    ~ParcAuto() {
        for(int i=0; i<numarMasini; i++) {
            delete masini[i];
        }
    }
};

void main() {
    ParcAuto parc;
    
    parc.adaugaMasina("BMW", "Seria 3", 2020, 25000);
    parc.adaugaMasina("Audi", "A4", 2019, 22000);
    parc.adaugaMasina("BMW", "X5", 2021, 45000);
    parc.adaugaMasina("Mercedes", "C-Class", 2022, 35000);
    
    parc.afiseazaToateMasinile();
    cout << endl;
    parc.afiseazaMasiniDupaMarca("BMW");
    
    cout << "\nTotal masini: " << Masina::getNrMasini() << endl;
}