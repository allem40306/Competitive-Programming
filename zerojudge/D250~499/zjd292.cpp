#include <bits/stdc++.h>
using namespace std;
const int N=200;
int main(){
    for(int i=6;i<=N;i++){
        for(int j=2;j<=N;j++){
            for(int k=j;k<=N;k++){
                for(int l=k;l<=N;l++){
                    if(i*i*i==j*j*j+k*k*k+l*l*l){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                    }
                }
            }
        }
    }
}
