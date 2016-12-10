#include <iostream>
using namespace std;
#define N 20 

int main(){
	int i = 0, t, m, n;
	for (cin >> t; i < t; i++){
		int arr[N][N];
		cin >> n >> m;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				cin >> arr[j][k];
		bool same = 1;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (arr[j][k] != arr[n - 1 - j][m - 1 - k])
					same = 0;
		printf("%s\n",same? "go forward": "keep defending");
	}
}
