#include <iostream>

#define SIZE 100000

using namespace std;

struct A {
	int l, r;
} ar[SIZE];

int x, y, rv[2];

void init(int n) {
	ar[1].l = -1;
	ar[1].r = 1;
	ar[n].l = n - 1;
	ar[n].r = -2;

	for(int i = 1; i < n - 1; i++) {
		ar[i].l = i - 1;
		ar[i].r = i + 1;
	}

	rv[0] = -1;
	rv[1] = -2;
}

void f1() {
	ar[ar[x].l].r = ar[x].r;
	ar[ar[x].r].l = ar[x].l;

	ar[x].r = y;
	ar[x].l = ar[y].l;
	ar[y].l = x;
	ar[ar[x].l].r = x;
}

void f2() {
	ar[ar[x].l].r = ar[x].r;
	ar[ar[x].r].l = ar[x].l;
	ar[x].l = y;
	ar[x].r = ar[y].r;
	ar[y].r = x;
	ar[ar[x].r].l = x;
}

void f3() {
	int tmp = ar[x].l;
	ar[x].l = ar[y].l;
	ar[y].l = tmp;

	tmp = ar[x].r;
	ar[x].r = ar[y].l;
	ar[y].r = tmp;
}

void f4() {
	int tmp = rv[0];
	rv[0] = rv[1];
	rv[1] = tmp;
}


void sum(int m) {
	int ans = 0;
	if(rv[0] == -1) {
		int i, j = 1;

		for(i = 0; i < m; i++) 
			if(ar[i].r == -1) break;
		
		while(j <= m) {
			cout << i  << ' ';
			if(j & 1) {
				ans += i;
			}

			i = ar[i].r;
			++j;
		}
			
	}


	else {
		int i, j = 1;
		int ans = 0;
		
		for(i = 0; i < m; i++)
			if(ar[i].r == -2) break;
		
		while(j <= m) {
			cout << i <<' ';
			if(j & 1) ans += i;
			i = ar[i].l;
			++j;
		}
	}
	cout << ans << endl;
}


int main() {
	int m, n;	

	while(cin >> m >> n) {
		init(m);

		for(int i = 0; i < n; i++) {
			int type;
			
			cin >> type >> x >> y;

			if(type == 1) f1();
			else if(type == 2) f2();
			else if(type == 3) f3();
			else if(type == 4) f4();
		}

		sum(m);
	}	

	return 0;
}
