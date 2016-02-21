#include <iostream>
#include <iomanip>
using namespace std;
int t, a[3];

int main(){
	int c;
	cin >> c;
	while (c--){
		int n, p[1005], t = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i];
			t += p[i];
		}
		float ans = 0;
		for (int i = 0; i < n; i++){
			ans += (p[i]>(t / n));
		}
		cout<<fixed<<setprecision(3)<<ans*100 / n<<"%\n";
	}
}