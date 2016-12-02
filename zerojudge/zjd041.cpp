#include <iostream>

int main(){
	int ni=1,n,age,y1,m1,d1,y2,m2,d2;
	for(scanf("%d",&n);ni<=n;ni++){
		scanf("%d/%d/%d%d/%d/%d",&d1,&m1,&y1,&d2,&m2,&y2);
		age=y1-y2-(m2*60+d2>m1*60+d1);
		printf("Case #%d: ",ni);
		age<0?printf("Invalid birth date\n"):age<131?printf("%d\n",age):printf("Check birth date\n");
	}
}
