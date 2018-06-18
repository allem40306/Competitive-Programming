import sys

while 1:
    s=input()
    if(s=='-1'):
        break
    s=int(s)
    if s==1:
        print(0,end='')
    else:
        print(int(s)*25,end='')
    print('%')
