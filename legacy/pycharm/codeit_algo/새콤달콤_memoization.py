def max_profit_memo(price_list, count, cache):
    if count <= 4:
        cache[count] = price_list[count]
        return cache[count]
    else:
        if count in cache:
            return cache[count]
        else:
            ans = 0
            for i in range(1, count // 2 + 1):
                temp = max_profit_memo(price_list, count - i, cache) + max_profit_memo(price_list, i, cache)
                ans = max(ans, temp)
            cache[count] = ans
            return cache[count]




# 코드를 작성하세요.


def max_profit(price_list, count):
    max_profit_cache = {}

    return max_profit_memo(price_list, count, max_profit_cache)


# 테스트
print(max_profit([0, 100, 400, 800, 900, 1000], 5))
print(max_profit([0, 100, 400, 800, 900, 1000], 10))
print(max_profit([0, 100, 400, 800, 900, 1000, 1400, 1600, 2100, 2200], 9))
