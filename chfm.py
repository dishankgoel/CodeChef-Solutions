for i in range(int(input())):
    n = int(input())
    A = list(map(int,input().split()))
    su = sum(A)
    mean = su/n
    for j in range(n):
        if (su-A[j])/(n-1) == mean:
            print(j+1)
            break
    else:
        print('Impossible')