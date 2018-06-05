#include <iostream>
using namespace std;
static const int N=40;

class HugeInteger{
private:
    int a[N];
    int digitof()const{
        for(int i=N-1;i>=0;i--){
            if(this->a[i])return i+1;
        }
        return 0;
    }
public:
    HugeInteger():a(){}
    bool operator ==(const HugeInteger &b){
        for(int i=N-1;i>=0;i--){
            if(a[i]!=b.a[i])return 0;
        }
        return 1;
    }
    bool operator <(const HugeInteger &b)const{
        for(int i=N-1;i>=0;i--){
            if(a[i]<b.a[i])return 1;
            if(a[i]>b.a[i])return 0;
        }
        return 0;
    }
    bool operator >(const HugeInteger &b)const{
        return b<(*this);
    }
    bool operator >=(const HugeInteger &b)const{
        return !((*this)<b);
    }
    bool operator <=(const HugeInteger &b)const{
        return !(b<(*this));
    }
    bool operator ==(const HugeInteger &b)const{
       return !((*this)<b)&&!(b<(*this));
    }
    bool operator !=(const HugeInteger &b)const{
        return (*this)<b||b<(*this);
    }
    bool iszero(){
        for(int i=0;i<N;i++){
            if(a[i])return 0;
        }
        return 1;
    }
    HugeInteger operator +(const HugeInteger &b)const{
        HugeInteger v;
        int c=0;
        for(int i=0;i<N;i++){
            v.a[i]=a[i]+b.a[i]+c;
            c=v.a[i]/10;
            v.a[i]%=10;
        }
        return v;
    }
    HugeInteger operator -(const HugeInteger &b)const{
        HugeInteger v,w=(*this);
        for(int i=0;i<N;i++){
            v.a[i]=w.a[i]-b.a[i];
            if(i!=N-1&&v.a[i]<0){
                v.a[i]+=10;
                w.a[i+1]--;
            }
        }
        return v;
    }
    HugeInteger operator *(const HugeInteger &b)const{
        HugeInteger v;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i+j>=N)break;
                v.a[i+j]+=a[i]*b.a[j];
            }
        }
        for(int i=0;i<N-1;i++){
            v.a[i+1]+=v.a[i]/10;
            v.a[i]%=10;
        }
        return v;
    }
    HugeInteger operator /(const HugeInteger &b)const{
        HugeInteger v=(*this),ans;
        int d1=(*this).digitof(),d2=b.digitof();
        for(int i=d1-d2;i>=0;i--){
            int bo,s;
            while(1){
                bo=0; s=0;
                for(int j=0;j<d2;j++){
                    s=-bo+v.a[i+j]-b.a[j];
                    if(s<0)bo=(-s+9)/10;
                    else bo=0;
                }
                if(bo&&(i+d2>=d1||bo>v.a[i+d2]))break;
                ans.a[i]++;
                for(int j=d2-1;j>=0;j--){
                    v.a[i+j]-=b.a[j];
                    while(v.a[i+j]<0){
                        v.a[i+j+1]--;
                        v.a[i+j]+=10;
                    }
                }
            }
        }
        for(int i=0;i<N-1;i++){
            while(v.a[i]<0){
                v.a[i]+=10;
                v.a[i+1]--;
            }
        }
        return ans;
    }
    HugeInteger operator %(const HugeInteger &b)const{
        HugeInteger v=(*this),ans;
        int d1=(*this).digitof(),d2=b.digitof();
        for(int i=d1-d2;i>=0;i--){
            int bo,s;
            while(1){
                bo=0; s=0;
                for(int j=0;j<d2;j++){
                    s=-bo+v.a[i+j]-b.a[j];
                    if(s<0)bo=(-s+9)/10;
                    else bo=0;
                }
                if(bo&&(i+d2>=d1||bo>v.a[i+d2]))break;
                ans.a[i]++;
                for(int j=d2-1;j>=0;j--){
                    v.a[i+j]-=b.a[j];
                    while(v.a[i+j]<0){
                        v.a[i+j+1]--;
                        v.a[i+j]+=10;
                    }
                }
            }
        }
        for(int i=0;i<N-1;i++){
            while(v.a[i]<0){
                v.a[i]+=10;
                v.a[i+1]--;
            }
        }
        return v;
    }
    HugeInteger operator +=(const HugeInteger &b){
        (*this)=(*this)+b;
    }
    HugeInteger operator -=(const HugeInteger &b){
        (*this)=(*this)-b;
    }
    HugeInteger operator *=(const HugeInteger &b){
        (*this)=(*this)*b;
    }
    HugeInteger operator /=(const HugeInteger &b){
        (*this)=(*this)/b;
    }
    HugeInteger operator %=(const HugeInteger &b){
        (*this)=(*this)%b;
    }
friend ostream& operator << (ostream &,HugeInteger &);
friend istream& operator >> (istream &in,HugeInteger &n);
};

istream& operator >> (istream &in,HugeInteger &n){
    string s;
    in>>s;
    for(int i=0;i<N;i++){
            n.a[i]=0;
        }
    for(int i=0;i<s.size();i++){
        n.a[s.size()-i-1]=s[i]-'0';
    }
    return in;
}

ostream& operator << (ostream &out,HugeInteger &n){
    int i;
    for(i=N-1;i>=0&&!n.a[i];i--);
    if(i<0)out<<'0';
    for(;i>=0;i--){
        out<<n.a[i];
    }
    return out;
}

int main(){
    HugeInteger x,y,z;
    cin>>x>>y;
    cout<<x<<" + "<<y<<" = "<<(z=x+y)<<'\n';
    if(x>=y)cout<<x<<" - "<<y<<" = "<<(z=x-y)<<'\n';
    else cout<<x<<" - "<<y<<" = -"<<(z=y-x)<<'\n';
    cout<<x<<" * "<<y<<" = "<<(z=x*y)<<'\n';
    cout<<x<<" / "<<y<<" = "<<(z=x/y)<<" ... ";
    cout<<(z=x%y)<<'\n';
    cout<<x<<" > "<<y<<" = "<<(x>y?"True\n":"False\n");
    cout<<x<<" < "<<y<<" = "<<(x<y?"True\n":"False\n");
    cout<<x<<" == "<<y<<" = "<<(x==y?"True\n":"False\n");
    cout<<x<<" != "<<y<<" = "<<(x!=y?"True\n":"False\n");

}
