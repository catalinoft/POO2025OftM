#include <iostream>
using namespace std;

class Timp {
    private:
    int ore;
    int minute;
    public:
    Timp(int o=0,int m=0) : ore(o),minute(m) {
        if(minute >= 60) {
            ore += minute / 60;
            minute = minute % 60;
            
        }
    } 
    
    //operator adunare
    Timp operator+(const Timp& alttimp) {
        int totalore = this->ore + alttimp.ore;
        int totalminute = this->minute + alttimp.minute;
        //daca depasesete 60,transforma in minute
        if(totalminute >= 60) {
            totalore += totalminute / 60;
            totalminute = totalminute % 60;
        }
        return(totalore,totalminute);
        
    }
    
    //operator scadere
    Timp operator-(const Timp& alttimp) {
        int totalminute1 = this->ore * 60 + this->minute;
        int totalminute2 = alttimp.ore * 60 + alttimp.minute;
        
        int diferenta = totalminute1 - totalminute2;
        if(diferenta < 0) diferenta = 0;
        return Timp(diferenta / 60,diferenta % 60);
    }
    
    //operator > mai mare
    bool operator>(const Timp& alttimp) {
        int total1 = this->ore * 60 + this->minute;
        int total2 = alttimp.ore * 60 + alttimp.minute;
        return total1 > total2;
    }
    
    //operator = =egal
    bool operator==(const Timp& alttimp) {
        return (this->ore == alttimp.ore && this->minute == alttimp.minute);
        
    }
    
    //opeartor ++ incrementare prefix
    Timp& operator++() {
        minute++;
        if(minute >= 60) {
            ore++;
            minute = 0;
            
        }
        return *this;
        
    }
    
    //operator ++ incrementare postfix
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
	Timp curs1(1,30);
	Timp curs2(0,45);
	cout<<"+"<<endl;
	Timp total = curs1+curs2;
	cout<<"rez este: ";
	total.afisare();
	cout<<"-"<<endl;
	Timp diferenta = curs1-curs2;
	cout<<"rez este:";
	diferenta.afisare();
	
	cout<<">"<<endl;
	if(curs1 > curs2) {
	    cout<<"curs1 mai mare"<<endl;
	}
	
	cout<<"=="<<endl;
	Timp curs3(1,30);
	if(curs1 == curs3) {
	    cout<<"egale"<<endl;
	    
	    
	}
	
	cout<<"++ prefix"<<endl;
	Timp t(1,59);
	cout<<"Initial";
	t.afisare();
	
	++t;
	cout<<"dupa ++t";
	t.afisare();
	
	cout<<"++ postfx"<<endl;
	Timp t2(2,30);
	cout<<"t2:";
	t2.afisare();
	
	Timp t3 = t2++;
	cout<<"t2 dupa t2++";
	t2.afisare();
	cout<<"t3 vechea 2";
	t3.afisare();
	    
	
}
