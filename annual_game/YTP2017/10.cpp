#include <bits/stdc++.h>
using namespace std;
int dis(int a,int b,int c,int d){
	double i=sqrt((a-b)*(a-b)+(c-d)*(c-d));
	return round(i);
}
int main(){
	int a,b,len,h=0;
	char ch;
	cin>>a;
	while(cin>>ch>>b){
		len=dis(a/10,b/10,a%10,b%10);
		if(len<5)h+=5-len;
	}
	printf("%.2d",h);
}
