m = 10**9 + 7
def power_2(x, n):
    res = 1
    while(n > 0):
        if (n&1):
            res = (res*x)%m
        n >>= 1
        x *= x
    return res%m
        
for i in range(int(input())):
    k = int(input())
    print(5*power_2(2, k))
