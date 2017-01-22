#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class SwapAndArithmetic{
    public:
        string able(vector<int> aa){
            sort(aa.begin(),aa.end());
            int c=aa[1]-aa[0],n=aa.size();
            string s1="Possible",s2="Impossible";
            for(int i=2;i<n;i++)
                if(aa[i]-aa[i-1]!=c)return s2;
            return s1;
        }
};
