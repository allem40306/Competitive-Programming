#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100
long long aa[N][N], bb[N][N];
long long cc[N][N];
long long a, b, c, d;

void zero(){
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	memset(cc, 0, sizeof(cc));
}

long long times(long long m, long long n){
	long long t = 0;
	for (long long i = 0; i < b; i++)
		t += aa[m][i] * bb[i][n];
	return t;
}

int main() {
	while (cin >> a >> b >> c >> d){
		if (b == c){
			zero();
			for (long long ia = 0; ia < a; ia++)
				for (long long ja = 0; ja < b; ja++)
					cin >> aa[ia][ja];
			for (long long ib = 0; ib < c; ib++)
				for (long long jb = 0; jb < d; jb++)
					cin >> bb[ib][jb];
			for (long long ic = 0; ic < a; ic++)
				for (long long jc = 0; jc < d; jc++)
					cc[ic][jc] = times(ic, jc);
			for (long long ic2 = 0; ic2 < a; ic2++){
				for (long long jc2 = 0; jc2 < d; jc2++)
					cout << cc[ic2][jc2] << ' ';
				cout << endl;
			}
		}
		else cout << "Error\n";
	}
}