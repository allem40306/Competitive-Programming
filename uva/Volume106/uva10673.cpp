#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int x,k;
		cin>>x>>k;
		int a=(x/k),b=(x/k)+(x%k>0);
		for(int p=0;p<=x;p++){
			if((x-a*p)%b==0){
				printf("%d %d\n",p,(x-a*p)/b);
				break;
			}
		}
	}
}
