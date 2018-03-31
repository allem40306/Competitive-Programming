import sys

for s in sys.stdin:
    s=int(s)
    if s==0 :
        print(1)
        continue
    print(s*s-s+2)
