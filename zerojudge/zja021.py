import sys

for s in sys.stdin:
    print(eval(s.replace("/","//")))
