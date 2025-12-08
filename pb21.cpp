#include <iostream>
using namespace std;

class Bilet {
    private:
    const int id; //constant
    string spectacol;
    float pret;
    static int biletevandute; //static
    public:
    Bilet(string s,float p) : id(++biletevandute),spectacol(s),pret(p) {
        try {
            if(p<=0) throw "Pret invalid";
            
        }
        catch(const char* e) {
            cout<<"atentie"<<e<<endl;
            pret=50; //pret default
            
        }
    }
    
    //operator+
    Bilet operator+(float taxa) {
        return Bilet(spectacol,pret+taxa);
    }
    
    //operator> 
    bool operator>(const Bilet& b) {
        return pret > b.pret;
    }
    //operator ==
    bool operator==(const Bilet& b) {
        return spectacol == b.spectacol;
    }
    
    //operator<< afisare
    friend ostream& operator<<(ostream& out,const Bilet& b) {
        out << "Bilet #" << b.id << " - " << b.spectacol << " (" << b.pret << " lei)";
        return out;
        
    }
    
    //calculator ()
    float operator()(float reducereprocent) {
        return pret*(1-reducereprocent/100);
    }
    //operator!
    bool operator!() {
        return pret>100;
    }
    static int getBileteVandute() {
        return biletevandute;
    }
    string getSpectacol() {return spectacol;}
    float getpret() {return pret;}
    
  
    

   
};


int Bilet::biletevandute=0;




int main() {
    Bilet b1("rock",150);
    Bilet b2("Teatru",80);
    Bilet b3("opera",200);
    cout<<"Biletevandute"<<Bilet::getBileteVandute()<<endl;
    cout << "\n" << b1 << "\n" << b2 << "\n" << b3 << endl;
    if(b3>b1) {
        cout<<b3.getSpectacol()<<"e mai scump";
        
    }
    Bilet cutaxa = b1 + 20;
    cout<<"cu taxa"<<cutaxa;
    float curede = b2(25);
    cout<<"cu reducere"<<curede;
    if(!b1) {
        cout << "\n" << b1.getSpectacol() << " este scump (>100 lei)";
        
    }
    return 0;
    
}   