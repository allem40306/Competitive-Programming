#include <iostream>
#include <algorithm>
using namespace std;

struct box{
	int h,w;
}b[6];

bool cmp(box a, box b){
	if (a.h != b.h)
		return a.h > b.h;
	return a.w > b.w;
}

bool solve(){
	for (int i = 0; i < 6; i += 2)
		if (b[i].h != b[i + 1].h || b[i].w != b[i + 1].w)return false;
	int a1 = b[0].h, a2 = b[0].w,b1 = b[2].h, b2 = b[2].w,c1 = b[4].h, c2 = b[4].w;
	if (a1 == b1&&a2 == c1&&b2 == c2)return 1;
	if (a1 == b1&&a2 == c2&&b2 == c1)return 1;
	if (a1 == b2&&a2 == c1&&b1 == c2)return 1;
	if (a1 == b2&&a2 == c2&&b1 == c1)return 1;
	if (a1 == c1&&a2 == b1&&b2 == c2)return 1;
	if (a1 == c1&&a2 == b2&&b1 == c2)return 1;
	if (a1 == c2&&a2 == b1&&b2 == c1)return 1;
	if (a1 == c2&&a2 == b2&&b1 == c1)return 1;
	return 0;
}


int main(){
	int t;
	while (cin >> b[0].h){
		cin >> b[0].w;
		if (b[0].h < b[0].w)t = b[0].h, b[0].h = b[0].w, b[0].w = t;
		for (int i = 1; i < 6; i++){
			cin >> b[i].h >> b[i].w;
			if (b[i].h < b[i].w)t = b[i].h, b[i].h = b[i].w, b[i].w = t;
		}
		sort(b,b + 6, cmp);
		printf(solve() ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
}