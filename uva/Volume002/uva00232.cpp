#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;
#define N 10

struct pans{
	string s;
	int n;
};
int main() {
	int r, c, ti = 1;
	while (cin >> r,r){
		cin >> c;
		int t = 1, prr = 0, pcr = 0;
		string s[N];
		pans pr[N*N], pc[N*N];
		for (int i = 0; i < r; i++)cin >> s[i];
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (!isalpha(s[i][j]))continue;
				string r1 = "", r2 = "";
				int k1 = j, k2 = i;
				if(k1==0||!isalpha(s[i][k1-1]))
				for (; k1 < c; k1++){
					if (!isalpha(s[i][k1]))break;
					r1 += s[i][k1];
				}
				if (k2==0||!isalpha(s[k2 - 1][j]))
				for (; k2 < r; k2++){
					if (!isalpha(s[k2][j]))break;
					r2 += s[k2][j];
				}
				bool used = 0;
				if (r1 != ""){ used = 1; pr[prr].n = t; pr[prr++].s = r1; }
				if (r2 != ""){ used = 1; pc[pcr].n = t; pc[pcr++].s = r2; }
				if(used)t++;
			}
		}
		if(ti>1)printf("\n");
		printf("puzzle #%d:\n", ti++);
		printf("Across\n");
		for (int i = 0; i < prr; i++){
			printf("%3d.", pr[i].n);
			cout << pr[i].s << endl;
		}
		printf("Down\n");
		for (int i = 0; i < pcr; i++){
			printf("%3d.", pc[i].n);
			cout << pc[i].s << endl;
		}
	}
}