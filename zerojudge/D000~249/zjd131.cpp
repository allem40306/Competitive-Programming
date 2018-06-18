#include <iostream>
#include <iomanip>
using namespace std;
#define N 105
#define MIN(x,y) x<y?x:y
int ma[N][N], ox[N], p[N], pr;

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

int bulid(){
	PrimeTable();
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < N; j++)
			ma[i][j] = 0;
	for (int i = 1; i <= 100; i++){
		int a = i;
		pr = 0;
		while (a > 1 && p[pr] <= a){
			while (a%p[pr] == 0){
				ma[i][pr]++;
				a /= p[pr];
			}
			pr++;
		}
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j < 25; j++)
			ma[i][j] += ma[i - 1][j];
	return 0;
}

int main(){
	bulid();
	int n;
	while (cin >> n, n){
		cout << setw(3) << n << "! =";
		int r = 0;
		while (ma[n][r]){
			if (r == 15)printf("\n      ");
			cout << setw(3) << ma[n][r];
			r++;
		}
		printf("\n");
	}
}