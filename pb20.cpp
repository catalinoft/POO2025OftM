#include <iostream>
using namespace std;

class Carte {
    private:
    const int id; //constanta]
    string titlu;
    float pret;
    static int totalCarti;
    public:
    Carte(string t,float p) : id(++totalCarti),titlu(t),pret(p) {}
    
    //operator <<
    friend ostream& operator<<(ostream& out,const Carte& c) {
        out << "#" << c.id << " \"" << c.titlu << "\" - " << c.pret << " lei";
        return out;
    }
    
    //operator +
    Carte operator+(float reducere) {
        return Carte(this->titlu,this->pret - reducere);
        
    }
    //operator >
    bool operator>(const Carte& alta) {
        return this->pret > alta.pret;
    }
    //getter static
    static int getTotal() {
        return totalCarti;
    }
    string  gettitlu() const {
        return titlu;
    }
    //getter pentru pret
    float getpret() {
        return pret;
    }
    
    //metoda try catch
    void vinde() {
        try {
            if(pret<=0) {
                throw "pret invalid";
            }
            cout<<"Carte vanduta"<<titlu<<endl;
            totalCarti--;
            
        }
        catch(const char* mesaj) {
            cout<<"Eroare la vanzare"<<mesaj<<endl;
        }
        
    }
  
};

int Carte::totalCarti=0;


//initializare static






int main() {
   Carte c1("Harry",50);
   Carte c2("lotr",70);
   Carte c3("Game of Thrones",90);
   cout<<"Carti in stoc"<<Carte::getTotal()<<endl;
   cout<<c1<<endl;
   cout<<c2<<endl;
   cout<<c3<<endl;
   if(c3>c1) {
       cout<<c3<<"e mai scumpa";
       
   }
   Carte c4 = c1+10;
   cout<<c4<<endl;
   c1.vinde();
   cout<<"Carti ramase"<<Carte::getTotal()<<endl;
   return 0;
    
}   