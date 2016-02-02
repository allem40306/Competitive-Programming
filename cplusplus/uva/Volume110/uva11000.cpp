#include <iostream>
using namespace std;
#define N 10000000
long long girl[N] = { 1 }, boy[N] = { 0 };

void dp(){
	for (int i = 1; i < N; i++){
		girl[i] = boy[i - 1] + 1;
		boy[i] = boy[i - 1] + girl[i - 1];
	}
}

int main(){
	dp();
	int n;
	while (cin >> n, n != -1)
		cout << boy[n] << ' ' << girl[n] + boy[n] << endl;
}