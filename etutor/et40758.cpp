#include <iostream>
using namespace std;

class HugeInteger{
private:
    static const int N=40;
    int a[N];
public:
    HugeInteger():a(){}
    void input(string s){
        for(int i=0;i<N;i++){
            a[i]=0;
        }
        for(int i=0;i<s.size();i++){
            a[s.size()-i-1]=s[i]-'0';
        }
        return;
    }
    const void output(){
        int i;
        for(i=N-1;i>=0&&!a[i];i--);
        if(i<0)cout<<'0';
        for(;i>=0;i--){
            cout<<a[i];
        }
        return;
    }
    int digitof()const{
        for(int i=N-1;i>=0;i--){
            if(this->a[i])return i+1;
        }
        return 0;
    }
    bool isEqualto(const HugeInteger &b){
        for(int i=N-1;i>=0;i--){
            if(a[i]!=b.a[i])return 0;
        }
        return 1;
    }
    bool isNotEqualto(const HugeInteger &b){
        return !(*this).isEqualto(b);
    }
    bool isGreaterThan(const HugeInteger &b){
        for(int i=N-1;i>=0;i--){
            if(a[i]>b.a[i])return 1;
            if(a[i]<b.a[i])return 0;
        }
        return 0;
    }
    bool isLessThan(const HugeInteger &b){
        for(int i=N-1;i>=0;i--){
            if(a[i]<b.a[i])return 1;
            if(a[i]>b.a[i])return 0;
        }
        return 0;
    }
    bool isGreaterThanOrEqualto(const HugeInteger &b){
        return !(*this).isLessThan(b);
    }
    bool isLessThanOrEqualto(const HugeInteger &b){
        return !(*this).isGreaterThan(b);
    }
    bool iszero(){
        for(int i=0;i<N;i++){
            if(a[i])return 0;
        }
        return 1;
    }
    HugeInteger add(const HugeInteger &b)const{
        HugeInteger v;
        int c=0;
        for(int i=0;i<N;i++){
            v.a[i]=a[i]+b.a[i]+c;
            c=v.a[i]/10;
            v.a[i]%=10;
        }
        return v;
    }
    HugeInteger subtract(const HugeInteger &b)const{
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
    HugeInteger multiply(const HugeInteger &b)const{
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
    HugeInteger divide(const HugeInteger &b)const{
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
    HugeInteger modulus(const HugeInteger &b)const{
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
//    HugeInteger modulus(const HugeInteger &b)const{
//        HugeInteger v1,v2,v3;
//        v1=(*this).divide(b);
//        v2=v1.multiply(b);
//        v3=(*this).subtract(v2);
//        return v3;
//    }
};

int main(){
    HugeInteger x,y,z;
    char ch;
    string s,r;
    cin>>ch;
    while(cin>>s>>r){
        x.input(s);
        y.input(r);
        switch(ch){
        case '+':
            z=x.add(y);
            break;
        case '-':
            z=x.subtract(y);
            break;
        case '*':
            z=x.multiply(y);
            break;
        case '/':
            z=x.divide(y);
            break;
        default:
            z=x.modulus(y);
            break;
        }
        x.output();
        cout<<' '<<ch<<' ';
        y.output();
        cout<<" = ";
        z.output();
        cout<<'\n';
    }
}
