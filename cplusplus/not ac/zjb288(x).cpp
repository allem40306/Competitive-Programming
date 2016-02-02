#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 1010
double p[N][2], m = 0;

double length(int x, int y){
	float len;
	len = (p[x][0] - p[y][0]) * (p[x][0] - p[y][0]) + (p[x][1] - p[y][1]) * (p[x][1] - p[y][1]);
	return sqrt(len);
}

double area(int j, int k, int l){
	double ar;
	int a = length(j, k);
	int b = length(k, l);
	int c = length(j, l);
	int s = (a + b + c) / 2;
	ar = sqrt(s*(s - a)*(s - b)*(s - c));
	return ar;
}

double c (int i,int j,int k,int l){
	double mmax;
	for (; j < i - 2; j++)
		for (; k < i - 1; k++)
				for (; l < i; l++)
					mmax = max(mmax, area(j, k, l));
	return mmax;
}

int main(){
	int n;
	while (cin >> n){
		for (int i1 = 0; i1 < N; i1++)p[i1][0] = p[i1][1] = 0;
		for (int i = 0; i < n; i++)
			cin >> p[i][0] >> p[i][1];
		cout << c(n, 0, 1, 2) << endl;
	}
}