import sys

MXN = 1005
ans = [0,0,1,1]

for i in range(2,MXN - 2):
    ans.append(ans[i] + 2 ** (i - 1))

for s in sys.stdin:
    print(ans[int(s)])