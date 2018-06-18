#include <iostream>
#include <string>
std::string s="UGYTI";

int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
		std::cout<<s[n%5]<<std::endl;
}
