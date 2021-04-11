from math import ceil, sqrt
import sys
def factors(n):
    f = set()
    while n%2==0:
        f.add(2)
        n = n/2
    for i in range(3,ceil(sqrt(n))+1,2):
        while n % i== 0: 
            f.add(i)
            n = n / i 
    if n>2:
        f.add(int(n))
    return(f)
    
for i in range(int(input())):
    x1 = ceil(sqrt(10**9))
    print("{} {}".format(1,x1))
    sys.stdout.flush()
    n1 = int(input())
    possible_factors = list(factors(x1**2 - n1))
    for f in possible_factors:
        if ((x1**2)%f) != n1:
            possible_factors.remove(f)
    if len(possible_factors) == 1:
        for f in possible_factors:
            print("{} {}".format(2, f))
            sys.stdout.flush()
            verdict = input()
    elif len(possible_factors) == 2:
        l = list(possible_factors)
        print("{} {}".format(1,l[0]))
        sys.stdout.flush()
        n2 = int(input())
        if n2 == 0:
            print("{} {}".format(2, l[0]))
            sys.stdout.flush()
            verdict = input()
        else:
            print("{} {}".format(2, l[1]))
            sys.stdout.flush()
            verdict = input()
    else:
        l = list(possible_factors)
        n = 10**5
        d = {}
        for t in l:
            d[(n**2)%t] = t
        print("{} {}".format(1, n))
        sys.stdout.flush()
        n3 = int(input())
        print("{} {}".format(2, d[n3]))
        sys.stdout.flush()
        verdict = input()