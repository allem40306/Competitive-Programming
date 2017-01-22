#include <iostream>

int main(){
	int n,ni=0,a,b,w=0,l=0;
	for(scanf("%d",&n);ni<n;ni++){
		scanf("%d %d",&a,&b);
		if(a<b)l++;
		else if(a>b)w++;
	}
	if(w>l)printf("Mishka\n");
	else if(w<l)printf("Chris\n");
	else printf("Friendship is magic!^^\n");
}
