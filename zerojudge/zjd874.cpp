#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int ans=0,i=1;
		while(n){
			if(n>i){
				n-=(n<i*2?n:i*2);
				ans+=2;
				i++;
			}
			else{
				ans++; n=0;
			}
		}
		printf("%d\n",ans);
	}
}