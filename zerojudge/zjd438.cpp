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


bool isDigitPrime(int in){
	int sum = 0;
	while (in){
		sum += in % 10;
		in = in / 10;
	}
	if (!ox[sum])
		return true;
	return false;
}

int dpCum[N] = {};

void DigitPrime(){
	for (int i = 2; i < N; i++){
		if (ox[i] == 0 && isDigitPrime(i))
			dpCum[i] = dpCum[i - 1] + 1;
		else
			dpCum[i] = dpCum[i - 1];
	}
}

int main(){
	PrimeTable();
	DigitPrime();
	int n, t1, t2;
	cin >> n;
	while (n--){
		cin >> t1 >> t2;
		int count = 0;
		cout << dpCum[t2] - dpCum[t1 - 1] << endl;
	}
}