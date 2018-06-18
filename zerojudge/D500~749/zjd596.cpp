#include <iostream>
using namespace std;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool nn[3][3];

void tag(int x, int y, int v){
	if (!v)nn[x][y] = 0;
	for (int i = 0; i < 4; i++){
		int a = x + dx[i], b = y + dy[i];
		if (a >= 0 && a < 3 && b >= 0 && b < 3)
			nn[a][b] = v;
	}
	return;
}

int main() {
	int n, a, b, c;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> a >> b >> c;
			for (int na = 0; na < 3; na++)
				for (int nb = 0; nb < 3; nb++)
					nn[na][nb] = 0;
			tag((a - 1) / 3, (a + 2) % 3, 1);
			tag((b - 1) / 3, (b + 2) % 3, 0);
			tag((c - 1) / 3, (c + 2) % 3, 0);
			int nans = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (nn[i][j]){
				if (nans++)printf(" ");
				printf("%d", i * 3 + j + 1);
					}
			if (!nans)printf("Empty");
			printf("\n");
		}
	}
}