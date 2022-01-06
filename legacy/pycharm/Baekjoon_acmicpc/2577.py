a = int(input())
b = int(input())
c = int(input())

res = a * b * c
res_s = str(res)

for i in range(0, 10):
    count = 0
    for j in res_s:
        if j == str(i):
            count += 1
    print(count)

