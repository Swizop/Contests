n = int(input())
count = 0
q1 = q2 = q3 = 0

for i in range(n):
    string = input()
    count += string.count("AB")
    if string[0] == "B" and string[-1] == "A":
        q3 += 1
    elif string[-1] == "A":
        q1 += 1
    elif string[0] == "B":
        q2 += 1

if q3 > 0:
    count += (q3 - 1)
    if q1 > 0:
        count += 1
        q1 -= 1
    if q2 > 0:
        count += 1
        q2 -= 1

count += min(q1, q2)
print(count)