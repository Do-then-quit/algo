
def Z(N, R, C):
    global r, c, count
    if N == 0:
        if (r == R and c == C):
            return

    else:
        Z(N - 1, R, C)
        if (r == R and c == C):
            return

        # 오른쪽 위
        c += 1
        r = r - (2 ** (N - 1) - 1)
        count += 1
        if (r == R and c == C):
            return

        Z(N - 1, R, C)
        if (r == R and c == C):
            return

        # 왼쪽 아래 쭉
        c = c - (2**N - 1)
        r += 1
        count += 1
        if (r == R and c == C):
            return

        Z(N - 1, R, C)
        if (r == R and c == C):
            return

        # 오른쪽 위
        c += 1
        r = r - (2 ** (N - 1) - 1)
        count += 1
        if (r == R and c == C):
            return

        Z(N - 1, R, C)
        if (r == R and c == C):
            return



r = 0
c = 0
count = 0

s = list(map(int, input().split(' ')))

N = s[0]
R = s[1]
C = s[2]

Z(N, R, C)

print(count)

# 일일이 다 하나씩 탐색하지말고 사분면단위로 계속 쪼개나가자. 어쩃든 이거 만든것도 의미는 있었다 재귀를 좀더 이해하게된 계기.
# 


