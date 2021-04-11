from math import gcd
def gcd_seq(A):
    ans = A[0]
    n = len(A)
    if n > 1:
        ans = gcd(A[0],A[1])
    else:
        return ans
    for i in range(2,n):
        ans = gcd(ans, A[i])
    return ans
        
for i in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    min_a = min(A)
    max_a = max(A)
    sub_1 = []
    sub_2 = []
    sub_3 = []
    for i in range(n):
        if A[i] != max_a:
            sub_3.append(A[i])
        if A[i]%min_a == 0:
            sub_1.append(A[i])
        else:
            sub_2.append(A[i])
    n_2 = len(sub_2)
    if n_2 > 0:
        max_sub_2 = max(sub_2)
        for i in range(len(sub_2)):
            if sub_2[i] != max_sub_2:
                sub_1.append(sub_2[i])
        n_1 = len(sub_1)
        B = gcd_seq(sub_1) + gcd_seq(sub_2)
    else:
        B = min_a
    n_3 = len(sub_3)
    if n_3 > 0:
        C = gcd_seq(sub_3) + max_a
    else:
        C = 2*max_a
    print(max(B,C))