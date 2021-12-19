#include <iostream>
#include <cstring>

#define SIZE 25

using namespace std;

long long arr[SIZE][SIZE][SIZE];



void dp() {
	memset(arr, 0, sizeof(arr));
	
	arr[0][0][0] = 1;
	arr[0][0][1] = 1;
	arr[1][0][1] = 1;
	arr[1][1][1] = 1;
	


	for(int k = 2; k < 21; k++) {
		for(int i = 0; i < 21; i++) {
			for(int j = 0; j < 21; j++)	{
				if(i >= 1) arr[i][j][k] += arr[i-1][j][k-1];
				if(i >= 1 && j >= 1) arr[i][j][k] += arr[i-1][j-1][k-1];
				arr[i][j][k] += arr[i][j][k-1];
			}	
		}
	}
}

int main() {
	dp();

	int n;
	while(cin >> n) {
		for(int i = 0; i <= n; i++) {
			cout << arr[i][0][n];
			for(int j = 1; j <= n; j++) {
				if(arr[i][j][n] == 0) break;
				cout << " " << arr[i][j][n];
			}	
			cout << endl;
		}	
	}
	return 0;
}
