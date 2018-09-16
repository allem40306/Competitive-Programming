#include <iostream>
#include <ctime>
#define MAX_SIZE 1000

//#define ALL_FUNCTION_OUTPUT

#ifdef ALL_FUNCTION_OUTPUT
#define TIME
#endif // ALL_FUNCTION_OUTPUT

#ifndef ALL_FUNCTION_OUTPUT
#define FUNCTION 4
/*
FUNCTION 1 Dynamic_Programming
FUNCTION 2 Generating_function
FUNCTION 3 Generating_solution(Table)
FUNCTION 4 Generating_solution(Disposable)
*/
#endif // ALL_FUNCTION_OUTPUT

using namespace std;

typedef long long int (*Combination)(int m,int n);
long long int Dynamic_Programming(int n,int k,int m);
long long int Generating_function(int n,int k,int m);
long long int Generating_solution(int n,int k,int m,Combination comb);
long long int Combination_Table(int m,int n);
long long int Combination_Disposable(int m,int n);

/*
dp(0,0)=1
dp(i,j)=dp(i-1,j-1)+...+dp(i-1,j-m)
*/
long long int dp[MAX_SIZE][MAX_SIZE];
long long int Dynamic_Programming(int n,int k,int m)
{
    for(int i=0;i<=k;++i)
    {
        for(int j=0;j<=n;++j)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int r=1;r<=m && r<=j;++r)
            {
                dp[i][j] += dp[i-1][j-r];
            }
        }
    }
    return dp[k][n];
}

/*
f(n,k,m)
=> (x+...+x^m)^k -> ax^n
*/
long long int arr[MAX_SIZE]={0},tmp[MAX_SIZE]={0},ans[MAX_SIZE]={0};
long long int Generating_function(int n,int k,int m)
{
    if(k*m < n)return 0;
    for(int i=0;i<=n;++i)
    {
        if(i<=m&&i!=0)
        {
            arr[i]=1;
            tmp[i]=1;
        }
        else
        {
            arr[i]=0;
            tmp[i]=0;
        }
        ans[i]=0;
    }
    for(int i=0;i<k-1;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int k=0;k+j<=n;++k)
            {
                ans[j+k]+=arr[j]*tmp[k];
            }
        }
        for(int j=0;j<=n;++j)
        {
            arr[j]=ans[j];
            ans[j]=0;
        }
    }
    return arr[n];
}

/*
f(n,k,m)
=> (x+...+x^m)^k -> ax^n
=> (1+...+x^(m-1))^k -> ax^(n-k)
=> (1-x^m)^k * (1-x)^(-k) -> ax^(n-k)

(1-x^m)^k = (r=0)...+ (-1)^r*(k,r)x^(m*r) +...(r=k)
(1-x)^(-k) = (r=0)...+ (k+r-1,r)x^r +...(r=k)
*/
long long int Generating_solution(int n,int k,int m,Combination comb)
{
    if(k*m < n)return 0;
    long long int ans = 0;
    for(int i=0;(i*m)<=(n-k);++i)
    {
        if(i%2==0)
        {
            ans += comb(k,i) * comb(n-i*m-1,n-k-i*m);
        }
        else
        {
            ans -= comb(k,i) * comb(n-i*m-1,n-k-i*m);
        }
    }
    return ans;
}

long long int comb_t[MAX_SIZE][MAX_SIZE];
bool init = false;
long long int Combination_Table(int m,int n)
{
    if(!init)
    {
        for(int i=0;i<MAX_SIZE;++i)
        {
            for(int j=0;j<MAX_SIZE;++j)
            {
                comb_t[i][j] = 0;
            }
        }

        for(int i=0;i<MAX_SIZE;++i)
        {
            comb_t[i][0] = 1;
            comb_t[i][i] = 1;
            for(int j=1;j<i;++j)
            {
                comb_t[i][j]=comb_t[i-1][j]+comb_t[i-1][j-1];
            }
        }
        init = true;
    }
    if(n > m-n)return comb_t[m][m-n];
    else return comb_t[m][n];
}

long long int comb_d[MAX_SIZE]={0};
long long int Combination_Disposable(int m,int n)
{
    comb_d[0]=1;
    for(int i=1;i<=m;++i)
    {
        comb_d[i]=1;
        for(int j=i-1;j>=1;--j)
        {
            comb_d[j]+=comb_d[j-1];
        }
    }
    return comb_d[n];
}

int main()
{
#ifdef TIME
    clock_t start_t,spent_t,total_dp=0,total_gf=0,total_gs_t=0,total_gs_d=0;
#endif // TIME
    int n,k,m;
    while(cin >> n >> k >> m)
    {
#ifdef ALL_FUNCTION_OUTPUT
#ifdef TIME
        start_t = clock();
#endif // TIME
        cout << "Dynamic_Programming:";
        cout << Dynamic_Programming(n,k,m) << endl;
#ifdef TIME
        spent_t = clock() - start_t;
        total_dp += spent_t;
        cout << "It spent " << spent_t << " clicks (" << ((float)spent_t/CLOCKS_PER_SEC)  << " seconds)." << endl << endl;

        start_t = clock();
#endif // TIME
        cout << "Generating_function:";
        cout << Generating_function(n,k,m) << endl;
#ifdef TIME
        spent_t = clock() - start_t;
        total_gf += spent_t;
        cout << "It spent " << spent_t << " clicks (" << ((float)spent_t/CLOCKS_PER_SEC)  << " seconds)." << endl << endl;

        start_t = clock();
#endif // TIME
        cout << "Generating_solution(Table):";
        cout << Generating_solution(n,k,m,Combination_Table) << endl;
#ifdef TIME
        spent_t = clock() - start_t;
        total_gs_t += spent_t;
        cout << "It spent " << spent_t << " clicks (" << ((float)spent_t/CLOCKS_PER_SEC)  << " seconds)." << endl << endl;

        start_t = clock();
#endif // TIME
        cout << "Generating_solution(Disposable):";
        cout << Generating_solution(n,k,m,Combination_Disposable) << endl;
#ifdef TIME
        spent_t = clock() - start_t;
        total_gs_d += spent_t;
        cout << "It spent " << spent_t << " clicks (" << ((float)spent_t/CLOCKS_PER_SEC)  << " seconds)." << endl << endl;
#endif // TIME
#endif // ALL_FUNCTION_OUTPUT

#ifndef ALL_FUNCTION_OUTPUT
        switch(FUNCTION)
        {
        case 1:
            cout << Dynamic_Programming(n,k,m) << endl;
            break;
        case 2:
            cout << Generating_function(n,k,m) << endl;
            break;
        case 3:
            cout << Generating_solution(n,k,m,Combination_Table) << endl;
            break;
        case 4:
            cout << Generating_solution(n,k,m,Combination_Disposable) << endl;
            break;
        default:
            break;
        }
#endif // ALL_FUNCTION_OUTPUT
    }
#ifdef TIME
    cout << "Dynamic_Programming total spent " << total_dp << " clicks (" << ((float)total_dp/CLOCKS_PER_SEC)  << " seconds)." << endl;
    cout << "Generating_function total spent " << total_gf << " clicks (" << ((float)total_gf/CLOCKS_PER_SEC)  << " seconds)." << endl;
    cout << "Generating_solution used Combination_Table total spent " << total_gs_t << " clicks (" << ((float)total_gs_t/CLOCKS_PER_SEC)  << " seconds)." << endl;
    cout << "Generating_solution used Combination_Disposable total spent " << total_gs_d << " clicks (" << ((float)total_gs_d/CLOCKS_PER_SEC)  << " seconds)." << endl;
#endif // TIME
    return 0;
}
