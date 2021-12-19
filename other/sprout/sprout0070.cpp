#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
	long long n, x;
	while (cin >> n, n){
		priority_queue <long long, vector <long long>, greater<long long> >q;
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
