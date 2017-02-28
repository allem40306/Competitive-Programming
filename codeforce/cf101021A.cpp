#include <iostream>
#include <string>
using namespace std;

int main(){
	int a=1,b=1000000,m=(a+b)/2;
	string s;
	printf( "%d\n",m+1);
	fflush( stdout );
	cin>>s;
	do{
		if(s==">=")a=m+1;
		else b=m;
		if(a==b){
			printf( "! %d\n",a);
			fflush( stdout );
			break;
		}m=(a+b)/2;
		printf( "%d\n",m+1);
		fflush( stdout );
	}while(cin>>s);
}
