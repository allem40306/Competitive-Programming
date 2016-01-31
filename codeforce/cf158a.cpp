#include <iostream>
using namespace std;
#define gor(a,b,c) for(a=b;a<c;a++)
#define N 100

int main() {
	int k,n;
	while(cin>>k>>n){
		int pass=0,i,nn[N];
		gor(i,0,k)
			cin>>nn[i];
		gor(i,0,k)	
		pass+=(nn[i]&&nn[i]>=nn[n-1]);
		printf("%d\n",pass);
	}
}
