    #include <bits/stdc++.h>
using namespace std;
const int N=255;

int main(){
    string s,r;
    int a[N],b[N],c[2*N];
    while(cin>>s){
        cin>>r;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<s.size();i++){
            a[i]=(s[s.size()-1-i]-'0');
        }
        for(int i=0;i<r.size();i++){
            b[i]=(r[r.size()-1-i]-'0');
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<r.size();j++){
                c[i+j]+=a[i]*b[j];
            }
        }
        for(int i=0;i<2*N-1;i++){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        int r=2*N-1;
        while(r>=0&&c[r]==0)r--;
        if(r==-1)cout<<0;
        while(r>=0)cout<<c[r--];
        cout<<'\n';
    }
}
