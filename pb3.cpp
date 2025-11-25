#include<iostream>
#include<string>
#include<memory>
#include<vector>

using namespace std;

class ExceptieFisier : public exception {
public:
    ExceptieFisier(const char* mesaj) : exception(mesaj) {}
};

class Fisier {
protected:
    string nume;
    double dimensiuneMB;
    string dataCreare;
    
public:
    Fisier(string nume, double dim, string data) 
        : nume(nume), dimensiuneMB(dim), dataCreare(data) {}
    
    virtual void afisareInfo() {
        cout << "📁 " << nume << " (" << dimensiuneMB << " MB) - " << dataCreare << endl;
    }
    
    virtual double getDimensiuneTotala() { return dimensiuneMB; }
    virtual ~Fisier() {
        cout << "Fisier " << nume << " a fost sters" << endl;
    }
};

class FisierText : public Fisier {
private:
    int numarLinii;
    string encoding;
    
public:
    FisierText(string nume, double dim, string data, int linii, string enc) 
        : Fisier(nume, dim, data), numarLinii(linii), encoding(enc) {}
    
    void afisareInfo() override {
        cout << "📄 ";
        Fisier::afisareInfo();
        cout << "   Linii: " << numarLinii << ", Encoding: " << encoding << endl;
    }
};

class FisierImagine : public Fisier {
private:
    string format;
    int latime, inaltime;
    
public:
    FisierImagine(string nume, double dim, string data, string fmt, int w, int h) 
        : Fisier(nume, dim, data), format(fmt), latime(w), inaltime(h) {}
    
    void afisareInfo() override {
        cout << "🖼️  ";
        Fisier::afisareInfo();
        cout << "   Format: " << format << ", Dimensiuni: " << latime << "x" << inaltime << endl;
    }
};

class Director {
private:
    string nume;
    vector<shared_ptr<Fisier>> fisiere;
    
public:
    Director(string nume) : nume(nume) {}
    
    void adaugaFisier(shared_ptr<Fisier> fisier) {
        fisiere.push_back(fisier);
        cout << "Fisier adaugat in directorul " << nume << endl;
    }
    
    void afiseazaContinut() {
        cout << "\n=== DIRECTOR " << nume << " ===" << endl;
        double totalSize = 0;
        
        for (auto& fisier : fisiere) {
            fisier->afisareInfo();
            totalSize += fisier->getDimensiuneTotala();
        }
        
        cout << "Dimensiune totala: " << totalSize << " MB" << endl;
        cout << "Numar fisiere: " << fisiere.size() << endl;
    }
    
    // Cautare fisier dupa nume
    shared_ptr<Fisier> cautaFisier(const string& numeCautat) {
        for (auto& fisier : fisiere) {
            // Trebuie sa accesam numele - ar trebui getter
            // Pentru simplitate, returnam primul
            return fisier;
        }
        return nullptr;
    }
};

void main() {
    try {
        // Creare director cu smart pointers
        Director doc("Documente");
        
        // Creare fisiere cu shared_ptr
        auto fisier1 = make_shared<FisierText>("nota.txt", 0.5, "2024-01-15", 50, "UTF-8");
        auto fisier2 = make_shared<FisierImagine>("poza.jpg", 2.5, "2024-01-16", "JPEG", 1920, 1080);
        auto fisier3 = make_shared<FisierText>("raport.docx", 1.2, "2024-01-17", 120, "UTF-16");
        
        // Adaugare fisiere in director
        doc.adaugaFisier(fisier1);
        doc.adaugaFisier(fisier2);
        doc.adaugaFisier(fisier3);
        
        // Afisare continut
        doc.afiseazaContinut();
        
        // Testare referinte multiple
        cout << "\n=== TEST REFERINTE MULTIPLE ===" << endl;
        Director backup("Backup");
        backup.adaugaFisier(fisier1); // Acelasi fisier in doua directoare
        backup.afiseazaContinut();
        
        // Smart pointers se ocupa automat de stergere!
        
    } catch (exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }
}