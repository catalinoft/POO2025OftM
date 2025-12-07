#include <iostream>
#include <exception>
using namespace std;

class Eroareamea : public exception {
    public:
    const char* what() const noexcept override {
        return "ai o eroare";
    }
};



int main() {
    try {
        throw Eroareamea();
    }
    catch(const Eroareamea& e) {
        cout<<"am prins eroarea"<<e.what();
        
    }
    catch(const exception& e) {
        cout<<"alta eraoea"<<e.what();
        
        
    }
    return 0;
  
};