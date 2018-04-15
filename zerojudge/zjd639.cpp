#include <iostream>
using namespace std;
#define M 10007
#define Max(x,y) x>y?x:y
#define N 3

struct dev{
    int a[N][N];
};


void ooo(dev a){
	for(int i=0;i<N;i++)
		printf("%d %d %d\n",a.a[i][0],a.a[i][1],a.a[i][2]);
}

dev mm(dev a, dev b){
	dev c;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){ 
			c.a[i][j]=0;
			for(int k=0;k<N;k++){
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
				c.a[i][j]%=M;	
			}
		} 
	return c;
}

int main(){
    int n;
    while(cin>>n){
        dev x={0,1,0,0,0,1,1,1,1},y={0,1,0,0,0,1,1,1,1};
        if(n<4)printf("%d\n",1);
        else{
        	n-=2;
	       	while(n){
	       	if(n&1)x=mm(x,y);
	       	y=mm(y,y);
	       	n>>=1;	
			}
		printf("%d\n",(x.a[0][0]+x.a[0][1]+x.a[0][2])%M);
		}
    }
}