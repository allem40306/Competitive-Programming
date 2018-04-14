#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
#define N 1005
#define M 26
string s[N],ss[N];
int t;

void mode(string a,int p){
	int list[M],li=0,lens=a.length();
	memset(list,-1,sizeof(list));
	for(int i=0;i<lens;i++){
		int ap=int(a[i]-'a');
		if(list[ap]==-1)list[ap]=li++;
		ss[p]+=char(97+ap);
		}
}

void mode2(string a,string b){
	int list[M],li=0,lens=a.length(),i;
	memset(list,-1,sizeof(list));
	for(i=0;i<lens;i++){
		int ap=(a[i]-'a');
		if(list[ap]==-1)list[ap]=li++;
		b+=char(97+ap);
		}
	for(i=0;i<t;i++){
		if(b==ss[i]){
			cout<<ss[i]<<endl;	
			break;
		}
	}
	if(i==t){
		for(i=0;i<lens;i++)printf("*");
	}
}

int main() {
	while(cin>>t){
	for(int i=0;i<t;i++)cin>>s[i];
	for(int i=0;i<t;i++)mode(s[i],i);
	string s2;
	while(getline(cin,s2)){
		stringstream ss3(s2);
		int p3=0;
		while(ss3>>s2){
			if(p3++)printf(" ");
			(mode2(s2,""));
		}	
		printf("\n");
	}
	}	
}
