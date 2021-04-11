def sumpair(t,s):
    su = 0
    if s == 1:
        return 0
    else:
        for i in range(s):
            su += i*t[i] - (s-i-1)*t[i]
        return su

for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    pre_xor = [A[0]]
    for i in range(1, n):
        pre_xor.append(A[i]^pre_xor[i-1])
    dp = {}
    ans = 0
    for i in range(n):
        if pre_xor[i] == 0:
            ans += i
        if pre_xor[i] in dp.keys():
            dp[pre_xor[i]].append(i)
        else:
            dp[pre_xor[i]] = [i]
    for x in dp.values():
        s = len(x)
        t = sumpair(x,s)
        if t != 0:
            ans += t - s*(s-1)//2
    print(ans)