#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long>v;
 
void dfs(long long x) {
    if (x > 1000000000)return;
    v.push_back(x);
    dfs(10 * x + 4);
    dfs(10 * x + 7);
}
 
int main() {
    dfs(0);
    sort(v.begin(),v.end());
    long long L,R;
    cin>>L>>R;
    cout<<(upper_bound(v.begin(),v.end(),R)-1)-(lower_bound(v.begin(),v.end(),L))+1<<'\n';
}