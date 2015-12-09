#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000005
int ox[N], p[N], pr, dp[N];

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

void DigitPrime(){
	for (int i = 0; i < N; i++){
		int i1 = i, dpp = 0;
		while (i1){
			dpp += i1 % 10;
			i1 /= 10;
		}
		dp[i] = ox[dpp];
	}
}

int main(){
	PrimeTable();
	DigitPrime();
	int n;
	cin >> n;
	while (n--){
		int t1, t2;
		cin >> t1 >> t2;
		int count = 0;
		for (int i = t1; i <= t2; i++){
			if (!ox[i] && !dp[i])count++;
		}
		cout << count << endl;
	}
}