#include <iostream>
using namespace std;
#define N 5
#define M 500
int w[N][N] = { 0, -1, 1, 1, -1, 1, 0, -1, 1, -1, -1, 1, 0, -1, 1, -1, -1, 1, 0, 1, 1, 1, -1, -1, 0 };

int main() {
	int n, na, nb, ti=0;
	while (cin >> n >> na >> nb){
		int a[M], b[M], pa = 0, pb = 0;
		for (int i = 0; i < na; i++)cin >> a[i];
		for (int i = 0; i < nb; i++)cin >> b[i];
		for (int i = 0; i < n; i++){
			pa += (w[a[i%na]][b[i%nb]] == 1);
			pb += (w[a[i%na]][b[i%nb]] == -1);
		}
		if (ti++)printf("\n");
		printf("%d %d\n", pa, pb);
	}
}