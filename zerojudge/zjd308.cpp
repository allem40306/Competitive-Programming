#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define N 6000
#define maxlen 200
#define M 10
#define mod 10000000000ULL
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
	bool operator >(Bigint b){
		int i;
		for (i = maxlen - 1; i&&this->d[i] == b.d[i]; i--);
		return this->d[i] > b.d[i];
	}
	bool operator ==(Bigint b){
		int i;
		for (i = maxlen - 1; i&&this->d[i] == b.d[i]; i--);
		return this->d[i] == b.d[i];
	}
	Bigint operator +(Bigint b){
		Bigint sum;
		int c = 0;
		for (int i = 0; i < maxlen; i++){
			sum.d[i] = this->d[i] + b.d[i] + c;
			c = int(sum.d[i] / mod);
			sum.d[i] %= mod;
		}
		return sum;
	}
	Bigint operator -(Bigint b){
		Bigint sum;
		for (int i = 0; i < maxlen; i++){
			sum.d[i] = this->d[i] - b.d[i];
			if (sum.d[i] < 0){
				this->d[i]--;
				sum.d[i] += mod;
			}
		}
		return sum;
	}
	Bigint operator *(Bigint b){
		Bigint sum;
		for (int i = 0; i < maxlen; i++){
			for (int j = 0; j < maxlen; j++){
				sum.d[i + j] += this->d[i] * b.d[j];
			}
		}
		for (int i = 0; i < maxlen - 1; i++){
			sum.d[i + 1] += sum.d[i] / mod;
			sum.d[i] %= mod;
		}
		return sum;
	}
	Bigint operator *(int b){
		Bigint sum;
		for (int i = 0; i < maxlen; i++)
			sum.d[i] = this->d[i] * b;
		for (int i = 0; i < maxlen - 1; i++){
			sum.d[i + 1] += sum.d[i] / mod;
			sum.d[i] %= mod;
		}
		return sum;
	}
	int spe(Bigint x){
		int sum = 0;unsigned long long y;
		for (int i = 0; i < maxlen; i++){
			y = x.d[i];
			while (y){ sum += y % 10; y /= 10; }
		}
		return sum;
	}
	friend ostream& operator << (ostream &, Bigint &);
	friend istream & operator >> (istream &in, Bigint &n);
};

ostream & operator << (ostream &out, Bigint &n){
	int i;
	for (i = maxlen - 1; i&& !n.d[i]; i--);
	out << n.d[i];
	out << setfill('0');
	for (i--; i >= 0; i--)
		out << setw(M) << n.d[i];
	return out;
}



istream & operator >> (istream &in, Bigint &n){
	Bigint bi;
	string s;
	in >> s;
	int lens = s.size(), i = 0, br = 0, b = M;
	for (i = lens; i >= 0; i -= M, br++){
		if (i > M)i -= M, b = M;
		else b = i, i = 0;
		for (; b; i++, b--){
			bi.d[br] *= 10;
			bi.d[br] += int(s[i] - '0');
		}
	}
	n = bi;
	return in;
}

int main(){
	Bigint a,b;
	while(cin>>a>>b){
		while(b<a||b==a)a=a-b;
		cout<<a<<endl;
	} 
}
