#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Rational{
private:
    int a,b;
    void reduction(){
        int GCD=__gcd(a,b);
        a/=GCD;
        b/=GCD;
    }
public:
    Rational(int = 0,int = 1){}
    void setRational(int x,int y){
        a=x;
        b=y;
        (*this).reduction();
    }
    void printRational(){
        cout<<a<<'/'<<b;
    }
    void printRationalAsDouble(){
        cout<<fixed<<setprecision(6)<<double(a)/double(b);
    }
    Rational addition(const Rational &y){
        Rational ans;
        ans.a=a*y.b+y.a*b;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational subtraction(const Rational &y){
        Rational ans;
        ans.a=a*y.b-y.a*b;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational multiplication(const Rational &y){
        Rational ans;
        ans.a=a*y.a;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational division(const Rational &y){
        Rational ans;
        ans.a=a*y.b;
        ans.b=b*y.a;
        ans.reduction();
        return ans;
    }
};

int main(){
    int x1,y1,x2,y2;
    Rational r1,r2,r3;
    cin>>x1>>y1;
    r1.setRational(x1,y1);
    cin>>x2>>y2;
    r2.setRational(x2,y2);

    r3=r1.addition(r2);
    r1.printRational();
    cout<<" + ";
    r2.printRational();
    cout<<" = ";
    r3.printRational();
    cout<<'\n';
    r3.printRational();
    cout<<" = ";
    r3.printRationalAsDouble();
    cout<<"\n\n";

    r3=r1.subtraction(r2);
    r1.printRational();
    cout<<" - ";
    r2.printRational();
    cout<<" = ";
    r3.printRational();
    cout<<'\n';
    r3.printRational();
    cout<<" = ";
    r3.printRationalAsDouble();
    cout<<"\n\n";

    r3=r1.multiplication(r2);
    r1.printRational();
    cout<<" x ";
    r2.printRational();
    cout<<" = ";
    r3.printRational();
    cout<<'\n';
    r3.printRational();
    cout<<" = ";
    r3.printRationalAsDouble();
    cout<<"\n\n";

    r3=r1.division(r2);
    r1.printRational();
    cout<<" / ";
    r2.printRational();
    cout<<" = ";
    r3.printRational();
    cout<<'\n';
    r3.printRational();
    cout<<" = ";
    r3.printRationalAsDouble();
    cout<<'\n';
}
