import sys
from fractions import gcd
n=int(input())
while n >0:
    n-=1
    s=input()
    arr=s.split(' ')
    g=gcd(int(arr[0]),int(arr[2]))
    print(int(arr[0])//g,arr[1],int(arr[2])//g)
