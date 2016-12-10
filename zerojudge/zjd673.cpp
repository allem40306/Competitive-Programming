#include <iostream>
#define M 12
int main() {
	int i,s,m[M][2],ti=1;
	while(scanf("%d",&s)&&s>=0){
		printf("Case %d:\n",ti++);
		for(i=0;i<M;i++)scanf("%d",&m[i][0]);
		for(i=0;i<M;i++)scanf("%d",&m[i][1]);
		for(i=0;i<M;i++){
			if(s<m[i][1])printf("No problem. :(\n");
			else{printf("No problem! :D\n");s-=m[i][1];}
			s+=m[i][0];
		}
	}
}
