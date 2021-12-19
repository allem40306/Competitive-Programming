#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Rational{
private:
    long long a,b;
    void reduction(){
        int GCD=__gcd(a,b);
        a/=GCD;
        b/=GCD;
    }
public:
    Rational(long long x = 0,long long y = 1){
        a=x;
        b=y;
        (*this).reduction();
    }
    double DoubleFrom(){
        return (double)a/(double)b;
    }
    Rational operator+(const Rational &y)const{
        Rational ans;
        ans.a=a*y.b+y.a*b;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational operator-(const Rational &y)const{
        Rational ans;
        ans.a=a*y.b-y.a*b;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational operator*(const Rational &y)const{
        Rational ans;
        ans.a=a*y.a;
        ans.b=b*y.b;
        ans.reduction();
        return ans;
    }
    Rational operator/(const Rational &y)const{
        Rational ans;
        ans.a=a*y.b;
        ans.b=b*y.a;
        ans.reduction();
        return ans;
    }
    friend ostream&operator<<(ostream &out,const Rational &n);
    friend istream&operator>>(istream &out,Rational &n);
};

ostream&operator<<(ostream &out,const Rational &n){
    out<<n.a<<'/'<<n.b;
    return out;
}

istream&operator>>(istream &in,Rational &n){
    in>>n.a>>n.b;
    n.reduction();
    return in;
}

int main(){
    Rational r1,r2,r3;
    cin>>r1>>r2;
    cout<<r1<<" + "<<r2<<" = "<<(r3=r1+r2)<<'\n';
    cout<<r3<<" = "<<fixed<<setprecision(6)<<r3.DoubleFrom()<<'\n';
    cout<<'\n';
    cout<<r1<<" - "<<r2<<" = "<<(r3=r1-r2)<<'\n';
    cout<<r3<<" = "<<fixed<<setprecision(6)<<r3.DoubleFrom()<<'\n';
    cout<<'\n';
    cout<<r1<<" x "<<r2<<" = "<<(r3=r1*r2)<<'\n';
    cout<<r3<<" = "<<fixed<<setprecision(6)<<r3.DoubleFrom()<<'\n';
    cout<<'\n';
    cout<<r1<<" / "<<r2<<" = "<<(r3=r1/r2)<<'\n';
    cout<<r3<<" = "<<fixed<<setprecision(6)<<r3.DoubleFrom()<<'\n';
}
