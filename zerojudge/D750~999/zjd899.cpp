#include <iostream>
using namespace std;
#define N 10005
int ma[N] = {}; 

void bulit(){
	int a = 1;
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < N; j++)
			if ((j / a) % 10 == 2)ma[j]++;
		a *= 10;
	}
	for (int k = 1; k < N; k++)
		ma[k] += ma[k - 1];
	return;
}

int main() {
	bulit();
	int n,m;
	while (cin >> n>>m){
		cout << ma[m] - ma[n - 1] << endl;
	}
}