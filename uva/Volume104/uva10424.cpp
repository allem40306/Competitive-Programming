#include <bits/stdc++.h>
using namespace std;

int sti(string s){//string to value
    int x=0;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            x+=(tolower(s[i])-'a'+1);
        }
    }
//    cout<<s<<' '<<x<<'\n';
    return x;
}

double itv(int x){//integer to value
    double a=0;
    while(x){
        a+=x%10;
        x/=10;
    }
    return(a>9?itv(int(a)):a);
}

int main(){
    string s,r;
    while(getline(cin,s)){
        getline(cin,r);
        double v1=itv(sti(s)),v2=itv(sti(r));
        cout<<fixed<<setprecision(2)<<min(v1,v2)/max(v1,v2)*100.0<<" %\n";
    }
}
