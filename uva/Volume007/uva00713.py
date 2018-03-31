def rs(a):
    v=0
    while a>0:
        v=v*10+a%10
        a//=10
    return v

t=int(input())
while t>0:
    t-=1
    a,b=input().split()
    a,b=int(a),int(b)
    print(rs(rs(a)+rs(b)))
