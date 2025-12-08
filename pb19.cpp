#include <iostream>
using namespace std;

class Angajat {
    private:
    const int id; //constanta la private
    string nume;
    float salariu;
    static int numarrAngajati; // static
    public:
    //constructor
    Angajat(string n,float s) : id(++numarrAngajati), nume(n),salariu(s) {
        //validare try catch]
        try {
            if(s < 0) {
                throw "Salariul nu poate fi negativ";
            }
        }
        catch(const char* mesaj) {
            cout << "Atentie: " << mesaj << endl;
            salariu = 0;
        }
        
    }
    //operator+
    Angajat operator+(float marire) {
        return Angajat(this->nume,this->salariu + marire);
    }
    //operator> comparatie
    bool operator>(const Angajat& altul) {
        return this->salariu > altul.salariu;
    }
    //operator == egal
    bool operator==(const Angajat& altul) {
        return this->nume == altul.nume;
        
    }
    
    //operator << afisare
    friend ostream& operator<<(ostream& out,const Angajat& a) {
        out<<"ID"<<a.id<< " | " << a.nume << " | " << a.salariu << " lei";
        return out;
    }
    
    //operator [] care acc caractere din nume
    char operator[](int index) {
        if(index >=0 && index < nume.length()) {
            return nume[index];
        }
        throw "Index invalid";
        
    }
    
    //operator () calcul salariu cu bonus
    float operator()(float bonus) {
        return salariu+bonus;
        
    }
    //operator += aduna si atribuie
    void operator+=(float suma) {
        salariu += suma;
    }
    //operator!
    bool operator!() {
        return salariu > 0;
    }
    //getter static,ca e privat]
    static int getNrAngajati() {
        return numarrAngajati;
    }
    //try catch separat
    void setSalariu(float nouSalariu) {
        try {
            if(nouSalariu<0) {
                throw 101;
            }
            salariu = nouSalariu;
        }
        catch(int codEroare) {
            cout << "Eroare " << codEroare << ": Salariu invalid!" << endl;
        }
    }
    
    //destructor
    ~Angajat() {
        numarrAngajati--;
        cout << "Angajat " << nume << " a plecat." << endl;
        
    }
    
    
    
    
    
  
  
};



//initializare static
int Angajat::numarrAngajati=0;





int main() {
    cout<<"angajati ini"<<Angajat::getNrAngajati()<<endl;
    //creare angajati
    Angajat a1("Ionescu",5000);
    Angajat a2("Popescu",3400);
    Angajat a3("Marinescu",8000);
    cout<<"Ang dupa creare"<<Angajat::getNrAngajati()<<endl;
    //operator <<
    cout<<a1<<a2<<a3<<endl;
    //operator>
    if(a2>a1) {
        cout<<a2<<"castiga mai mult"<<a1<<endl;
        
    }
    //operator+
    Angajat a4 = a1+1000;
    cout<<a4<<endl;
    //operator[]
    try {
        cout << "Prima litera din nume: " << a1[0] << endl;
        cout << "A treia litera: " << a1[2] << endl;
        
    }
    catch(const char* e) {
        cout << "Eroare: " << e << endl;
    }
    //operator()
    float cuBonus = a1(500);
    cout << "Salariu cu bonus: " << cuBonus << " lei" << endl;
    //operator +=
    a1 += 300;
    cout<<"dupa +="<<a1<<endl;
    //operator!
    if(!a1) {
        cout << a1 << " are salariu" << endl;
    }
    //test constanta
    cout<<"id este"<<&a1<<"nu se poate modif"<<endl;
    //try catch
    Angajat a5("Test",-1000);
    a1.setSalariu(-500);
    return 0;
    
}   