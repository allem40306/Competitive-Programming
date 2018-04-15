#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    int i,t;
    while (cin >> s,s!="0"){
        t = 0;
        for (i = 0; i != s.size(); i++){
            if (isalpha(s[i]))
                t += toupper(s[i]) - 64;
            else break;
        }
        if(i !=s.size())
            cout <<"Fail "<< endl;
        else 
            cout << t << endl;
    }
}