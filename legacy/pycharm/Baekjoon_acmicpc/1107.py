def check(t, b_l, b_s):
    if t < 0:
        return False
    t_l = [int(i) for i in str(t)]
    for i in range(0, b_s):
        if b_l[i] in t_l:
            return False

    return True

now = 100

num = input()
num_lis = [int(i) for i in num]
num = int(num)

broken_size = int(input())

if broken_size == 0:
    broken_lis = []
else:
    broken_lis = list(map(int, input().split(' ')))


i = 0

ans = 0
while True:
    if len(broken_lis) == 10:
        break
    target_p = num + i
    if check(target_p, broken_lis, broken_size):
        ans = -1

    target_n = num - i
    if check(target_n, broken_lis, broken_size):
        ans = 1

    if ans != 0:
        break
    i += 1


if ans == 0:
    if num >= 100:
        ans_100 = num - 100
    else:
        ans_100 = 100 - num

    print(ans_100)
    quit()

target_p_str = str(target_p)
target_n_str = str(target_n)

if ans > 0:
    ans = num - target_n + len(target_n_str)
else:
    ans = target_p - num + len(target_p_str)

if num >= 100:
    ans_100 = num - 100
else:
    ans_100 = 100 - num


if ans_100 > ans:
    print(ans)
else:
    print(ans_100)


