#include <iostream>
using namespace std;
#define N 3000
bool a[N][N], b[N][N], c[N][N],s;
int n,i,j;

int sum(int x, int y){
	s = 0;
	for (int i = 0; i < n; i++)
		if (a[x][i] & b[i][y])s = !s;
	return s;
}

void ans(){
	for (int i = 0;i < n; i++)
		for (int j = 0;j < n; j++)
			if (sum(i, j) % 2 != c[i][j]&&(printf("NO\n")))return;
		printf("YES\n");
		return;
}

int main(){
	while (cin >> n){
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> a[i][j];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> b[i][j];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> c[i][j];		
		ans();
	}
}

