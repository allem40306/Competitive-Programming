#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

template<typename T, size_t N = 10>
class Array {
private:
	int rear;
	int size;
	T* arrayPtr;
public:
	explicit Array() {
		arrayPtr = new T[N];
		rear = -1;
		size = N;
	};
	explicit Array(int n) {
		arrayPtr = new T[n];
		rear = -1;
		size = n;
	};
	~Array() {
		delete []arrayPtr;
	}
	bool push_back(const T &n) {
		if (isFull())return 0;
		rear++;
		arrayPtr[rear] = n;
		size = n;
		return 1;
	}
	bool pop_back() {
		if (rear == -1)return 0;
		rear--;
		if (rear == -1)size = -1;
		return 1;
	}
	void minmax(T &min, T &max) {
		if (isEmpty())return;
		min = *min_element(arrayPtr, arrayPtr + rear + 1);
		max = *max_element(arrayPtr, arrayPtr + rear + 1);
		return;
	}
	bool isEmpty() {
		return rear == -1;
	}
	bool isFull() {
		return rear + 1 == size;
	}
	int count()const {
		return rear;
	}
	int capacity() {
		return size;
	}
	T& operator[](const int n) {
		return arrayPtr[n];
	}
	T operator[](const int n)const {
		return arrayPtr[n];
	}
	// ~Array(){};
	// bool push_back(T &){}
	// bool pop_back(T $){}
	// void minmax(min,max)
};

template< typename T, size_t N>
void inputArray(Array< T, N > &theArray, const string top, int &n) {
	stringstream ss(top);
	T x;
	ss >> x;
	theArray.push_back(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		theArray.push_back(x);
	}
	return;
}

template< typename T, size_t N>
void testArray(Array< T, N > &theArray, const string ArrayName) {
	T mn = 0, mx = 0;
	theArray.minmax(mn, mx);
	cout << ArrayName << ' ' << mn << ' ' << mx << '\n';
	return;
}


int checkType(string s) {
	if (isalpha(s[0]))return 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '.')return 1;
	}
	return 2;
}

int main() {
	string s;
	int n;
	while (cin >> n) {
		cin >> s;
		int type = checkType(s);
		if (type == 0) {
			Array<char>a(n);
			inputArray(a, s, n);
			testArray(a, "CharArray");
		} else if (type == 1) {
			Array<double>a(n);
			inputArray(a, s, n);
			testArray(a, "DoubleArray");
		} else {
			Array<int>a(n);
			inputArray(a, s, n);
			testArray(a, "IntArray");
		}
	}
}
