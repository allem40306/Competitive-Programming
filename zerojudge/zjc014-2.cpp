#include <iostream>

int main(){
	int a,b,o,c;
	while(scanf("%d %d",&a,&b),a||b){
		c=o=0;
		while(a||b){
			c=(a%10+b%10+c)/10;
			if(c)o++;
			a/=10;b/=10;
		}
		if(!o)printf("No carry operation.\n");
		else if(o==1)printf("1 carry operation.\n");
		else printf("%d carry operations.\n",o);
	}
}
