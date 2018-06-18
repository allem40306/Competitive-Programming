t=int(input())

while t>0:
    s=input()
    ans=1
    for c in s:
        cc=int(c)
        if ans==2:
            if cc==1:
                ans=1
        elif ans==3 or ans==4:
            if cc==1 or cc==3 or cc==4:
                ans=cc
        else:
            ans=cc
        ##print(ans,end='->')
    print(ans)
    t-=1
