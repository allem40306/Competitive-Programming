#include <iostream>
#include <string>
using namespace std;
int main(){
	int n; string s;
	while(scanf("%d",&n)&&n>=0){
		if(!n)printf("0\n");
		else{s="";while(n){s=char((n%3)+'0')+s;n/=3;}
		cout<<s<<endl;
		}
	}
}
