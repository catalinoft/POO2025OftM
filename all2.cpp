#include <bits/stdc++.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum GenFilm { ACTIUNE=1,COMEDIE=2,DRAMA=3,SF=4};

class Film {
    private:
    const int id;
    float rating;
    string titlu;
    GenFilm Gen;
    int nrActori;
    string* numeActori; //array de string cu numele actorilor
    static int nrTotalFilme;
    public:
    //constructor default
    Film() :id(++nrTotalFilme) {
        cout<<"se apeleaza construcot pentru filmul"<<id<<endl;
        this->titlu = "film basic";
        this->rating = 0.0;
        this->nrActori = 0;
        this->numeActori = nullptr;
        this->Gen = ACTIUNE;
        
        
    }
    //constructor cu parametrii
    Film(string titlu, float rating,int nrActori,string* actorii,GenFilm gen) :id(++nrTotalFilme) {
        cout<<"se apeleaza pentru "<<id<<endl;
        this->numeActori = new string[this->nrActori];
        for(int i=0;i<this->nrActori;i++) {
            this->numeActori[i] = this->actorii[i];
            cout<<"  - Adaugat actor: " << actorii[i] << endl;
        }
        
        
    }
    //constructor de copiere
    Film(const Film& copie) :id(++nrTotalFilme) {
        cout<<"se apeleaza "<<id<<endl;
        cout<<"copiez"<<(&copie)<<"in filmul"<<this<<endl;
        this->titlu = copie.titlu;
        this->rating = copie.rating;
        this->nrActori = copie.nrActori;
        this->gen = copie.gen;
        if(copie.numeActori != nullptr && copie.nrActori > 0) {
            this->numeActori = new string[this->nrActori];
            for(int i=0;i<this->nrActori;i++) {
                this->numeActori[i] = copie.numeActori[i];
                cout<<"nume actori"<<copie.numeActori[i];
                
                
            }
        }
        else {
            this->numeActori = nullptr;
            this->nrActori = 0;
            
        }
    }
    
    //operator atribuire
    Film& operator=(const Film& copie) {
        cout<<"se apeleaza filmele cu id" <<this->id<<"si"<<(&copie);
        if(this!= copie) {
            this->titlu  = copie.titlu;
            this->rating = copie.rating;
            this->gen = copie.gen;
            this->nrActori = copie.nrActori;
            //sterge memoria veche
            if(this->numeActori != nullptr) {
                delete[] this->numeActori;
            }
            
            //aloca memorie si copiaza
            if(this->numeActori != nullptr && this->nrActori > 0) {
                    this->numeActori = new string[copie.nrActori];
                    cout << "  - Copiat actor: " << copie.numeActori[i] << endl;
            }
            
            
        } else {
            this->numeActori = nullptr;
        }
        return *this;
    }
    
    //metoda afisare
    void afisarefilm() {
        cout<<endl<<"afisare film" <<this->id;
        cout<<endl<<"cu titlul" <<this->titlu;
        cout<<endl<<"cu rating"<<this->rating;
        cout<<endl<<"Gen: ";
        if(this->Gen == ACTIUNE) cout<<"ACTIUNE";
        if(this->Gen == COMEDIE) cout<<"COMEDIE";
        if(this->Gen == DRAMA) cout<<"DRAMA";
        if(this->Gen == SF) cout<<"SF";
        
        cout<<endl<<"Actori (" << this->nrActori << "): ";
        if(this->numeActori != nullptr) {
            for(int i=0;i<this->nrActori;i++) {
                cout<<this->nrActori[i];
                if(i<this->nrActori-1) cout<<",";
                
                    
                    
                
            }
        }
        else {
            cout<<"niciun actor";
            
        }
        cout<<endl;
        
        
    }
    
    //getter pentru gen ca string
    string getgentx() {
        if(this->gen == ACTIUNE) cout<<"ACTIUNE";
        if (this->gen == COMEDIE) return "COMEDIE";
        if (this->gen == DRAMA) return "DRAMA";
        if (this->gen == SF) return "SF";
        return "NECUNOSCUT";
    }
    //getteri
    int getid() {
        return this->id;
    }
    string gettitlu {
        return this->titlu;
    }
    float getrating {
        return this->rating;
    }
    GenFilm getfilm {
        return this->gen;
    }
    
    string* getActori() {
        if(this->numeActori != nullptr) {
            string* copieActori = new string[this->nrActori];
            for(int i=0;i<this->nrActori;i++) {
                copieActori[i] = this->numeActori[i];
                
            }
            return copieActori;
        }
    }
    
    //setteri
    void settilu(string noutitlu) {
        this->titlu = noutitlu;
        
    }
    void setraing(float nourating) {
        this->rating = nourating;
    }
    void setgen (GenFilm nougen) {
        this->gen = nougen;
    }
    void setActori (string* actoriiNoi,int actorinou) {
        cout<<"set"<<this->nrActori;
        this->nrActori = actorinou;
        if(this->numeActori != nullptr) {
            delete[] this->numeActori;
        }
        if(actoriiNoi != nullptr && actorinou > 0) {
            this->numeActori = new string[this->nrActori];
            for(int i=0;i<this->nrActori;i++) {
                this->numeActori[i] = actoriiNoi[i];
                
            }
        }
        else {
            this->numeActori = nullptr;
            
        }
    }
    
    //destructor
    ~Film() {
        cout<<this->id<<endl;
        if(this->numeActori != nullptr) {
            cout<<this->nrActori;        
            delete[] this->numeActori;
        }
    }
    //metoda static_cast
    static int getnrtotalfilme() {
        return nrTotalFilme;
    }
};

int Film::nrTotalFilme=0;

int main() {
    Film film1;
    film1.afisarefilm();
    string* actori = new string[3] {"Johnny Depp", "Orlando Bloom", "Keira Knightley"};
    Film* film2 = new Film("Piratii din Caraibe", 8.5, 3, actori, ACTIUNE);
    film2->afisarefilm();
    Film film3(*film2);
    film3.afisarefilm();
    film1 = *film2;
    film1.afisarefilm();
    cout<<film2->getgentx();
    Film filmcomedie("Forrest Gump", 8.8, 2, new string[2]{"Tom Hanks", "Robin Wright"}, DRAMA);
    cout<<filmcomedie..getgentx();
    film3.settilu("comoara");
    film3.setraing(8.7);
    film3.setgen(ACTIUNRE);
    string* actoriiNoi = new string[4] {"Johnny Depp", "Orlando Bloom", "Keira Knightley", "Geoffrey Rush"};
    film3.setActori(actoriiNoi,4);
    film3.afisarefilm();
    cout<<film2->gettitlu();
    cout<<film2->getgentx();
    string* listaactori = film2->getActori();
    for(i=0;i<film2->getActori;i++) {
        if(i<film2->getActori()-1 ) cout<<",";
        
    }
    cout<<Film::getnrtotalfilme()<<endl;
    
    delete film2;
    delete[] actori;
    delete[] actoriiNoi;
    delete[] listaactori;
    
}