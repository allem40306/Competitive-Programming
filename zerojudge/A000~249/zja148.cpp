#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
   float n,m,sum;
   while(cin>>n){
   sum=0;
   for (int i=0;i<n;i++){
       cin>>m;
       sum+=m;
       }
       cout<<((sum/n>59)? "no\n" : "yes\n");
   }
}
