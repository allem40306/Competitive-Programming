#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=505;
const int M=505;
vector<LL>p;
bitset<N>is_notp;
vector<int>v[M];
int n;

void PrimeTable(){
    is_notp.reset();
	is_notp[0] = is_notp[1] = 1;
	for (LL i = 2; i < N; i++){
		if (is_notp[i])continue;
		p.push_back(i);
		for (int j=0;i*p[j]<N&&j<p.size();j++){
			is_notp[i*p[j]] = 1;
			if(i%p[j]==0)break;
		}
	}
    for(int i=0;i<M;i++){
        v[i].resize(p.size());
    }
}

void init(){
    for(int i=0;i<M;i++){
        for(int j=0;j<v[i].size();j++){
            v[i][j]=0;
        }
    }
}

void debug(){
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

bool cmp(vector<bool> a,vector<bool> b){
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[i]!=b[i]){
            return a[i]>b[i];
        }
    }
    return a.size()<b.size();
}

int sol(int row, int col){
    int i = 0, j = 0;
    while(i < row && j < col){
        int r = i;
        for(int k = i; k < row; k++){
            if(v[k][j]){
                r = k;
                break;
            }
        }
        if(v[r][j]){
            if(r != i){
                for(int k = 0; k <= col; k++)swap(v[r][k], v[i][k]);
                
            }
            for(int k = i + 1; k < row; k++){
                if(v[k][j]){
                    for(int kk = i; kk <= col; kk++)v[k][kk] ^= v[i][kk];
                }
            }
            i++;
        }
        j++;
        // debug();
    }
    return i;
}

int main(){
    PrimeTable();
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        init();
        LL x;
        int mx = 0;
        for(int i=0;i<n;i++){
            cin>>x;
            for(int j=0;j<p.size();j++){
                while(x%p[j]==0){
                    v[j][i]^=1;
                    mx = max(mx, j);
                    x/=p[j];
                }
            }
        }
        int ans=sol(mx + 1, n);
        cout<<((1LL<<(n-ans))-1)<<'\n' ;
    }
}