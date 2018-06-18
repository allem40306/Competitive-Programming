#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 10
int pr;

struct arr{
	int  n, i;
	string s;
}a[N];

void init(){
	for (int i = 0; i < N; i++)
		a[i].i = i;
}

bool cmp(arr a,arr b){
	if (a.n != b.n)
		return a.n > b.n;
	return a.i < b.i;
}

int main(){
	int n, ni =1 ;
	for (cin >> n; ni <= n; ni++){
		init();
		for (int i = 0; i < N; i++)
			cin >> a[i].s >> a[i].n;
		sort(a, a + N, cmp);
		printf("Case #%d:\n", ni);
		for (int i = 0; i < N && a[i].n == a[0].n; i++)
			cout << a[i].s << endl;
	}
}