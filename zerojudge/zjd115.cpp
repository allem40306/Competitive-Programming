#include <iostream>
#include <algorithm>
using namespace std;

int n[100], k, i[101] = { -1 },m;

void comb(int p){
	if (p > m){
		for (int j = 1; j <= m; j++){
			cout << n[i[j]] << " ";
		}
		cout << endl;
	}
	else 
	for (i[p] = i[p - 1] + 1; i[p] < k - m + p; i[p]++)
		comb(p + 1);
}

int main(){
	int  j;
		while (cin>>k,k){
			for (j = 0; j < k; j++)
				cin >> n[j];
			sort(n, n + k);
			cin >> m; 
			comb(1);
	}
}