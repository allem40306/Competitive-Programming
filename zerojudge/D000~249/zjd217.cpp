#include <bits/stdc++.h>
using namespace std;

int main(){
	int id,g[30],used[30],w,l;
	string s1,s2;
	while(cin>>id,id!=-1){
		memset(g,0,sizeof(g));
		memset(used,0,sizeof(used));
		w=0;
		l=7;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			if(!g[s1[i]-'a'])w+=1;
			g[s1[i]-'a']=1;
		}
		for(int i=0;i<s2.size();i++){
			if(g[s2[i]-'a']){
				w--;
				g[s2[i]-'a']=0;
			}else if(!used[s2[i]-'a']){
				l--;
			}
			if(!w||!l)break;
            used[s2[i]-'a']=1;
		}
		cout<<"Round "<<id<<"\n";
		cout<<(!w?"You win.\n":(!l?"You lose.\n":"You chickened out.\n"));
	}
}
