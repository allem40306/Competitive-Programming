#include <bits/stdc++.h>
using namespace std;
const int N=100005;
char ch[N];

int main(){
    int n,d;
    string s;
    while(cin>>n>>d,n||d){
        cin>>s;
        int cnt=0;
        int k=n-d;
        for(int i=0;i<s.size();i++){
            while(cnt&&n+(cnt-i)>k&&s[i]>ch[cnt-1])cnt--;
            if(cnt<k)ch[cnt++]=s[i];
        }
        for(int i=0;i<k;i++)cout<<ch[i];
        cout<<'\n';
    }
}