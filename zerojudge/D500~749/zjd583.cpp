#include <iostream>
#include <algorithm>

int main(){
	int n,i,a[100005];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		std::sort(a,a+n);
		for(i=0;i<n;i++){if(i)printf(" ");printf("%d",a[i]);}
		printf("\n");
	}
}
