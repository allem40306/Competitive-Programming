#include<bits/stdc++.h>
using namespace std;

int p , l;
string str;

string dfs(){
    string s , t;
    int num;
    while(p < l){
        if(str[p] == ']') return s;
        if(str[p] <= '9'&& str[p] > '1'){
            num = str[p] -'0';
            p += 2;
            t = dfs();
            for(int i = 0 ;i < num ; ++i)
                s += t;
        }else s += str[p];
        ++p;
        //cout << s << ' ' << p << endl;
    }
    return s;
}

int main(){
    int t;
    while(cin >> t){
        cin >> ws;
        while(t--){
            str = "";
            p = 0;
            getline(cin,str);
            l = str.size();
            cout << dfs() << endl;
        }
    }
}

