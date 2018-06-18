#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=30005;
int main(){
	int n, r, x,idx[N];
	vector<int> a;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> r;
			int m;
			unsigned long long ans = 0;
			memset(idx,0,sizeof(idx));
			for (int j = 0; j < r; j++){
				cin >> x;
                idx[x]++;
			}
			a.clear();
			for(int i=0;i<N;i++){
                while(idx[i]){
                    a.push_back(i);
                    idx[i]--;
                }
			}
			m = a[(r-1) / 2];
			for (int k = 0; k < r; k++)
				ans += abs(a[k] - m);
			cout<< ans << ' ' << m << '\n';
		}
	}
}
