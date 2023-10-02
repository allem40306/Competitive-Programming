import sys

MXN = 1005
ans = [0,0,1,1]

for i in range(4,MXN + 1):
    if i % 2:
        ans.append(ans[i - 1] * 2 - 1)
    else:
        ans.append(ans[i - 1] * 2 + 1)

for s in sys.stdin:
    print(ans[int(s)])