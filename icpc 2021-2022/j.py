from collections import defaultdict
import math


def notPrime(n, d, t):
    if d[n][0] != -1:
        if d[n][1] != t:
            d[n] = (d[n][0], t)
            return d[n][0]
        else:
            return 0
    s = 0
    este = False
    if n % 2 == 0:
        s = s + 1 + notPrime(n / 2, d, t)
        este = True
    for j in range(3,int(math.sqrt(n))+1):
        if n % j == 0:
            if este == False:
                s = s + 1
                este = True
            s = s + notPrime(n / j, d, t)
            s = s + notPrime(j, d, t)
    d[n] = (s, t)
    return s
    


#d = defaultdict(lambda: (-1, 0))
n = int(input())
# d[1] = (0, 0)            #pe 1 il vom aduna separat, la final
# d[2] = (0, 0)

for i in range(n):
    x = int(input())
    d = defaultdict(lambda: (-1, 0))
    d[1] = (0, 0)            #pe 1 il vom aduna separat, la final
    d[2] = (0, 0)
    print(notPrime(x, d, i + 1) + 1)


