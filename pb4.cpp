#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

// Interface pentru observatori
class Observer {
public:
    virtual void primesteNotificare(const string& mesaj) = 0;
    virtual ~Observer() = default;
};

// Subiectul care notifica observatorii
class Subiect {
private:
    vector<Observer*> observatori;
    string nume;
    
public:
    Subiect(string nume) : nume(nume) {}
    
    void adaugaObserver(Observer* observer) {
        observatori.push_back(observer);
        cout << "Observer adaugat la " << nume << endl;
    }
    
    void stergeObserver(Observer* observer) {
        // Implementare simplificata
        cout << "Observer sters din " << nume << endl;
    }
    
    void notificaToti(const string& mesaj) {
        cout << "\n🔔 " << nume << " trimite notificare: " << mesaj << endl;
        for (auto observer : observatori) {
            observer->primesteNotificare(mesaj);
        }
    }
};

// Observatori concreti
class Utilizator : public Observer {
private:
    string nume;
    
public:
    Utilizator(string nume) : nume(nume) {}
    
    void primesteNotificare(const string& mesaj) override {
        cout << "   👤 " << nume << " a primit: " << mesaj << endl;
    }
};

class Administrator : public Observer {
private:
    string nivelAcces;
    
public:
    Administrator(string nivel) : nivelAcces(nivel) {}
    
    void primesteNotificare(const string& mesaj) override {
        cout << "   🛡️  Admin (" << nivelAcces << ") a primit: " << mesaj << endl;
    }
};

// Singleton pentru sistemul de notificari
class SistemNotificari {
private:
    static SistemNotificari* instanta;
    Subiect subiectPrincipal;
    
    SistemNotificari() : subiectPrincipal("Sistem Central") {}
    
public:
    static SistemNotificari* getInstanta() {
        if (!instanta) {
            instanta = new SistemNotificari();
        }
        return instanta;
    }
    
    void inregistreazaUtilizator(Observer* observer) {
        subiectPrincipal.adaugaObserver(observer);
    }
    
    void trimiteNotificareGlobala(const string& mesaj) {
        subiectPrincipal.notificaToti(mesaj);
    }
    
    // Prevenire copiere
    SistemNotificari(const SistemNotificari&) = delete;
    void operator=(const SistemNotificari&) = delete;
};

SistemNotificari* SistemNotificari::instanta = nullptr;

void main() {
    // Obține instanta singleton
    SistemNotificari* sistem = SistemNotificari::getInstanta();
    
    // Creare observatori
    Utilizator user1("Ion Popescu");
    Utilizator user2("Maria Ionescu");
    Administrator admin("Super Admin");
    
    // Inregistrare observatori
    sistem->inregistreazaUtilizator(&user1);
    sistem->inregistreazaUtilizator(&user2);
    sistem->inregistreazaUtilizator(&admin);
    
    // Trimitere notificari
    sistem->trimiteNotificareGlobala("Sistemul va fi intretinut maine intre 2-4 AM");
    sistem->trimiteNotificareGlobala("Noua actualizare este disponibila!");
    
    // Demonstrare ca e acelasi singleton
    SistemNotificari* sistem2 = SistemNotificari::getInstanta();
    cout << "\nAdresa sistem1: " << sistem << endl;
    cout << "Adresa sistem2: " << sistem2 << endl;
    cout << "Sunt aceeasi instanta: " << (sistem == sistem2) << endl;
}