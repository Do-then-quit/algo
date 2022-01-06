def count(garo, sero, origin):
    count_B = 0
    count_W = 0
    for i in range(sero, sero + 8):
        for j in range(garo, garo + 8):
            if (i-sero + j-garo) % 2 == 0:
                if origin[i][j] == 'B':
                    count_B += 1
            else:
                if origin[i][j] == 'W':
                    count_B += 1

    for i in range(sero, sero + 8):
        for j in range(garo, garo + 8):
            if (i-sero + j-garo) % 2 == 0:
                if origin[i][j] == 'W':
                    count_W += 1
            else:
                if origin[i][j] == 'B':
                    count_W += 1


    if count_B > count_W:
        return count_W
    else:
        return count_B



size = list(map(int, input().split(' ')))

sero = size[0]
garo = size[1]

origin = []

min = garo * sero

for j in range(0, sero):
    origin.append([])
    origin[j] = input()

for i in range(0, garo - 7):
    for j in range(0, sero - 7):
        tmp = count(i, j, origin)
        if min > tmp:
            min = tmp

print(min)







