#include <iostream>

int main(){
	freopen("01i.txt","r",stdin);
	freopen("01o.txt","w",stdout);
	int a,b,sum=1;
	scanf("%d",&a);
	printf("%d ",a);
	for(int i=0;i<a;i++){scanf("%d",&b);printf("%d ",b); sum+=b;}
	printf("%d\n",sum);
	fclose(stdin); fclose(stdout);
}
