#include <iostream>
#include <exception>
using namespace std;

class soldinsuficient : public exception {
    public:
    const char* what() const noexcept override {
        return "Nu ai destui bani in cont";
    }
    
};

//eroare pentru suma invalida
class Sumainvalida : public exception {
    public:
    const char* what() const noexcept override {
        return "Suma trebuie sa fie mai mare ca 0";
    }
};

class ContBancar {
    int sold = 100;
    public:
    void retrage(int suma) {
        if(suma<=0) throw Sumainvalida();
        if(suma > sold) throw soldinsuficient();
        sold -= suma;
        cout<<"ai retras"<<suma<<"lei";
        
    }
};




int main() {
    ContBancar cont;
    try {
        cont.retrage(-50); //suma invalida
        
    }
    catch(const Sumainvalida& e) {
        cout<<"eroare 1"<<e.what()<<endl;
    }
    catch(const soldinsuficient& e) {
        cout<<"eroare"<<e.what()<<endl;
        
    }
    return 0;
  
};