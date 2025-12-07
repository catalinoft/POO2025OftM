#include <iostream>
#include <string>
using namespace std;

class Timp {
    private:
    int ore;
    int minute;
    public:
    Timp(int o=0,int m=0) : ore(o),minute(m) {
        if(minute >=60) {
            ore += minute / 60;
            minute = minute % 60;
        }
    }
    
    //operator + adunare
    Timp operator+(const Timp& altimp) {
        int totalore = this->ore + altimp.ore;
        int totalminute = this->minute + altimp.minute;
        //daca dep 60,trece in ore
        if(totalminute >= 60) {
            totalore = totalminute / 60;
            totalminute = totalminute % 60;
            
        }
        return Timp(totalore,totalminute);
        
    }
    
    //operator - scadere Timp
    Timp operator-(const Timp& altimp) {
        int totalminute1 = this->ore * 60 + this->minute;
        int totalminute2 = altimp.ore *60 + altimp.minute;
        
        int diferenta = totalminute1 - totalminute2;
        if(diferenta < 0) diferenta = 0;
        
        return Timp(diferenta / 60,diferenta % 60);
        
        
    }
    
    //operator mai mare
    bool operator>(const Timp& altimp) {
        int total1 = this->ore * 60 + this->minute;
        int total2 = altimp.ore *60 + altimp.minute;
        return total1 > total2;
        
    }
    //opeartor egal
    bool operator==(const Timp& altimp) {
        return(this->ore == altimp.ore && this->minute == altimp.minute);
        
    }
    
    //operator incrementare prefix
    Timp& operator++() {
        minute++;
        if(minute >=60) {
            ore++;
            minute = 0;
            
        }
        return *this;
        
    }
    
    //operator++ incrementare postfix
    Timp operator++(int) {
        Timp temp = *this;
        ++(*this);
        return temp;
        
        
    }
    
    void afisare() {
        cout << ore << "h " << minute << "m" << endl;
        
    }
    
    
 
    
};



int main() {
    Timp ora1(1,30); // o ora 30
    Timp ora2(0,45);
    Timp total = ora1 + ora2;
    cout<<"total este";
    total.afisare();
    
    Timp diferenta = ora1-ora2;
    cout<<"diferenta este ";
    diferenta.afisare();
    
    if(ora1 > ora2) {
        cout<<"1 mai mult ca 2";
    }
    
    
    Timp ora3(1,30);
    if(ora1==ora3) {
        cout<<"1 si 3 sunt egale";
        
    }
    
    Timp t(1,59);
    cout<<"initial";
    t.afisare();
    
    ++t;
    cout<<"dupa ++t";
    t.afisare();
    
    
    Timp t2(2,30);
    cout<<"t2";
    t2.afisare();
    
    Timp t3 = t2++;
    cout<<"t2 dupa t2++";
    t2.afisare();
    cout<<"t3 t2 vechi";
    t3.afisare();
    
    
    
  
        
    

    
	

}
