#include <cstdio>
#include <algorithm>
#define N 100005
static int a[N],b[N],n,tr;

struct tree{
	int p,v; //pass value
	bool e;
};

static tree t[2*N];

int bulid(int L,int R,int x){
	if(L==R){
		t[x].e=1; t[x].p=0; t[x].v=b[tr++];
		return t[x].v;
	}
	t[x].e=0; t[x].p=0;
	int M=(L+R)/2;
	t[x].v=bulid(L,M,(x<<1));
	int v2=bulid(M+1,R,(x<<1)+1);
	if(v2>t[x].v)t[x].v=v2;
	return t[x].v;
}

int f(int x,int c,int o){
	if(t[x].e==1)return o;
	if(c<=t[(x<<1)].v){
		o+=t[(x<<1)+1].p;
		o+=t[(x<<1)].p++;
		return f((x<<1),c,o);
	}else{
        t[(x<<1)+1].p++;
		return f((x<<1)+1,c,o);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		std::sort(b,b+n);
		tr=0;
		bulid(1,n,1);
		for(int i=1;i<=16;i++)
		for(int i=0;i<n;i++)
		printf("%d\n",f(1,a[i],1));
	}
} 
