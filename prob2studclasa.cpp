#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    int varsta;
    double medie;
    
public:
    // Constructor
    Student(string n, int v, double m) {
        nume = n;
        varsta = v;
        medie = m;
    }
    
    // Metodă pentru afișare profil
    void afiseazaProfil() {
        cout << "Nume: " << nume << endl;
        cout << "Varsta: " << varsta << " ani" << endl;
        cout << "Media: " << medie << endl;
        
        if (medie >= 9.5) {
            cout << "Status: Bursier" << endl;
        } else if (medie >= 8.0) {
            cout << "