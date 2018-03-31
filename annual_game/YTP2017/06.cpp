#include<bits/stdc++.h>
using namespace std;
string f="CDHS",f2="123456789TJQK";
int num(char a,char b){
	for(int i=0;;i++){
		if(a==f[i]){
			for(int j=0;;j++){
				if(b==f2[j]){
					return i*13+j;
				}
			}
		}
	}
}
int main(){
	int p[10][10],sr=0;
	string s,s1,s2;
	cin>>s>>s1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			p[i][j]=num(s[sr],s[sr+1]);
			sr+=2;
		}
	}
	int np=0;
	
}
