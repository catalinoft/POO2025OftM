#include<iostream>
#include<string>

using namespace std;

class Film {
private:
    const int id;
    string titlu;
    string regizor;
    int anLansare;
    double rating;
    static int nrFilme;
    
public:
    Film(string titlu, string regizor, int an, double rating) 
        : id(++nrFilme), titlu(titlu), regizor(regizor), anLansare(an), rating(rating) {}
    
    void afisare() const {
        cout << id << ". " << titlu << " - " << regizor << " (" << anLansare 
             << ") ★ " << rating << "/10" << endl;
    }
    
    bool esteClasic() const {
        return anLansare < 2000;
    }
    
    string getRegizor() const { return regizor; }
    double getRating() const { return rating; }
    
    static int getNrFilme() { return nrFilme; }
};

int Film::nrFilme = 0;

class ColectieFilme {
private:
    Film* filme[100];
    int numarFilme;
    
public:
    ColectieFilme() : numarFilme(0) {
        for(int i=0; i<100; i++) filme[i] = nullptr;
    }
    
    void adaugaFilm(string titlu, string regizor, int an, double rating) {
        if(numarFilme >= 100) return;
        filme[numarFilme] = new Film(titlu, regizor, an, rating);
        numarFilme++;
    }
    
    void afiseazaToateFilmele() {
        cout << "=== COLECTIE FILME ===" << endl;
        for(int i=0; i<numarFilme; i++) {
            filme[i]->afisare();
        }
    }
    
    void afiseazaFilmeDupaRegizor(string regizor) {
        cout << "=== FILME " << regizor << " ===" << endl;
        for(int i=0; i<numarFilme; i++) {
            if(filme[i]->getRegizor() == regizor) {
                filme[i]->afisare();
            }
        }
    }
    
    void afiseazaClassice() {
        cout << "=== FILME CLASICE ===" << endl;
        for(int i=0; i<numarFilme; i++) {
            if(filme[i]->esteClasic()) {
                filme[i]->afisare();
            }
        }
    }
    
    ~ColectieFilme() {
        for(int i=0; i<numarFilme; i++) {
            delete filme[i];
        }
    }
};

void main() {
    ColectieFilme colectie;
    
    colectie.adaugaFilm("The Godfather", "Francis Ford Coppola", 1972, 9.2);
    colectie.adaugaFilm("Pulp Fiction", "Quentin Tarantino", 1994, 8.9);
    colectie.adaugaFilm("Inception", "Christopher Nolan", 2010, 8.8);
    colectie.adaugaFilm("The Dark Knight", "Christopher Nolan", 2008, 9.0);
    
    colectie.afiseazaToateFilmele();
    cout << endl;
    colectie.afiseazaFilmeDupaRegizor("Christopher Nolan");
    cout << endl;
    colectie.afiseazaClassice();
    
    cout << "\nTotal filme: " << Film::getNrFilme() << endl;
}