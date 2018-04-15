#include <iostream>
using namespace std;
int main(){
	unsigned long long int n;
	while (cin >> n){
		if (n%4==0)cout<<(n/4)*(n/4)<<endl;
		else cout << (n/4+1)*(n/4)<<endl;
	}
}