#include <iostream>
using namespace std;

int main(){
	int n, m, m2, c, app[25], oc[20], t, max,safe,sequence=1;
	while (cin >> n >> m >> c, n){
		t = 0, safe = 1; max = 0;
		for (int i = 0; i != n; i++){
			cin >> app[i];
			oc[i] = 1;
		}
		for (int i = 0; i != m; i++){
			cin >> m2;
			t += app[m2 - 1] * oc[m2 - 1];
			oc[m2 - 1] *= -1;
			if (t > max)max = t;
			if (t > c) safe = 0;
		}
		if(sequence>1)printf("\n");
		if (safe == 0)cout <<"Sequence "<<sequence<<"\n"<< "Fuse was blown.\n";
		else cout <<"Sequence "<<sequence<<"\n"<< "Fuse was not blown.\n" << "Maximal power consumption was " << max << " amperes.\n";
		sequence++;
	}
}

