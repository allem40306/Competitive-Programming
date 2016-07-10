#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define N 6000
#define maxlen 200

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
	Bigint operator =(Bigint b){
		for (int i = 0; i < maxlen; i++){
			d[i] = b.d[i];
		}
		return *this;
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

Bigint dp[N] = { 0, 1, 1 };

void ddp(){
	for (int i = 3; i < N; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main(){
	ddp();
	int n;
	while (cin >> n){
		printf("The Fibonacci number for %d is ", n);
		cout << dp[n] << endl;
	}
}