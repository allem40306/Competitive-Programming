#include <iostream>
#include <vector>
using namespace std;

class SuperUserDo{
	public:
     int install(vector <int> A, vector <int> B){
        bool bb[1005]={0};
		int len=A.size(),ans=0;
       	for(int i=0;i<len;i++)
            for(int j=A[i];j<=B[i];j++)
            	if(!bb[j]){ans++; bb[j]=1;}
        return ans;
     }
};
