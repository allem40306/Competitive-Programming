#include <cstdio>
#define x5 x*x*x*x*x
#define x4 x*x*x*x
#define x3 x*x*x
#define x2 x*x
 
int main(){
	int a,b,c,d,e,f,x,arr[150];
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(!a&&!b&&!c&&!d&&!e&&!f)printf("Too many... = =\"");
	else{
		bool b=0;
		for(x=-73;x<=73;x++)
			if((a*x5+b*x4+c*x3+d*x2+e*x+f)<0)arr[x+73]=-1;
			else if((a*x5+b*x4+c*x3+d*x2+e*x+f)>0)arr[x+73]=1;
			else arr[x+73]=0;
		for(x=-73;x<73;x++)
			if(arr[x+73]==0&&(b=1))printf("%d %d\n",x,x);
			else if(arr[x+73]*arr[x+74]==-1&&(b=1))printf("%d %d\n",x,x+1);
			if(!b)printf("N0THING! >\\\\\\<");
	}
}
