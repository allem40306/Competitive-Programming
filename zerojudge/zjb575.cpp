#include <iostream>
#include <string>
using namespace std;
#define N 50
string a[N], b[N];
int n, k;

bool ta(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])return false;
	return true;
}

bool tb(){
	for (int i = 0; i < n; i++ )
		for (int j = 0,j2=n-1; j < n; j++,j2--)
			if (a[i][j] != b[j2][i])return false;
	return true;
}

bool tc(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[n-1-i][n-1-j])return false;
	return true;
}

bool td(){
	for (int i = 0,i2=n-1; i < n; i++,i2--)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[j][i2])return false;
	return true;
}

int main(){
	while (cin >> n >> k){
		for (int i = 0; i < n; i++)
				cin >> a[i];
		int ans = 0;
		for (int a = 0; a < k; a++){
			cin >> ws;
			for (int i = 0; i < n; i++)
					cin >> b[i];
			if (ta() || tb() || tc() | td())ans++;
		}
		printf("%d\n", ans);
	}
}