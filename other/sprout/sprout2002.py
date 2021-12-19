k=int(input())
n=k
n2=k+1
k2=k+1
b=0
while (k+b)>=3:
    b+=k
    n+=int(b/3)
    k=int(b/3)
    b=b%3
b=0
while (k2+b)>=3:
    b+=k2
    n2+=int(b/3)
    k2=int(b/3)
    b=b%3
print (max(n,n2-1))