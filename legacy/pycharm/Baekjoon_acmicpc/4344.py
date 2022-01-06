c = int(input())

for i in range(0, c):
    line = list(map(int, input().split()))
    n = line.pop(0)

    over = 0
    ave = sum(line) / n
    for j in range(0, n):
        if line[j] > ave:
            over += 1
    over_ave = over / n * 100
    print('{0:.3f}%' .format(over_ave))


