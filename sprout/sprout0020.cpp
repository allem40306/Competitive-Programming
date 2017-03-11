#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 1005
#define M 1000005
struct Node{
    int i;
    queue<int>q;
};
int n,ni,k,ki,ti=1,x,num[M],g[N],vr,vqr;
vector<Node> vq;
string s;
void init(){
	vr=-1,vqr=0;
	vq.clear();
	memset(num,0,sizeof(num));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	Node kk;
	while(cin>>n){
		init();
		cout<<"Line #"<<ti++<<endl;
		for(ni=1;ni<=n;ni++){
			cin>>k,g[ni]=-1;
			for(ki=0;ki<k;ki++){
				cin>>x;
				num[x]=ni;
			}
		}
		while(cin>>s){
			if(s[0]=='E'){
				cin>>x;
//				cout<<num[x]<<' '<<g[num[x]]<<endl;
				if(!num[x]||g[num[x]]<0){
					vr++;
					vq.push_back(kk);
					vq[vr].q.push(x);
					g[num[x]]=vr;
				}else{
					vq[g[num[x]]].q.push(x);
				}
//				cout<<x<<' '<<g[num[x]]<<endl;
			}else if(s[0]=='D'){
				cout<<(x=vq[vqr].q.front())<<endl; 
				vq[vqr].q.pop();
				if(vq[vqr].q.empty()){
					g[num[x]]=-1;
					vqr++;
				}
			}else break;
		}
	}
}
