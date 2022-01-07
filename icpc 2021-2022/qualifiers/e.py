from collections import defaultdict
values = input().split(" ")
N = int(values[3])
R = int(values[0])
G = int(values[1])
B = int(values[2])
d = defaultdict(lambda: 0)


count = 0
x = 0
while x * R <= N:
    y = 0
    while y * G + x * R <= N:
        d[y * G + x * R] += 1
        y += 1
    x += 1

x = 0
while x * B <= N:
    count += d[N - x * B]
    x += 1
    continue

print(count)