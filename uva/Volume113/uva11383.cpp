#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n;
int Left[N];
int w[N][N], Lx[N], Ly[N];
bitset<N> vx, vy;

bool match(int i) {
	vx[i] = true;
	for (int j = 1; j <= n; j++) {
		if (Lx[i] + Ly[j] - w[i][j] == 0 && !vy[j]) {
			vy[j] = true;
			if (!Left[j] || match(Left[j])) {
				Left[j] = i;
				return true;
			}
		}
	}
	return false;
}

void update() {
	int a = 200;
	for (int i = 1; i <= n; i++) {
		if (vx[i])for (int j = 1; j <= n; j++) {
				if (!vy[j])a = min(a, Lx[i] + Ly[j] - w[i][j]);
			}
	}
	for (int i = 1; i <= n; i++) {
		if (vx[i])Lx[i] -= a;
		if (vy[i])Ly[i] += a;
	}
}

void KM() {
	for (int i = 1; i <= n; i++) {
		Left[i] = Lx[i] = Ly[i] = 0;
		for (int j = 1; j <= n; j++) {
			Lx[i] = max(Lx[i], w[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		while (true) {
			vx.reset(); vy.reset();
			if (match(i))break;
			update();
		}
	}
}

int main(){
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> w[i][j];
            }
        }
        KM();
        int ans = 0;
        for(int i = 1; i <= n ; i++){
            ans += Lx[i];
            if(i != 1)cout << ' ';
            cout << Lx[i]; 
        }
		cout << '\n';
        for(int i = 1; i <= n ; i++){
            ans += Ly[i];
            if(i != 1)cout << ' ';
            cout << Ly[i]; 
        }
		cout << '\n';
        cout << ans << '\n';
    }
}