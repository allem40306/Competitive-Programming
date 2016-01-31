#include <iostream>
using namespace std;

int main() {
	int n;
	while(cin>>n,n>0){
		if(n==1)printf("0%\n");
		else printf("%.0lf%%\n",(double)n*25.0);
	}
}
