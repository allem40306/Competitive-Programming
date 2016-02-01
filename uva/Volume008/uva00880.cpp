#include <iostream>
using namespace std;

int main() {
	unsigned a;
	while(cin>>a){
		unsigned b,c;
		for(b=0;a>b;b++)a-=(b+1);
		b+=(a>0);
		c=b+1;
		a+=(a==0)*b;
		cout<<c-a<<'/'<<a<<endl;
	}
}
