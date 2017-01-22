#include <iostream>

int main(){
	long long int n,ni=0,a,b,t;
	for(std::cin>>n;ni<n;ni++){
		std::cin>>a>>b;
		if(a<b)t=a,a=b,b=t;
		while(t=a%b)a=b,b=t;
		if(b==1)printf("Nao\n");
		else printf("Sim\n");
	}
} 
