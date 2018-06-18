#include <iostream>
using namespace std;
#define N 20000000
int ox[N], p[N], pr, ans[N];

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}


int main(){
	PrimeTable();
	int n, m;
	cin >> n;
	while (n--){
		cin >> m;
		cout <<p[m+1] << endl;
	}
}