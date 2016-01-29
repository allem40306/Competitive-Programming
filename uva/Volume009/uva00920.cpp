#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

struct point{
	double x;
	double y;
	point(double, double);
};

point::point(double nx = 0.0, double ny = 0.0) :x(nx), y(ny){}
bool compare(point a, point b){
	return a.x > b.x;
}

double length(point a, point b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main(){
	int cc, n;
	point mountain[105];
	double highest, line, temp, m, c;
	while (cin >> cc){
		for (int i = 0; i < cc; i++){
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> mountain[j].x >> mountain[j].y;
			sort(mountain, mountain + n, compare);
			highest = 0, line = 0;
			for (int j = 1; j < n; j++){
				if (mountain[j].y > highest){
					m = (mountain[j].y - mountain[j - 1].y) / (mountain[j].x - mountain[j - 1].x);
					c = mountain[j].y - m*mountain[j].x;
					temp = (highest - c) / m;
					line += length(mountain[j], point(temp, highest));
					highest = mountain[j].y;
				}
			}
			cout << fixed << setprecision(2) << line << endl;
		}
	}
}
