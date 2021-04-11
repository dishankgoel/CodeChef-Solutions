from collections import defaultdict
def solve(A, pos, n):
    d = defaultdict(int)
    i = 1
    fresh = 0
    hit = 1
    d_sum = 0
    while d[pos] != 1:
        while d[i] == 1:
            i = (i+1)%(n)
        if fresh == i:
            d[pos] = 1
            break
        if i == pos:
            if hit == 1:
                d_sum += A[fresh]
            else:
                hit = 1
            fresh = i
        else:
            if hit == 0:
                fresh = i
                hit = 1
            else:
                d[i] = 1
                hit = 0
        i = (i+1)%(n)
    return d_sum
        
        
for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    f = int(input())
    p = 0
    d_sheild = 10**12
    for i in range(n-1):
        if A[i] <= f:
            d1 = solve(A, i, n-1) + f
            if d1 < d_sheild:
                d_sheild = d1
                p = i+1
    if d_sheild == 10**12:
        print("impossible")
    else:
        print("possible")
        print("{} {}".format(p, d_sheild))