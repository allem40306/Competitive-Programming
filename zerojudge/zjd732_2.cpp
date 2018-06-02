#include <iostream>
using namespace std;
#define N 100005
int a[N];

int bs(int q, int L, int R){//binary search
	int M;
	while(L<=R){
        M= (L + R) / 2;
        if(a[M]<q){
            L=M+1;
        }else if(a[M]>q){
            R=M-1;
        }else {
            return M;
        }
	}
	return 0;
}

int main(){
	int n, m, q;
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        cin >> q;
        cout<<bs(q,1,n)<<'\n';
    }
}
