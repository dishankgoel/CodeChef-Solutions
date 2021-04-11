from collections import defaultdict

def eve_1s(x):
    x ^= x>>16
    x ^= x>>8
    x ^= x>>4
    x ^= x>>2
    x ^= x>>1
    return not (x & 1)

def xor_c(x, l):
    mb = defaultdict(int)
    for m in l:
        while mb[m.bit_length() - 1] != 0:
            m ^= mb[m.bit_length() - 1]
        if m != 0:
            mb[m.bit_length() - 1] = m
    while mb[x.bit_length() - 1] != 0:
        x ^= mb[x.bit_length() - 1]
    return x == 0
    
for i in range(int(input())):
    even,odd = 0,0
    s = []
    q = int(input())
    mb = defaultdict(int)
    for i in range(q):
        x = int(input())
        if s == []:
            s.append(x)
            m = x
            while mb[m.bit_length() - 1] != 0:
                m ^= mb[m.bit_length() - 1]
            if m != 0:
                mb[m.bit_length() - 1] = m

            if eve_1s(x):
                even += even
                odd += odd
                even += 1
            else:
                odd,even =odd+even,even+odd
                odd += 1
            print("{} {}".format(even,odd))
        else:
            k = x
            while mb[k.bit_length() - 1] != 0:
                k ^= mb[k.bit_length() - 1]
            if not k == 0:
                if eve_1s(x):
                    even += even
                    odd += odd
                    even += 1
                else:
                    odd,even =odd+even,even+odd
                    odd += 1
                print("{} {}".format(even,odd))
                m = x
                while mb[m.bit_length() - 1] != 0:
                    m ^= mb[m.bit_length() - 1]
                if m != 0:
                    mb[m.bit_length() - 1] = m
            else:
                print("{} {}".format(even,odd))
