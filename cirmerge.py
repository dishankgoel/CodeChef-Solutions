from collections import defaultdict
dp = defaultdict(int)
def solve(A, size):
    if dp[(tuple(A),size)] != 0:
        return dp[(tuple(A), size)]
    if size == 2:
        return A[0] + A[1]
    ans = 10**12
    for i in range(size):
        if i == size-1:
            penalty = A[0] + A[-1]
            B = A[1:-1] + [penalty]
        else:
            penalty = A[i] + A[i+1]
            B = A[:i] + [penalty] + A[i+2:]
        ans = min(ans, solve(B, size-1)+penalty)
    dp[(tuple(A), size)] = ans
    return ans
    
    

for i in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    print(solve(A, n))
