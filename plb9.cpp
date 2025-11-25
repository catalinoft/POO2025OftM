#include<iostream>
#include<string>

using namespace std;

class Curs {
private:
    const int id;
    string denumire;
    string profesor;
    int ore;
    double pret;
    static int nrCursuri;
    
public:
    Curs(string denumire, string profesor, int ore, double pret) 
        : id(++nrCursuri), denumire(denumire), profesor(profesor), ore(ore), pret(pret) {}
    
    void afisare() const {
        cout << id << ". " << denumire << " - " << profesor 
             << " (" << ore << " ore) - " << pret << " RON" << endl;
    }
    
    double getPretPerOra() const {
        return pret / ore;
    }
    
    string getProfesor() const { return profesor; }
    int getOre() const { return ore; }
    
    static int getNrCursuri() { return nrCursuri; }
};

int Curs::nrCursuri = 0;

class CatalogCursuri {
private:
    Curs* cursuri[60];
    int numarCursuri;
    
public:
    CatalogCursuri() : numarCursuri(0) {
        for(int i=0; i<60; i++) cursuri[i] = nullptr;
    }
    
    void adaugaCurs(string denumire, string profesor, int ore, double pret) {
        if(numarCursuri >= 60) return;
        cursuri[numarCursuri] = new Curs(denumire, profesor, ore, pret);
        numarCursuri++;
    }
    
    void afiseazaToateCursurile() {
        cout << "=== CATALOG CURSURI ===" << endl;
        for(int i=0; i<numarCursuri; i++) {
            cursuri[i]->afisare();
            cout << "   Pret pe ora: " << cursuri[i]->getPretPerOra() << " RON" << endl;
        }
    }
    
    void afiseazaCursuriDupaProfesor(string profesor) {
        cout << "=== CURSURI " << profesor << " ===" << endl;
        for(int i=0; i<numarCursuri; i++) {
            if(cursuri[i]->getProfesor() == profesor) {
                cursuri[i]->afisare();
            }
        }
    }
    
    void afiseazaCursuriLungi() {
        cout << "=== CURSURI LUNGI (peste 40 ore) ===" << endl;
        for(int i=0; i<numarCursuri; i++) {
            if(cursuri[i]->getOre() > 40) {
                cursuri[i]->afisare();
            }
        }
    }
    
    ~CatalogCursuri() {
        for(int i=0; i<numarCursuri; i++) {
            delete cursuri[i];
        }
    }
};

void main() {
    CatalogCursuri catalog;
    
    catalog.adaugaCurs("Programare C++", "Prof. Popescu", 60, 1200);
    catalog.adaugaCurs("Baze de Date", "Prof. Ionescu", 45, 900);
    catalog.adaugaCurs("Web Development", "Prof. Popescu", 50, 1100);
    catalog.adaugaCurs("Algoritmi", "Prof. Georgescu", 30, 600);
    
    catalog.afiseazaToateCursurile();
    cout << endl;
    catalog.afiseazaCursuriDupaProfesor("Prof. Popescu");
    cout << endl;
    catalog.afiseazaCursuriLungi();
    
    cout << "\nTotal cursuri: " << Curs::getNrCursuri() << endl;
}