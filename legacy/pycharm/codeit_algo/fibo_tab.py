def fib_tab(n):
    tab = {}
    for i in range(1, n + 1):
        if i == 1 or i == 2:
            tab[i] = 1
        else:
            tab[i] = tab[i - 1] + tab[i - 2]

    return tab[n]


# 테스트
print(fib_tab(10))
print(fib_tab(56))
print(fib_tab(132))