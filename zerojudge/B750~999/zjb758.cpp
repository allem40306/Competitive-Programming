#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int h,m;
	while(cin>>h>>m){
		int h1,m1;
		m1=(m+30)%60;
		h1=(h+(m+30)/60+2)%24;
		printf("%s%d:%s%d\n",((h1/10)?"":"0"),h1, ((m1/10)?"":"0") ,m1);
	}
}
