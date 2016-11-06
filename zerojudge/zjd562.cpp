#include <cstdio>
#define N 100

int main(){ 
	int n,a[N];
	while(scanf("%d",&n)!=EOF){
		int i=0,j=n-1;
		for(int k=0;k<n;k++)scanf("%d",&a[k]);
		for(int k=0;k<n;k++){
			if(k%2)
				for(int p=j;p>=i;p--)
					if(j==p)printf("%d",a[p]);
					else printf(" %d",a[p]);
			else
				for(int p=i;p<=j;p++)
					if(i==p)printf("%d",a[p]);
					else printf(" %d",a[p]);
			if(k%2)j--;
			else i++;
			printf("\n");
		}
		printf("\n");
	}
}
