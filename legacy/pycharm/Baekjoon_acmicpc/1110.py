n = int(input())

if n < 10:
    n = n * 10
origin = n
cycle_num = 0

while True:
    n_sum = 0
    n_str = str(n)
    for i in n_str:
        n_sum += int(i)

    new_num = (n % 10) * 10 + (n_sum % 10)
    cycle_num += 1
    if new_num == origin:
        print(cycle_num)
        break
    n = new_num

