#include <iostream> 
#include <algorithm>
#define N 10005

int main(){
	unsigned long long n,i;
	bool b=1;
	scanf("%d",&n);
	for(i=1;b;i++){
		if((1+i)*i/2>=n){
			std::cout<<i<<std::endl;
			b=0;
		}
	}
}
