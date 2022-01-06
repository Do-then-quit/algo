def max_profit(price_list, count):
    max_list = {}
    for i in range(0, count + 1):
        if i <= 1:
            max_list[i] = price_list[i]
        else:
            if i < len(price_list):
                ans = price_list[i]
            else:
                ans = 0
            for j in range(1, i // 2 + 1):
                temp2 = max_list[i - j] + max_list[j]
                if temp2 > ans:
                    ans = temp2
            max_list[i] = ans
    return max_list[count]

# 테스트
print(max_profit([0, 200, 600, 900, 1200, 2000], 5))
print(max_profit([0, 300, 600, 700, 1100, 1400], 8))
print(max_profit([0, 100, 200, 400, 600, 900, 1200, 1300, 1500, 1800], 9))
