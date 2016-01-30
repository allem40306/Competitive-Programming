#include <iostream>
#include <string>
#include <sstream> 
using namespace std;
#define gor(a,b,c) for(a=b;a<c;a++)

void ooo(string a){
	int len=a.length();
	for(int i=len-1;i>=0;i--)
		printf("%c",a[i]);
}

int main() {
	string s;
	while(cin>>s){
		stringstream ss(s);
		string w;
		int o=0;
		while(ss>>w){
			if(o++)printf(" ");
			ooo(w);
		}
		printf("\n");
	}
}
