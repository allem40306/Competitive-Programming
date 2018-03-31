import sys

dp=[[0 for i in range (101)] for j in range(101)]
for i in range(101):
    dp[i][0]=1
dp[1][1]=1
i=2
while i<=100:
    j=1
    while j<=i:
        dp[i][j]=dp[i-1][j]+dp[i-1][j-1]
        j+=1
    i+=1

for s in sys.stdin:
    n,m=s.split()
    if int(n)==0 and int(m)==0:
        break
    print(n+' things taken '+m+' at a time is '+str(dp[int(n)][int(m)])+' exactly.')
