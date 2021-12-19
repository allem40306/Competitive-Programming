#include <iostream>
using namespace std;
#define N 2000010
#define LC(x) (x<<1)
#define RC(x) (x<<1)+1
int tmp,heap[N],r=0,cmp;
void ph(int a){
	heap[++r]=a;
	cmp=r;
	while(cmp/2&&heap[cmp]<heap[cmp/2])
		swap(heap[cmp],heap[cmp/2]),cmp/=2;
	return;
}
void pp(){
	if(!r){
		cout<<"empty!\n";
		return;
	}
	cout<<heap[1]<<'\n';
	heap[1]=heap[r--];
	cmp=1;
	while(r>=LC(cmp)){
		if(r<RC(cmp)){
			if(heap[cmp]>heap[LC(cmp)])
				swap(heap[cmp],heap[LC(cmp)]);
			return;
		}else{
			if(heap[LC(cmp)]<=heap[RC(cmp)]){
				if(heap[cmp]<heap[LC(cmp)])return;
				swap(heap[cmp],heap[LC(cmp)]);
				cmp=LC(cmp);
			}else{
				if(heap[cmp]<heap[RC(cmp)])return;
				swap(heap[cmp],heap[RC(cmp)]);
				cmp=RC(cmp);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t,i=0,x,y;
	for(cin>>t;i<t;i++){
		cin>>x;
		if(x%2){
			cin>>y;
			ph(y);
		}else{
			pp();
		}
	}
}
