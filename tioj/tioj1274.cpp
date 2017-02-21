#include <stdio.h>
#define o(n) (n<3?n+2:n+11) 
int main(){
	short n;
	scanf("%d",&n);
	printf("%d\n",o(n));
}
