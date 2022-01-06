scores = []
for i in range(0, 5):
    scores.append(int(input()))
    if scores[i] < 40:
        scores[i] = 40

print(sum(scores) // 5)