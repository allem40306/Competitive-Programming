#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int x,y,z,w,n,m,t,now,dead,i,out;
	cin>>t;
	while(t--){
		dead=0;
		cin>>x>>y>>z>>w>>n>>m;
		getline(cin,s);
		now=m;
		out=0;
		getline(cin,s);
		for(i=0;i<s.size();i++){
			if(s[i]>='0' && s[i]<='4')
				now-=out;
			if(now<=0)
				dead=1;
			if(s[i]=='1')
				now+=x;
			else if(s[i]=='2')
				now+=y;
			else if(s[i]=='3')
				now-=z;
			else if(s[i]=='4')
				now-=w,out+=n;
			if(now<=0)
				dead=1;
		}
		if(dead)
			cout<<"bye~Rabbit\n";
		else
			cout<<now<<"g\n";
	}
}
