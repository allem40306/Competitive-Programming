#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int main() {
    int n, m, mn, mx;
    static int a[N], o[N];
    string s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    mn = mx = o[0] = 0;
    cin >> s;
    for (int i = 1; i < n; i++) {
        char ch = s[i - 1];
        if (ch == '=')o[i] = o[i - 1];
        else if (ch == 'L')o[i] = o[i - 1] - 1;
        else o[i] = o[i - 1] + 1;
        mx = max(mx, o[i]);
        mn = min(mn, o[i]);
    }
    // for(int i=0;i<n;i++)cout<<o[i]<<' '; cout<<'\n';
    sort(a, a + m);
    if (mx - mn + 1 > m) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << a[o[i] - mn] << '\n';
    }
    cout << '\n';
}