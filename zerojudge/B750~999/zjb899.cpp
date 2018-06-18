#include <iostream>
using namespace std;
#define aa (j+2)%3
#define bb (j+1)%3
int main(){
	int a[3][2],j;
	for(int i=0;i<3;i++)
		cin>>a[i][0]>>a[i][1];
	for(j=0;j<3;j++)
		if((a[j][0]-a[aa][0])*(a[j][0]-a[bb][0])+(a[j][1]-a[aa][1])*(a[j][1]-a[bb][1])==0)
			printf("%d %d\n",a[bb][0]+a[aa][0]-a[j][0],a[bb][1]+a[aa][1]-a[j][1]);
}
