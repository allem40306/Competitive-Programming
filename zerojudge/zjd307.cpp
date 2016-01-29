#include <iostream>
using namespace std;
#define N 2000000
int ox[N], p[N], pr;

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
	int n;
	while (cin >> n, n){
		int x, cc = 0;
		for (x = 1; x<=n / 2; x ++)
			if (!ox[x] && !ox[n - x])cc++;
		cout << cc << endl;
	}
}
