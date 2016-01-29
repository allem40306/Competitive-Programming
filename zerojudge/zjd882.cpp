#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int maxlen = 3;

class Bigint{
	unsigned long long d[maxlen];
public:
	Bigint(int n = 0){
		this->d[0] = n;
		for (int i = 1; i < maxlen; i++)
			this->d[i] = 0;
	}
	bool operator <(Bigint b){
		int i;
		for (i = maxlen - 1; i&&this->d[i] == b.d[i]; i--);
			return this->d[i] < b.d[i];
	}
	Bigint operator +(Bigint b){
		Bigint sum;
		int c = 0;
		for (int i = 0; i < maxlen; i++){
			sum.d[i] = this->d[i] + b.d[i] + c;
			c = int(sum.d[i] / 1000000000000000000ULL);
			sum.d[i] %= 1000000000000000000ULL;
		}
		return sum;
	}
	friend ostream& operator << (ostream &, Bigint &);
};

ostream & operator << (ostream &out, Bigint &n){
	int i;
	for (i = maxlen - 1; i&& !n.d[i]; i--);
	out << n.d[i];
	out << setfill('0');
	for (i--; i >= 0; i--)
		out << setw(18) << n.d[i];
	return out;
}

int main(){
	int n, i, j;
	Bigint m, mn, m1[10001], m2;
	for (int i = 1; i <= 10000; i++){
		mn = m1[i - 1], m2 = 1;
		for (j = 1; j < i; j++){
			m = m1[i - 1 - j] + m2;
			if (mn < m)
				break;
			mn = m;
			m2 = m2 + m2 + 1;
		}
		m1[i] = mn + mn + 1;
	}
	while (cin >> n)
		cout << m1[n] << endl;
}
