#include <bits/stdc++.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum Tip { TELEFON=1, TABLETA=2, LAPTOP=3 };

class DispozitivElectronic {
    private:
    const int id;
    float pret;
    string model;
    Tip tip;
    int nrSpecificatii;
    float* valorispecificatii; //ram storage ecran 
    static int nrTotalDispozitive;
    public:
    //constructor default
    DispozitivElectronic() :id(++nrTotalDispozitive) {
    this->model = "dispozitiv default";
    this->pret = 0;
    this->nrSpecificatii = 0;
    this->valorispecificatii = nullptr;
    this->tip = TELEFON;
    }
    
    //constructor cu parametrii
    DispozitivElectronic(string model,float pret,int nrSpecificatii,float* specificatii,Tip tip) :id(++nrTotalDispozitive) {
        this->valorispecificatii = new float[this->nrSpecificatii];
        for(int i=0;i<this->nrSpecificatii;i++) {
            this->valorispecificatii[i] = specificatii[i];
            
        }
    }
    //constructor de copiere
    DispozitivElectronic(const DispozitivElectronic& const) :id(++nrTotalDispozitive) {
        this->model = copie.model;
        this->pret = copie.pret;
        this->tip = copie.tip;
        this->nrSpecificatii = copie.nrSpecificatii;
        if(copie.valorispecificatii != nullptr && copie.nrSpecificatii > 0) {
            this->valorispecificatii = new float[this->nrSpecificatii];
            for(int i=0;i<this->nrSpecificatii;i++) {
                this->valorispecificatii[i] = copie.valorispecificatii[i];
                
                
            }
        }
        else {
            this->valorispecificatii = nullptr;
            this->nrSpecificatii = 0;
            
        }
    }
    
    //operator atribuire
    void operator=(const DispozitivElectronic& copie) {
        this->model = copie.model;
        this->pret = copie.pret;
        this->tip = copie.tip;
        this->nrSpecificatii = copie.nrSpecificatii;
        if(this->valorispecificatii != nullptr) {
            delete[] this->valorispecificatii;
        }
        
        if(copie.valorispecificatii != nullptr && copie.nrSpecificatii > 0) {
            this->valorispecificatii = new float[copie.nrSpecificatii];
            for(int i=0;i<this->nrSpecificatii;i++) {
                this->valorispecificatii[i] = copie.valorispecificatii[i];
                
            }
        }
        else {
            this->valorispecificatii = nullptr;
        }
    }
    
    void afisaredispoztivi() {
        cout<<endl<<this->id<<"dispozitivul electronic"<<this->model<<"costa"<<this->pret<<"lei,este de tipul";
        if(this->tip == TELEFON) cout<<"telefon";
        if(this->tip == TABLETA) cout<<"tableta";
        if(this->tip == LAPTOP) cout<<"laptop";
        cout<<"si are"<<this->nrSpecificatii<<"specificatii:";
        if(this->valorispecificatii != nullptr) {
            for(int i=0;i,this->nrSpecificati-1;i++) {
                cout<<this->valorispecificatii<<",";
                
                
            }
            cout<<this->valorispecificatii[this->nrSpecificati-1]<<".";
            
        }
    }
    
    //getter si setter pentru nr specificatii
    int getNrspecificatii() {
        return this->nrSpecificatii;
    }
    
    void setNrSpecificatii(int nrSpecificatiiNou) {
        if(nrSpecificatiiNou > 0) {
            this->nrSpecificatii = nrSpecificatiiNou;
        
    }
    }
    
    //getter si setter pentru pointer
    float* getValorispecificatii() {
        if(this->valorispecificatii != nullptr) {
            float* copieSpecificatii = new float[this->nrSpecificatii];
            for(int i=0;i<this->nrSpecificatii;i++) {
                copieSpecificatii = this->valorispecificatii;
                
            }
            return copieSpecificatii;
            
        }
    }
        
        void setValorispecificatii(float* specificatiiNoi,int nrSpecificatiiNou) {
            setNrSpecificatii(nrSpecificatiiNou);
            if(this->valorispecificatii != nullptr) {
                delete[] this->valorispecificatii;
            }
            this->valorispecificatii = new float[this->nrSpecificatii];
            for(int i=0;i<this->nrSpecificatii;i++) {
                this->valorispecificatii[i] = specificatiiNoi[i];
                
            }
            
            
        }
        
        //getteris si setteri simpli
        string getModel() {
            return this->model;
            
        }
        float GetPret() {
            return this->pret;
        }
        Tip GetTip() {
            return this->tip;
        }
        int GetId() {
            return this->id;
        }
        //setteri simpli
        void setModel(string modelnou) {
            this->model = modelnou;
            
        }
        void setpret(float pretnou) {
            this->pret = pretnou;
            
        }
        void setTip(Tip tipnou) {
            this->tip = tipnou;
        }
        ~DispozitivElectronic() {
            if(this->valorispecificatii != nullptr) {
                delete[] this->valorispecificatii;
                
            }
        }
        
        
        
        
    
    
    
    
};


int DispozitivElectronic::nrTotalDispozitive=0;

int main() {
    //dispozitiv default
    DispozitivElectronic dispozitiv1;
    dispozitiv1.afisaredispoztivi();
    //dispozitiv cu paramatrii
    float* specificatii = new float[3] {8.0,256.0,6.1}; //ram storage diagonala ecran
    DispozitivElectronic* telefon = new DispozitivElectronic("samsung",2500,3,specificatii,TELEFON);
    telefon->afisaredispoztivi();
    //constructor copiere
    DispozitivElectronic telefoncopiat(*telefon);
    cout<<endl<<"Dispozitiv copiat";
    //operatov atribuire
    DispozitivElectronic tableta;
    tableta = *telefon;
    cout<<"Tableta dupa atribuire";
    tableta.afisaredispoztivi();
    //testare getteri si setteri
    cout<<endl<<"Model"<<telefon->getModel();
    cout<<endl<<"Pret"<<telefon->GetPret()<<"lei";
    cout<<endl<<"Tip"<<telefon->GetTip();
    cout<<endl<<"ID"<<telefon->GetId();
    cout<<endl<<"Nr specificatii"<<telefon->getNrspecificatii();
    
    
    //testare setteri
    telefon->setModel("Samsung galaxy");
    telefon->setpret(2800);
    telefon->setTip(TELEFON);
    cout << endl << endl << "--- Dupa modificari ---";
    telefon->afisaredispoztivi();
    
    //testare getter pentru specificatii;
    float* specActuale = telefon->getValorispecificatii();
    cout << endl << endl << "Specificatii actuale: "
    for(int i=0;i<telefon->getNrspecificatii;i++) {
        cout<<specActuale[i]<<"";
        
        
    }
    
    delete[] specActuale;
    delete[] telefon;
    delete[] Specificatii;
    
    
    
    
    
}