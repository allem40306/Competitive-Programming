#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
	
	int n, x;
	while (cin >> n, n){
		priority_queue <int, vector <int>, greater<int>>q;
			while (n--)
				cin >> x, q.push(x);
		long long e = 0;
		while (q.size() > 1){
			x = q.top(), q.pop();
			x += q.top(), q.pop();
			q.push(x);
			e += x;
		}
		cout << e << endl;
	}
}

