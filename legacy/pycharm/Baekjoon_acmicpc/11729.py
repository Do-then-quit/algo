
def move_disk(start_peg, end_peg):
    print("%d %d" % (start_peg, end_peg))


def hanoi(num_discs, start_peg, end_peg):
    other_peg = 6 - start_peg - end_peg

    if num_discs == 1:
        move_disk(start_peg, end_peg)
    else:
        hanoi(num_discs - 1, start_peg, other_peg)
        move_disk(start_peg, end_peg)
        hanoi(num_discs - 1, other_peg, end_peg)

# 테스트 코드 (포함하여 제출해주세요)
n = int(input())
count = 2 ** n - 1
print(count)
hanoi(n, 1, 3)

