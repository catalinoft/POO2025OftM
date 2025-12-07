#include <iostream>
using namespace std;

class ProdusComplet {
    private:
    string nume;
    float pret;
    int stoc;
    public:
    ProdusComplet(string n = "",float p=0,int s=0) : nume(n),pret(p),stoc(s) {}
    
    //operator += atribuie
    void operator+=(float adaos) {
        pret+=adaos;
    }
    
    //operator > compara
    bool operator>(const ProdusComplet& altul) {
        return pret > altul.pret;
    }
    
    //operator! verifica daca e in stoc
    bool operator!() {
        return stoc > 0;
    }
    
    //operator() calculeaza pret cu tva
    float operator()(float tvaprocent) {
        return pret * (1 + tvaprocent/100);
        
    }
    
    //operator<< afisare
    friend ostream& operator<<(ostream& out,const ProdusComplet& p) {
        out<<p.nume<<"-"<<p.pret<<"lei,stoc"<<p.stoc;
        return out;
    }
    
    //operator++ postincrementare
    ProdusComplet operator++(int) {
        ProdusComplet vechi = *this;
        stoc++;
        return vechi;
    }
    
    //operator++ preincrementare
    ProdusComplet& operator++() {
        stoc++;
        return *this;
    }
    
    //operator int() 
    explicit operator int() {
        return stoc;
    }
  

  
    
};

int main() {
    ProdusComplet laptop("Laptop",3000,5);
    ProdusComplet telefon("Telefon",2000,0);
    //testam toti operatorii
    cout<<"Initial"<<laptop<<endl;
    laptop += 500;
    cout<<"duoa"<<laptop<<endl;
    if(laptop > telefon) {
        cout<<"laptop mai scum decat tel";
    }
    if(!laptop) {
        cout<<"nu e in stoc"<<endl;
    } else {
        cout<<"e in"<<endl;
    }
    if(!telefon) {
        cout<<"tel nu e"<<endl;
    }
    float pretcutva = laptop(19); //opearto()
    cout<<"pret cu tva"<<pretcutva<<"lei"<<endl;
    cout<<laptop++<<endl; //++ postincrementare
    cout<<laptop<<endl;
    
    cout<<++laptop<<endl; //pre
    int stoc = (int) laptop; //operator int()
    cout<<"stoc final"<<stoc<<"bucati";
    
   
	    
	
}
