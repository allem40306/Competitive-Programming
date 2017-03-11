#include <bits/stdc++.h>
using namespace std;
int n,ni=0,a,b,c,d,e,len,oo[10],oi,xx;
bool f;
string s,r;
int stoi(){
	int ans=0;
	for(int i=0;i<a;i++)
		ans=ans*26+(s[i]-'A')+1;
	return ans;
}
int toi(int a){
	int ans=0;
	for(int i=a;i<len;i++)
		ans=ans*10+(s[i]-'0');
	return ans;
}
void itos(int x){
	xx=x;
	r="";
	oi=-1;
	while(x){
		if(x==26){
			oo[++oi]=25;
			break;
		}
		oo[++oi]=x%26-1;
		x/=26;
	}
	for(c=0;c<=oi;c++){
		if(oo[c]<0){
			oo[c]+=26;
			oo[c+1]--;
		}
	}
	for(c=0,d=0,e=1;c<=oi;c++){
		d+=e*(oo[c]+1); e*=26; 
		if(d>xx)break;
		r=char('A'+oo[c])+r;
	}
	cout<<r;
	return;
}
bool ddd(){
	for(c=2;c<len;c++)
		if(isalpha(s[c]))return 1;
	return 0;
}
int main (){
	for(cin>>n;ni<n;ni++){
		memset(oo,0,sizeof(oo));
		cin>>s;
		len=s.size();
		if(s[0]=='R'&&isdigit(s[1])&&ddd()){
			for(a=1;isdigit(s[a]);a++);
			itos(toi(a+1));
			for(b=1;b<a;b++)
				cout<<s[b];
			cout<<endl;
		}else{
			for(a=0;!isdigit(s[a]);a++);
			cout<<'R';   
			for(b=a;b<len;b++)
				cout<<s[b];
			cout<<'C'<<stoi()<<endl;
		}
	}
}

