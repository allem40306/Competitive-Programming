#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double fo, fe, fa, m, ft;
	while (cin >> fo >> fe >> fa){
		if (!fo&&!fe&!fa)break;
		m = fo / fe;
		ft = fa / m;
		printf("%.2lf %.2lf\n", m, ft);
	}
}