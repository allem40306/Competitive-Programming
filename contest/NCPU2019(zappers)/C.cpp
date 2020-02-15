#include <iostream>

#define SIZE 1000000

using namespace std;

struct A {
	long long  l, r;
} ar[SIZE];

long long  x, y, rv[5];

void init(long long  n) {
	ar[1].l = -1;
	ar[1].r = 2;
	ar[n].l = n - 1;
	ar[n].r = -2;

	for(long long  i = 2; i < n; i++) {
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

void f3(long long  m) {
    if(ar[x].l>0 && ar[x].l <= m)
    ar[ar[x].l].r = y;
    if(ar[x].r>0 && ar[x].r <= m)
    ar[ar[x].r].l = y;
    if(ar[y].l>0 && ar[y].l <= m)
    ar[ar[y].l].r = x;
    if(ar[y].r>0 && ar[y].r <= m)
    ar[ar[y].r].l = x;
    swap(ar[x],ar[y]);
}

void f4() {
	long long  tmp = rv[0];
	rv[0] = rv[1];
	rv[1] = tmp;
}


void sum(int m) {
	long long ans = 0;
	if(rv[0] == -2) {
		long long i, j = 1;

		for(i = 1; i <= m; i++)
			if(ar[i].r == -2) break;

		while(j <= m) {
			if(j % 2 == 1)
				ans += i;
            if(j != m)
			i = ar[i].l;
			++j;
		}

	}


	else {
		long long i, j = 1;

		for(i = 1; i <= m; i++)
			if(ar[i].l == -1) break;

		while(j <= m) {
			if(j % 2 == 1) ans += i;
            if(j != m)
			i = ar[i].r;
			++j;
		}
	}
	cout << ans << endl;
}


int main() {
	long long  m, n;

	while(cin >> m >> n) {
		init(m);

		for(long long i = 0; i < n; i++) {
			long long  type;

			cin >> type;

			if(type == 1){
                cin >> x >> y;
                f1();
			}
			else if(type == 2){
                cin >> x >> y;
                f2();
			}
			else if(type == 3){
                cin >> x >> y;
                f3(m);
			}
			else if(type == 4) f4();

		}
		for(int i = 1 ; i  <= m ; ++i){
            cout << ar[i].l << ' ';
		}cout << endl;
		for(int i = 1 ; i  <= m ; ++i){
            cout << ar[i].r << ' ';
		}cout << endl << endl;


		sum(m);
	}

	return 0;
}
