#include <iostream>
#include <queue>
using namespace std;
const int N = 100005;
long long a[N];
 
int main() {
    long long ans = 0, n, k, s=0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    queue<int>q;
    for (int i = 0; i < n; i++) {
        q.push(i);
        s += a[i];
        while (!q.empty() && s > k) {
            ans += n - i;
            // cout << q.front() << ' ' << i << '\n';
            s -= a[q.front()]; q.pop();
        }
    }
    cout << ans << '\n';
}