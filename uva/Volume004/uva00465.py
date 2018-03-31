import sys

for s in sys.stdin:
    while s=='\n' or s=='':
        s=input()
    print(s,end='')
    a=s.split(' ')
    if(int(a[0])>2147483647):
        print('first number too big')
    if(int(a[2])>2147483647):
        print('second number too big')
    if a[1]=='+':
        if int(a[0])+int(a[2])>2147483647:
            print('result too big')
    elif int(a[0])*int(a[2])>2147483647:
        print('result too big')
    
