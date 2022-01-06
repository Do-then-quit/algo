import sys


def make_star(n, x, y):
    if n == 3:
        sketch[y][x] = '*'
        sketch[y + 1][x - 1] = '*'
        sketch[y + 1][x + 1] = '*'
        for i in range(0, 5):
            sketch[y + 2][x - 2 + i] = '*'
        return
    make_star(n // 2, x, y)
    make_star(n // 2, x - (n // 2), y + (n // 2))
    make_star(n // 2, x + (n // 2), y + (n // 2))
    return


temp = sys.stdin.readline;r=''
n = int(temp())

sketch = [[' ']*(n * 2) for i in range(n)]

make_star(n ,n - 1 ,0)

for i in range(0, len(sketch)):
    s = sketch[i]
    print(''.join(s))

