#include <iostream>
#include <string>
using namespace std;
#define N 100000

int main(){
	int t,i;
	string s;
	for(i=0,cin>>t;i<t;i++){
		cin>>s;
		int i,len=s.length();
		for(i=2;i<len;i++){
			if(len%i==0&&s.substr(0,len-i)==s.substr(i,len-i))break;
		}
		printf("%d\n",i);
	}
}
