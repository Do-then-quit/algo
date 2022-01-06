def sublist_max(profits):
    total_month = len(profits)
    max_profit = 0
    for start in range(0, total_month):
        for end in range(start, total_month):
            max_profit = max(max_profit, sum(profits[start:end + 1]))

    return max_profit



# 테스트
print(sublist_max([4, 3, 8, -2, -5, -3, -5, -3]))
print(sublist_max([2, 3, 1, -1, -2, 5, -1, -1]))
print(sublist_max([7, -3, 14, -8, -5, 6, 8, -5, -4, 10, -1, 8]))