#include<iostream>
#include<string>

using namespace std;

class ExceptieBanca : public exception {
public:
    ExceptieBanca(const char* mesaj) : exception(mesaj) {}
};

class ContBancar {
protected:
    const string iban;
    string detinator;
    double sold;
    static int nrTotalConturi;
    
public:
    ContBancar(string iban, string detinator, double sold) 
        : iban(iban), detinator(detinator), sold(sold) {
        nrTotalConturi++;
    }
    
    virtual void afisareDate() {
        cout << "IBAN: " << iban << ", Detinator: " << detinator 
             << ", Sold: " << sold << " RON" << endl;
    }
    
    virtual void depunere(double suma) {
        if (suma <= 0) throw ExceptieBanca("Suma depusa trebuie sa fie pozitiva!");
        sold += suma;
        cout << "Depunere reusita: " << suma << " RON" << endl;
    }
    
    virtual void retragere(double suma) = 0; // Metoda pur virtuala
    
    virtual ~ContBancar() {
        nrTotalConturi--;
    }
    
    static int getNrTotalConturi() { return nrTotalConturi; }
};

int ContBancar::nrTotalConturi = 0;

class ContCurent : public ContBancar {
private:
    double limitaDescoperire;
public:
    ContCurent(string iban, string detinator, double sold, double limita)
        : ContBancar(iban, detinator, sold), limitaDescoperire(limita) {}
    
    void retragere(double suma) override {
        if (suma <= 0) throw ExceptieBanca("Suma retrasa trebuie sa fie pozitiva!");
        if (suma > sold + limitaDescoperire) {
            throw ExceptieBanca("Fonduri insuficiente pentru retragere!");
        }
        sold -= suma;
        cout << "Retragere reusita: " << suma << " RON" << endl;
    }
    
    void afisareDate() override {
        cout << "[CONT CURENT] ";
        ContBancar::afisareDate();
        cout << "Limita descoperire: " << limitaDescoperire << " RON" << endl;
    }
};

class ContEconomii : public ContBancar {
private:
    double dobandaAnuala;
public:
    ContEconomii(string iban, string detinator, double sold, double dobanda)
        : ContBancar(iban, detinator, sold), dobandaAnuala(dobanda) {}
    
    void retragere(double suma) override {
        if (suma <= 0) throw ExceptieBanca("Suma retrasa trebuie sa fie pozitiva!");
        if (suma > sold) {
            throw ExceptieBanca("Fonduri insuficiente in contul de economii!");
        }
        sold -= suma;
        cout << "Retragere reusita din economii: " << suma << " RON" << endl;
    }
    
    void calculeazaDobanda() {
        double dobanda = sold * dobandaAnuala / 100;
        cout << "Dobanda anuala: " << dobanda << " RON" << endl;
    }
    
    void afisareDate() override {
        cout << "[CONT ECONOMII] ";
        ContBancar::afisareDate();
        cout << "Dobanda anuala: " << dobandaAnuala << "%" << endl;
    }
};

class ContBusiness : public ContCurent {
private:
    string numeCompanie;
    double comisionTranzactii;
public:
    ContBusiness(string iban, string detinator, double sold, double limita, 
                 string companie, double comision)
        : ContCurent(iban, detinator, sold, limita), 
          numeCompanie(companie), comisionTranzactii(comision) {}
    
    void depunere(double suma) override {
        double sumaFinala = suma - (suma * comisionTranzactii / 100);
        ContBancar::depunere(sumaFinala);
        cout << "Comision aplicat: " << (suma * comisionTranzactii / 100) << " RON" << endl;
    }
    
    void afisareDate() override {
        cout << "[CONT BUSINESS] ";
        cout << "Companie: " << numeCompanie << ", ";
        ContBancar::afisareDate();
        cout << "Comision tranzactii: " << comisionTranzactii << "%" << endl;
    }
};

void main() {
    try {
        ContBancar* conturi[4];
        
        conturi[0] = new ContCurent("RO123", "Ion Popescu", 5000, 2000);
        conturi[1] = new ContEconomii("RO456", "Maria Ionescu", 10000, 3.5);
        conturi[2] = new ContBusiness("RO789", "SC ABC SRL", 20000, 5000, "ABC SRL", 1.5);
        conturi[3] = new ContCurent("RO999", "Ana Vasile", 3000, 1000);
        
        cout << "=== SISTEM BANCAR ===" << endl;
        for (int i = 0; i < 4; i++) {
            conturi[i]->afisareDate();
            cout << "-------------------" << endl;
        }
        
        // Test operatii
        cout << "\n=== OPERATII ===" << endl;
        conturi[0]->depunere(1000);
        conturi[0]->retragere(2000);
        
        // Downcasting pentru metode specifice
        ContEconomii* economii = dynamic_cast<ContEconomii*>(conturi[1]);
        if (economii) {
            economii->calculeazaDobanda();
        }
        
        cout << "\nNumar total conturi: " << ContBancar::getNrTotalConturi() << endl;
        
        // Curatare memorie
        for (int i = 0; i < 4; i++) {
            delete conturi[i];
        }
        
    } catch (ExceptieBanca& e) {
        cout << "Eroare banca: " << e.what() << endl;
    }
}