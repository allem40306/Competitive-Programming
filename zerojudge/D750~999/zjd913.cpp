#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
	
int a[6] = { 1, 2, 3, 4, 5, 6 };

struct deploy{
	int x1, x2, x3, x4, x5, x6, y;
}d[6];

int count(deploy b){
	int c = 0;
	if (a[0] == b.x1)c++;
	if (a[1] == b.x2)c++;
	if (a[2] == b.x3)c++;
	if (a[3] == b.x4)c++;
	if (a[4] == b.x5)c++;
	if (a[5] == b.x6)c++;
	return c;
}

int main(){
	int c;
	while (cin >> d[0].x1 >> d[0].x2 >> d[0].x3 >> d[0].x4 >> d[0].x5 >> d[0].x6 >> d[0].y){
		for (int i = 1; i < 6; i++)
			cin >> d[i].x1 >> d[i].x2 >> d[i].x3 >> d[i].x4 >> d[i].x5 >> d[i].x6 >> d[i].y;
		do{
			c = 0;
			for (int i = 0; i < 6; i++)
				if (count(d[i]) == d[i].y)c++;
			if (c == 6)cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << "\n";
		} while (next_permutation(a,a+6));
	}
}