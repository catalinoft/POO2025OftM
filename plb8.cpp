#include<iostream>
#include<string>

using namespace std;

class JocVideo {
private:
    const int id;
    string titlu;
    string platforma;
    int anLansare;
    double pret;
    static int nrJocuri;
    
public:
    JocVideo(string titlu, string platforma, int an, double pret) 
        : id(++nrJocuri), titlu(titlu), platforma(platforma), anLansare(an), pret(pret) {}
    
    void afisare() const {
        cout << id << ". " << titlu << " - " << platforma 
             << " (" << anLansare << ") - " << pret << " EUR" << endl;
    }
    
    void aplicaReducere() {
        pret *= 0.8; // 20% reducere
        cout << titlu << " este la reducere! Pret nou: " << pret << " EUR" << endl;
    }
    
    string getPlatforma() const { return platforma; }
    int getAn() const { return anLansare; }
    
    static int getNrJocuri() { return nrJocuri; }
};

int JocVideo::nrJocuri = 0;

class ColectieJocuri {
private:
    JocVideo* jocuri[80];
    int numarJocuri;
    
public:
    ColectieJocuri() : numarJocuri(0) {
        for(int i=0; i<80; i++) jocuri[i] = nullptr;
    }
    
    void adaugaJoc(string titlu, string platforma, int an, double pret) {
        if(numarJocuri >= 80) return;
        jocuri[numarJocuri] = new JocVideo(titlu, platforma, an, pret);
        numarJocuri++;
    }
    
    void afiseazaToateJocurile() {
        cout << "=== JOCURI VIDEO ===" << endl;
        for(int i=0; i<numarJocuri; i++) {
            jocuri[i]->afisare();
        }
    }
    
    void afiseazaJocuriDupaPlatforma(string platforma) {
        cout << "=== JOCURI " << platforma << " ===" << endl;
        for(int i=0; i<numarJocuri; i++) {
            if(jocuri[i]->getPlatforma() == platforma) {
                jocuri[i]->afisare();
            }
        }
    }
    
    void aplicaReduceri() {
        cout << "=== REDUCERI ===" << endl;
        for(int i=0; i<numarJocuri; i++) {
            if(jocuri[i]->getAn() < 2020) {
                jocuri[i]->aplicaReducere();
            }
        }
    }
    
    ~ColectieJocuri() {
        for(int i=0; i<numarJocuri; i++) {
            delete jocuri[i];
        }
    }
};

void main() {
    ColectieJocuri colectie;
    
    colectie.adaugaJoc("The Witcher 3", "PC", 2015, 29.99);
    colectie.adaugaJoc("Cyberpunk 2077", "PS5", 2020, 49.99);
    colectie.adaugaJoc("GTA V", "XBOX", 2013, 19.99);
    colectie.adaugaJoc("Elden Ring", "PC", 2022, 59.99);
    
    colectie.afiseazaToateJocurile();
    cout << endl;
    colectie.afiseazaJocuriDupaPlatforma("PC");
    cout << endl;
    colectie.aplicaReduceri();
    
    cout << "\nTotal jocuri: " << JocVideo::getNrJocuri() << endl;
}