import sys


def make_star(n, x, y):
    if n == 1:
        sketch[y][x] = '*'
        return
    make_star(n // 3, x, y)
    make_star(n // 3, x + (n // 3), y)
    make_star(n // 3, x + 2 * (n // 3), y)
    make_star(n // 3, x, y + (n // 3))
    make_star(n // 3, x + 2 * (n // 3), y + (n // 3))
    make_star(n // 3, x, y + 2 * (n // 3))
    make_star(n // 3, x + (n // 3), y + 2 * (n // 3))
    make_star(n // 3, x + 2 * (n // 3), y + 2 * (n // 3))
    return


temp = sys.stdin.readline
r = ''
n = int(temp())

sketch = [[' '] * n for i in range(n)]

make_star(n, 0, 0)

for i in range(0, len(sketch)):
    s = sketch[i]
    print(''.join(s))

# 동작시간이 조금 끔찍...하다....
