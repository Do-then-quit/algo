def Z(N, R, C):
    if N == 0:
        return 0

    square_count = 2 ** (2 * N)
    quarter_count = square_count // 4
    lenth = 2 ** N
    half = lenth // 2

    if C < half:
        if R < half:
            return Z(N - 1, R, C)
        else:
            return quarter_count * 2 + Z(N - 1, R - half, C)
    else:
        if R < half:
            return quarter_count + Z(N - 1, R, C - half)
        else:
            return quarter_count * 3 + Z(N - 1, R - half, C - half)


s = list(map(int, input().split(' ')))

N = s[0]
R = s[1]
C = s[2]
print(Z(N, R, C))

# 분할해서 정복하자....

