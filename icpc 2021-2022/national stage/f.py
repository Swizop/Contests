inp = input().split()
n = int(inp[0])
m = int(inp[1])
xs = input().split()

d = {}
fr = {}
pairs = 0
maxi = 0
for x in range(len(xs)):
    xs[x] = int(xs[x])
    try:
        d[xs[x] % m][0] += 1
    except KeyError:
        d[xs[x] % m] = [1, 0]
    try:
        fr[xs[x]] += 1
        if fr[xs[x]] == 2:
            fr[xs[x]] = 0
            d[xs[x] % m][1] += 1
    except KeyError:
        fr[xs[x]] = 1

#print(maxi)
for k in d:
    try:
        while d[k][0] > 0 and d[m - k][0] > 0:
            pairs += 1
            if d[k][0] % 2 == 0:
                d[k][1] -= 1
            if d[m - k][0] % 2 ==0:
                d[m - k][1] -= 1
            d[k][0] -= 1
            d[m - k][0] -= 1
        if d[k][1] > 0:
            pairs += d[k][1]
    except KeyError:
        if d[k][1] > 0:
            pairs += d[k][1]

print(pairs)