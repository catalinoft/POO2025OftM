#include<iostream>
#include<string>

using namespace std;

class Angajat {
private:
    const int id;
    string nume;
    string departament;
    double salariu;
    int vechime;
    static int nrAngajati;
    
public:
    Angajat(string nume, string dept, double salariu, int vechime) 
        : id(++nrAngajati), nume(nume), departament(dept), salariu(salariu), vechime(vechime) {}
    
    void afisare() const {
        cout << id << ". " << nume << " - " << departament 
             << " - " << salariu << " RON (" << vechime << " ani)" << endl;
    }
    
    void marireSalariu(double procent) {
        salariu += salariu * procent / 100;
        cout << nume << " a primit marire! Salariu nou: " << salariu << " RON" << endl;
    }
    
    string getDepartament() const { return departament; }
    double getSalariu() const { return salariu; }
    int getVechime() const { return vechime; }
    
    static int getNrAngajati() { return nrAngajati; }
};

int Angajat::nrAngajati = 0;

class Firma {
private:
    Angajat* angajati[200];
    int numarAngajati;
    
public:
    Firma() : numarAngajati(0) {
        for(int i=0; i<200; i++) angajati[i] = nullptr;
    }
    
    void angajeaza(string nume, string dept, double salariu, int vechime) {
        if(numarAngajati >= 200) return;
        angajati[numarAngajati] = new Angajat(nume, dept, salariu, vechime);
        numarAngajati++;
    }
    
    void afiseazaTotiAngajatii() {
        cout << "=== ANGAJATI FIRMA ===" << endl;
        for(int i=0; i<numarAngajati; i++) {
            angajati[i]->afisare();
        }
    }
    
    void afiseazaAngajatiDupaDepartament(string dept) {
        cout << "=== ANGAJATI " << dept << " ===" << endl;
        for(int i=0; i<numarAngajati; i++) {
            if(angajati[i]->getDepartament() == dept) {
                angajati[i]->afisare();
            }
        }
    }
    
    void acordaMariri() {
        cout << "=== ACORDARE MARIRI ===" << endl;
        for(int i=0; i<numarAngajati; i++) {
            if(angajati[i]->getVechime() > 5) {
                angajati[i]->marireSalariu(10);
            }
        }
    }
    
    ~Firma() {
        for(int i=0; i<numarAngajati; i++) {
            delete angajati[i];
        }
    }
};

void main() {
    Firma firma;
    
    firma.angajeaza("Ionescu Ana", "IT", 5000, 3);
    firma.angajeaza("Popescu Marius", "Vanzari", 4500, 7);
    firma.angajeaza("Georgescu Ion", "IT", 5500, 6);
    firma.angajeaza("Marin Elena", "Marketing", 4000, 2);
    
    firma.afiseazaTotiAngajatii();
    cout << endl;
    firma.afiseazaAngajatiDupaDepartament("IT");
    cout << endl;
    firma.acordaMariri();
    
    cout << "\nTotal angajati: " << Angajat::getNrAngajati() << endl;
}