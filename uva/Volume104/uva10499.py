import sys

while 1:
    s=input()
    s=int(s)
    if(s<0):
        break
    if s==1:
        print(0,end='')
    else:
        print(int(s)*25,end='')
    print('%')
