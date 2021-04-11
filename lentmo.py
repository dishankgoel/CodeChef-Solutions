def takesecond(elem):
    return elem[1]
for i in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    k = int(input())
    x = int(input())
    bigger = 0
    ans = 0
    xored_list_large = []
    xored_list_small = []
    for i in range(n):
        xored_element = A[i]^x
        if xored_element > A[i]:
            bigger += 1
            xored_list_large.append((A[i], xored_element-A[i]))
        else:
            xored_list_small.append((A[i], A[i]-xored_element))
    xored_list_large = sorted(xored_list_large, key=takesecond)
    xored_list_small = sorted(xored_list_small, key=takesecond)
    if bigger>=k:
        if (bigger-k)%2 == 0 or bigger%k == 0:
            ans = sum([t[0]+t[1] for t in xored_list_large]) + sum([t[0] for t in xored_list_small])
        else:
            ans1 = sum([t[0]+t[1] for t in xored_list_large[1:]]) + xored_list_large[0][0] + sum([t[0] for t in xored_list_small])
            ans2 = sum([t[0]+t[1] for t in xored_list_large]) + (xored_list_small[0][0] - xored_list_small[0][1]) + sum([t[0] for t in xored_list_small[1:]])
            ans = max(ans1, ans2)
    else:
        loss = k - bigger
        ans1 = sum([t[0]+t[1] for t in xored_list_large]) + sum([t[0]-t[1] for t in xored_list_small[:loss]]) + sum([t[0] for t in xored_list_small[loss:]])
        ans2 = sum([t[0] for t in xored_list_large]) + sum([t[0] for t in xored_list_small])
        ans = max(ans1, ans2)
    print(ans)