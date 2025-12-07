#include <iostream>
using namespace std;

class Vector2D {
    private:
    float x,y;
    
    public:
    Vector2D(float x=0,float y=0) : x(x), y(y) {}
    
    //operator adunare
    Vector2D operator+(const Vector2D& altvector) {
        return Vector2D(this->x + altvector.x ,this->y + altvector.y);
    }
    //operator --
    Vector2D operator-(const Vector2D& altvector) {
        return Vector2D(this->x - altvector.x, this->y - altvector.y);
    }
    //operator * inmultire
    Vector2D operator*(float scalar) {
        return Vector2D(this->x * scalar,this->y * scalar);
    }
    //operator / impartire
    Vector2D operator/(float scalar) {
        if(scalar == 0) return *this;
        return Vector2D(this->x/scalar,this->y/scalar);
    }
    
    //operator == egalitate
    bool operator==(const Vector2D& altvector) {
        return (this->x == altvector.x,this->y == altvector.y);
    }
    
    //operator +=
    Vector2D& operator+=(const Vector2D& altvector) {
        this->x += altvector.x;
        this->y += altvector.y;
        return *this;
        
    }
    //operator *=
    Vector2D& operator*=(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }
    //operator [] index
    float& operator[](int index) {
        if(index==0) return x;
        if(index==1) return y;
        throw "index invalid";
        
    }
    //operator de afisare
    friend ostream& operator<<(ostream& os,const Vector2D& v) {
        os<<"("<<v.x<<","<<v.y<<")";
        return os;
    }
  


    
  
    
};

int main() {
    Vector2D v1(3,4);
    Vector2D v2(1,2);
    cout<<"v1 e "<<v1<<endl;
    cout<<"v2 e"<<v2<<endl;
    
    cout<<"+"<<endl;
    Vector2D suma = v1+v2;
    cout<<"suma este"<<suma<<endl;
    
    cout<<"-"<<endl;
    Vector2D diferenta = v1-v2;
    cout<<"dif este"<<diferenta<<endl;
    
    cout<<"*"<<endl;
    Vector2D inmultit = v1 * 2;
    cout<<"inmultire"<<inmultit<<endl;
    
    cout<<"/"<<endl;
    Vector2D impartit = v1 / 2;
    cout<<"impartit"<<impartit<<endl;
    
    cout<<"+= "<<endl;
    Vector2D v3(5,5);
    cout<<"v3 i"<<v3<<endl;
    v3 += v1;
    cout<<"v3 dupa"<<v3<<endl;
    
    cout<<"*="<<endl;
    Vector2D v4(2,3);
    cout<<"v4 ini"<<v4<<endl;
    v4 *= 3;
    cout<<"v4 este "<<v4<<endl;
    
    cout<<"[]"<<endl;
    Vector2D v5(7,8);
     cout << "v5[0] = " << v5[0] << endl;  // 7
     cout << "v5[1] = " << v5[1] << endl;  // 8
     
    //modificare prin []
    v5[0] = 10;
    v5[1] = 20;
    cout<<"v5"<<v5<<endl;
    
    cout<<"op =="<<endl;
    Vector2D v6(3,4);
    if(v1==v6) {
        cout<<"unt egale"<<endl;
    }
    
    //lant de operatii
    cout<<"lant"<<endl;
    Vector2D rezultat = (v1 + v2) * 2 - Vector2D(1, 1);
    cout << "(v1 + v2) * 2 - (1,1) = " << rezultat << endl;
    
    

	    
	
}
