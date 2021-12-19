#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 250005;
struct Data {
    long long g, x, y;
    bool operator<(const Data &rhs)const {
        if (g != rhs.g)return g < rhs.g;
        if (y != rhs.y)return y > rhs.y;
        return x < rhs.y;
    }
};
 
long long n, a[N];
int main() {
    vector<Data>v;
    Data d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d.g = i;
        for (int j = 0; j < a[i]; j++) {
            cin >> d.x >> d.y;
            v.push_back(d);
        }
    }
    sort(v.begin(), v.end());
    long long ans = 0, cook = 0;
    for (int i = 0, cnt = 0; i < n; i++) {
        ans = cook;
        for (int j = 0; j < a[i]; j++) {
            cook += v[cnt].x;
            ans = max(ans, cook + v[cnt].y);
            cnt++;
        }
        cout << ans << '\n';
    }
}