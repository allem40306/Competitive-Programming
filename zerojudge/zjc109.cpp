#include <bits/stdc++.h>
using namespace std;
const int N=205;

int main(){
	int n,k,a[N],ord[N][N];//order
	string s;
	char ans[N];
    while(cin>>n,n){
		for(int i=1;i<=n;i++){
            cin>>a[i];
		}
		for(int i=1;i<=n;i++){
            int tmp=i,j=0;
            do{
                ord[i][++j]=tmp;
                tmp=a[tmp];
            }while(i!=tmp);
            ord[i][0]=j;
		}
		while(cin>>k,k){
            getline(cin,s);
            s=s.substr(1,s.size()-1);
            for(int i=1;i<=n;i++){
                ans[i]=' ';
            }
            for(int i=1,j;i<=s.size();i++){
                j=k%ord[i][0];
                ans[ord[i][j+1]]=s[i-1];
            }
            for(int i=1;i<=n;i++){
                cout<<ans[i];
            }
            cout<<'\n';
		}
		cout<<'\n';
	}
}
