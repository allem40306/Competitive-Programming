#include <iostream>
#include <iomanip>
using namespace std;

class Complex{
private:
    double realPart;
    double imaginaryPart;
public:
    Complex(double a= 0.0,double b= 0.0){
        realPart=a;
        imaginaryPart=b;
    }
    Complex operator+(const Complex &b){
        Complex v;
        v.realPart=realPart+b.realPart;
        v.imaginaryPart=imaginaryPart+b.imaginaryPart;
        return v;
    }
    Complex operator-(const Complex &b){
        Complex v;
        v.realPart=realPart-b.realPart;
        v.imaginaryPart=imaginaryPart-b.imaginaryPart;
        return v;
    }
    Complex operator*(const Complex &b){
        Complex v;
        v.realPart=realPart*b.realPart-imaginaryPart*b.imaginaryPart;
        v.imaginaryPart=realPart*b.imaginaryPart+imaginaryPart*b.realPart;
        return v;
    }
    Complex operator/(const Complex &b){
        Complex bb=b; bb.imaginaryPart*=-1;
        Complex v=(*this)*(bb);
        double deno=b.realPart*b.realPart+b.imaginaryPart*b.imaginaryPart;
        v.imaginaryPart/=deno;
        v.realPart/=deno;
        return v;
    }
    bool operator==(const Complex &b)const{
        return (*this).realPart==b.realPart&&(*this).imaginaryPart==b.imaginaryPart;
    }
    bool operator!=(const Complex &b)const{
        return !(*this==b);
    }
    friend ostream& operator<<(ostream &out,const Complex &n);
    friend istream& operator>>(istream &in,Complex &n);
};

ostream& operator<<(ostream &out,const Complex &n){
    out<<fixed<<setprecision(2)<<'('<<n.realPart<<", "<<n.imaginaryPart<<')';
    return out;
}

istream& operator>>(istream &in,Complex &n){
    in>>n.realPart>>n.imaginaryPart;
    return in;
}

int main(){
    Complex a,b,c;
    cin>>a>>b;
    cout<<a<<" + "<<b<<" = "<<(c=a+b)<<'\n';
    cout<<a<<" - "<<b<<" = "<<(c=a-b)<<'\n';
    cout<<a<<" * "<<b<<" = "<<(c=a*b)<<'\n';
    cout<<a<<" != "<<b<<" = "<<(a!=b?"True":"False")<<'\n';
    cout<<a<<" == "<<b<<" = "<<(a==b?"True":"False")<<'\n';
}
