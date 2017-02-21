#include <bits/stdc++.h>
using namespace std;
#define N 50
int k,e,a[N],ans,len,ti=1;
string s,r[N],rr;
set <string>se;
 
string ddd(string s){
    int lens=s.size(),ri;
	string r;
    for(int i=0;i<lens;i++)
        if(isalpha(s[i]))
            r+=tolower(s[i]);
    return r;
}
 
int main(){
    while(cin>>k>>e){
    	memset(a,0,sizeof(a));
    	ans=0;
    	se.clear();
        for(int i=0;i<k;i++){
            cin>>s;
            se.insert(ddd(s));
        }
        cin>>ws;
        for(int i=0;i<e;i++){
            getline(cin,r[i]);
            stringstream ss(r[i]);
            while(ss>>s){
            	len=s.size();
	            for(int j=0;j<len;j++){
	            	rr="";
	            	while(isalpha(s[j])){
	            		rr+=tolower(s[j]);
	            		j++;
					}
					if(se.find(rr)!=se.end())a[i]++;
				}
			}
//			cout<<a[i]<<endl;
			ans=max(ans,a[i]);
        }
        cout<<"Excuse Set #"<<ti++<<endl;
        for(int i=0;i<e;i++){
        	if(a[i]==ans)
        		cout<<r[i]<<endl;
		}
		cout<<endl;
    }
}
