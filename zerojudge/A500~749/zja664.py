t=int(input())

while t>0:
    t-=1
    s=input()
    print(eval(s.replace('/','//')))
