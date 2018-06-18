#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int t, ti = 0;
	string s;
	for (cin >> t >> ws; ti < t; ti++) {
		getline(cin, s); stringstream ss(s);
		int ot = 0, oc = 0, nt = 0, nc = 0;
		while (ss >> s) {
			if (s[0] == 'c')nc++;
			else nt++;
			if (nc < nt&&!ot)ot++;
		}
		if (nc > nt&&!oc)oc++;
		if (oc&&ot)printf("chi pu tao bu tu pu tao pi, bu chi pu tao dao tu pu tao pi\n");
		else if (oc)printf("chi pu tao bu tu pu tao pi\n");
		else if (ot)printf("bu chi pu tao dao tu pu tao pi\n");
		else printf("chi pu tao tu pu tao pi\n");
	}
}