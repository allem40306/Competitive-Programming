#include <iostream>
using namespace std;

int main() {
	int a,b;
	while(cin>>a>>b){
		printf("[%d;",a/b);
		a%=b;
		bool flag=false;
		while(a>0){
			swap(a,b);
			if(flag)printf(",");
			flag=true;
			printf("%d",a/b);
			a%=b;
		}
		printf("]\n");
	}
}
