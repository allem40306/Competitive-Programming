#include <iostream>
using namespace std;
#define gor(a,b,c) for(a=b;a<c;a++)
//Josephus Problem

int main() {
	int n,m,off,i;
	while(cin>>n,n){
		n--;
		gor(m,1,n){
			off=0;
			gor(i,1,n+1)
			off=(off+m)%i;
			if(off==11)break;
		}
		printf("%d\n",m);
	}
}
