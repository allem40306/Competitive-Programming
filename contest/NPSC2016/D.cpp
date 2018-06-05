#include <stdio.h>
#include <string.h>

int min(int a,int b)
{
	return a*(a<b) + b*(b<=a);
}

int main()
{
	char up[1000001],down[1000001];
	int t,u[3]={0,0,0},d[3]={0,0,0},ans[3]={0,0,0},i,lu,ld,tmp;
	scanf("%lld %s %s",&t,up,down),lu = strlen(up),ld=strlen(down);
	for(i=0;up[i]!='\0';i++)
	{
		if(up[i] == 'P') u[0]+=t/lu+(t%lu<i);
		else if(up[i] == 'R') u[1]+=t/lu+(t%lu<i); 
		else u[2]+=t/lu+(t%lu<i); 
	}
	for(i=0;down[i]!='\0';i++)
	{
		if(down[i] == 'P') d[0]+=t/ld+(t%ld<i);
		else if(down[i] == 'R') d[1]+=t/ld+(t%ld<i); 
		else u[2]+=t/ld+(t%ld<i); 
	}
	tmp = min(u[0],d[1]),u[0]-=tmp,d[1]-=tmp;
	ans[0]+=tmp;
	tmp = min(u[1],d[2]),u[1]-=tmp,d[2]-=tmp;
	ans[0]+=tmp;
	tmp = min(u[2],d[0]),u[2]-=tmp,d[0]-=tmp;
	ans[0]+=tmp;
	tmp = min(u[0],d[1]),u[0]-=tmp,d[1]-=tmp;
	ans[1]+=tmp;
	tmp = min(u[1],d[2]),u[1]-=tmp,d[2]-=tmp;
	ans[1]+=tmp;
	tmp = min(u[2],d[0]),u[2]-=tmp,d[0]-=tmp;
	ans[1]+=tmp;
	printf("%lld %lld %lld\n",ans[0],ans[1],t-ans[0]-ans[1]);
}
