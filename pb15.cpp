#include <iostream>
#include <exception>
using namespace std;

class VarstaInvalida : public exception {
    public:
    const char* what() const noexcept override {
        return "Varsta trebuie sa fie intre 0 si 120";
    }
};

class Persoana {
    public:
    Persoana(int v) {
        if(v < 0  || v > 120) throw VarstaInvalida();
        
    }
};




int main() {
    Persoana p(150);
    return 0;

  
};