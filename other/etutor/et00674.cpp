#include <iostream>
using namespace std;

int main(){
	unsigned long long int a[10],ans;
	while(cin>>a[0]){
		for(int i=1;i<6;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=0;i<6;i++){
			ans+=a[i]*a[i]*a[i];
		}
		cout<<ans<<'\n';
	}
}
