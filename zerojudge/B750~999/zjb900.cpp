#include <iostream>
#include <string> 
using namespace std;

int main(){
	int h,w,i,j,x;
	string s[105];
	cin>>h>>w;
	for(i=0;i<w;i++)cin>>s[i];
	for(i=0;i<h;i++){
		for(j=0,x=2*i;j<w;j++){
			if(x-1>0&&s[j][x-1]=='-')x-=2;
			else if(x+1<2*w-2&&s[j][x+1]=='-')x+=2;
		}
		if(i)printf(" ");
		printf("%d",x/2+1);
	}
	printf("\n");
}
