# def cheie(tu):
#     return tu[1]

# t = int(input())

# for i in range(t):
#     n = int(input())
#     ch = []
#     for j in range(n):
#         values = input().split(" ")
#         s = 0
#         for x in values[1:]:
#             s += int(x)
#         ch.append((j, s))
    
#     ch.sort(key=cheie)
#     y = 0.0
#     for tu in ch:



t = int(input())

for i in range(t):
    n = int(input())
    ch = []
    for j in range(n):
        values = input().split(" ")
        s = 0
        for x in values[1:]:
            s += int(x)
        ch.append(s)
    
    ch.sort()
    suma = 0
    currTime = 0
    for tu in ch:
        currTime += tu
        suma += currTime
    print(float(suma) / len(ch))