test_case = int(input())

for i in range(0, test_case):
    answer = input()
    score = 0
    combo = 0
    for j in answer:
        if j == 'O':
            combo += 1
            score += combo
        elif j == 'X':
            combo = 0
    print(score)
