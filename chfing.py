for i in range(int(input())):
    n,k = tuple(map(int, input().split()))
    m = (k-n)//(n-1)
    prime = 10**9 + 7
    ans = ((k-n)*(m+1) + (m*(m+1)*(n-1))//2 + (k-1))%prime
    print(ans)