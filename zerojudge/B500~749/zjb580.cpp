#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 105
int n, arr[N][N], t;

void ccw(){
	int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };
	int x = n-1, y = n-1, d = 0, t = n*n;
	while (t){
		arr[x][y] = t;
		if ((arr[x + dx[d]][y + dy[d]]) || !(x + dx[d] >= 0 && x + dx[d] < n &&y + dy[d] >= 0 && y + dy[d] < n))d = (d + 1) % 4;
		x += dx[d]; y += dy[d];
		t--;
	}
	return;
}

void init(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = 0;
	return;
}

int main(){
	cin >> t;
	while (t--){
		init();
		cin >> n;
		ccw();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (j)printf(" ");
				printf("%4d", arr[i][j]);
			}	
			printf("\n");
		}
	}
}