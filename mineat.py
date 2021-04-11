from math import ceil
def sum_k(arr, k):
    su = 0
    for i in arr:
        su += ceil(i/k)
    return su

for _ in range(int(input())):
    n,h = tuple(map(int, input().split()))
    a = list(map(int, input().split()))
    # possible_k = [i for i in range(1, max(a) + 1)]
    low, high = 0, max(a) - 1
    count = 0
    while(low <= high):
        mid = (low + high)//2
        if(sum_k(a, mid+1) > h):
            low = mid + 1
            count = mid + 1
        else:
            high = mid - 1
    print(count+1)