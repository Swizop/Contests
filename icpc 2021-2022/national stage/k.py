t = int(input())
for i in range(t):
    inp = input().split()
    l = int(inp[0])
    n = int(inp[1])
    ncop = n
    even = []
    odd = []
    while ncop > 0:
        inp = input().split()
        ncop -= len(inp)
        for j in inp:
            j = int(j)
            if j % 2 == 0:
                even.append(j)
            else:
                odd.append(j)
    
    minTime = -1
    for j in range(len(even)):
        minTime = max(minTime, min(even[j], l - even[j]))
    for j in range(len(odd)):
        minTime = max(minTime, min(odd[j], l - odd[j]))
    print(minTime, end=" ")
    
    even.sort()
    odd.sort()
    stepsDone = 0           #minTime will now become maxTime

    if len(even) == 1:
        minTime = max(minTime, l - even[0], even[0])
    if len(odd) == 1:
        minTime = max(minTime, odd[0], l - odd[0])
    for j in range(len(even) - 1):
        even[j + 1] -= stepsDone
        stepsDone += (even[j + 1] - even[j]) / 2
        even[j + 1] =  (even[j + 1] + even[j]) / 2
        minTime = max(minTime, stepsDone + even[j + 1])
    try:
        minTime = max(minTime, l - even[-1] + stepsDone)
    except IndexError:
        pass

    stepsDone = 0
    for j in range(len(odd) - 1):
        odd[j + 1] -= stepsDone
        stepsDone += (odd[j + 1] - odd[j]) / 2
        odd[j + 1] =  (odd[j + 1] + odd[j]) / 2
        minTime = max(minTime, stepsDone + odd[j + 1])
    try:
        minTime = max(minTime, l - odd[-1] + stepsDone)
    except IndexError:
        pass
    print(int(minTime))