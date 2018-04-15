#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct person {
	int c, e;
} p[1000];

bool operator< (person a, person b) {
	return a.e > b.e;
}

int main() {
	int n, i,max,sum;
	while (cin >> n) {
		max = 0,sum=0;
		for (i = 0; i != n; i++)
			cin >> p[i].c >> p[i].e;
		sort(p, p + n);
		for (i = 0; i != n; i++){
			sum += p[i].c;
			if (max < sum + p[i].e)max = sum + p[i].e;
		}
		cout << max << "\n"<<endl;
	}
}