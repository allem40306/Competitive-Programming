#include <iostream>
#include <algorithm>
using namespace std;

struct student{
	int n, c, m, e,t;
}s[1000];

bool comp(student a, student b){
	if (a.t != b.t)return a.t > b.t;
	if (a.c != b.c)return a.c > b.c;
	return a.n < b.n;
}
int main(){
	int p;
	while (cin >> p){
			for (int i = 0; i < p; i++){
				cin >> s[i].c >> s[i].m >> s[i].e;
				s[i].n = i + 1;
				s[i].t = s[i].c + s[i].m + s[i].e;
			}
			sort(s, s + p, comp);
			for (int i = 0; i < 5; i++){
				cout << s[i].n << " " << s[i].t << endl;
		}
	}
}