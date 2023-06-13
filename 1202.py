import heapq
import sys
input = sys.stdin.readline
N, K = map(int, input().split())
jewel = []
bags = []
bagState = [False for _ in range(K)]
for _ in range(N):
    m, v = map(int, input().split())
    jewel.append((m, v))
for _ in range(K):
    c = int(input())
    bags.append(c)

bags.sort()
jewel.sort(key=lambda j: j[0], reverse=True)
answer = 0
heapJewel = []
for b in bags:
    while len(jewel) != 0 and jewel[-1][0] <= b:
        newJewel = jewel.pop()
        heapq.heappush(heapJewel, -newJewel[1])
    if len(heapJewel) == 0:
        continue
    takeJewel = heapq.heappop(heapJewel)
    takeJewel = -takeJewel
    answer += takeJewel

print(answer)