#include <iostream>
#include <iomanip>
using namespace std;

class Complex{
private:
    double realPart;
    double imaginaryPart;
public:
    Complex():realPart(0.0),imaginaryPart(0.0){}
    Complex add(const Complex &b){
        Complex v;
        v.realPart=realPart+b.realPart;
        v.imaginaryPart=imaginaryPart+b.imaginaryPart;
        return v;
    }
    Complex subtract(const Complex &b){
        Complex v;
        v.realPart=realPart-b.realPart;
        v.imaginaryPart=imaginaryPart-b.imaginaryPart;
        return v;
    }
    Complex multiply(const Complex &b){
        Complex v;
        v.realPart=realPart*b.realPart-imaginaryPart*b.imaginaryPart;
        v.imaginaryPart=realPart*b.imaginaryPart+imaginaryPart*b.realPart;
        return v;
    }
    Complex divide(const Complex &b){
        Complex bb=b; bb.imaginaryPart*=-1;
        Complex v=(*this).multiply(bb);
        double deno=b.realPart*b.realPart+b.imaginaryPart*b.imaginaryPart;
        v.imaginaryPart/=deno;
        v.realPart/=deno;
        return v;
    }
    void printComplex(){
        cout<<fixed<<setprecision(6)<<'('<<realPart<<", "<<imaginaryPart<<')';
    }
    void setComplexNumber(double r,double i){
        realPart=r;
        imaginaryPart=i;
    }
};

int main(){
    Complex a,b,c;
    double i1,r1,i2,r2;
    cin>>r1>>i1>>r2>>i2;
    a.setComplexNumber(r1,i1);
    b.setComplexNumber(r2,i2);

    c=a.add(b);
    a.printComplex();
    cout<<" + "; 
    b.printComplex();
    cout<<" = "; 
    c.printComplex();
    cout<<'\n';

    c=a.subtract(b);
    a.printComplex();
    cout<<" - "; 
    b.printComplex();
    cout<<" = "; 
    c.printComplex();
    cout<<'\n';

    c=a.multiply(b);
    a.printComplex();
    cout<<" * "; 
    b.printComplex();
    cout<<" = "; 
    c.printComplex();
    cout<<'\n';

    c=a.divide(b);
    a.printComplex();
    cout<<" / "; 
    b.printComplex();
    cout<<" = "; 
    c.printComplex();
    cout<<'\n';
}
