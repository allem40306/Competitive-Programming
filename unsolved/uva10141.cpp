#include <iostream>  
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 100000

struct rreepp{
	string name;
	float price;
	int meet, o;
};

bool cmp(rreepp a, rreepp b){
	if (a.meet != b.meet)
		return a.meet > b.meet;
	if (a.price != b.price)
		return a.price < b.price;
	return a.o < b.o;
}

int main(){
	int n, p, r, ti = 1;
	while (cin >> n >> p){
		string s;
		set<string>se;
		rreepp re[N];
		for (int i = 0; i < n; i++){
			getline(cin, s);
			se.insert(s);
		}
		for (int i = 0; i < p; i++){
			re[i].meet = 0;
			re[i].o = i;
			getline(cin, re[i].name);
			cin >> re[i].price >> r;
			for (int j = 0; j < r; r++){
				cin >> s;
				if (se.count(s))re[i].meet++;
			}
		}
		sort(r, r + n, cmp);
		printf("RFP #%d\n", ti++);
		cout << re[0].name << endl;
	}
}