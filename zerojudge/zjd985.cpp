#include<iostream> 
using namespace std;

int main(){
	int a,b,m,n,t,mx,sum;
	while (cin >> n){
		for ( int i = 1; i<=n ; i++){
			cin >> m; sum = 0; mx = 36000;
			for (int j = 0; j < m; j++){
				cin >> a >> b;
				t = a * 60 + b;
				if (t<mx)mx = t;
				sum += t;
			}
			sum /= m;
			cout << "Track " << i << ":\n";
			cout << "Best Lap: " << mx / 60 << " minute(s) " << mx % 60 << " second(s).\n";
			cout << "Average: " << sum/60 << " minute(s) "<< sum%60 << " second(s).\n";
		}
		cout << endl;
	}
}