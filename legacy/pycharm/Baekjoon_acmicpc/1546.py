n = int(input())

scores = list(map(int, input().split()))

newscores = []
for i in range(0, n):
    newscores.append(scores[i] / max(scores) * 100)


print(sum(newscores) / n)

