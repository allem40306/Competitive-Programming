#include <iostream>
using namespace std;
const int N = 10005;
int t[N], s[N];

int main(){
    int c = 2;
    t[1] = 2; s[1] = 1;
    for(int i = 2; i < N; ++i){
        s[i] = s[i - 1] + t[i - 1];
        if(t[i - 1] + 1 != s[c]){
            t[i] = t[i - 1] + 1;
        }else{
            t[i] = t[i - 1] + 2;
            c++;
        }
    }
    int n;
    while(cin >> n){
        cout << s[n] << '\n';
    }
}