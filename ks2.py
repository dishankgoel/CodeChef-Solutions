n = int(input())
l = []
i = 1
while len(l)!=n:
    if sum(list(map(int, list(str(i)))))%10 == 0:
        l.append(i)
    i += 1
for i in range(len(l)):
    print("{} {}".format(l[i], i+1))
    
