def min_coin_count(value, coin_list):
    count = 0
    while value > 0:
        if value >= 500:
            value -= 500
            count += 1
            continue
        if value >= 100:
            value -= 100
            count += 1
            continue
        if value >= 50:
            value -= 50
            count += 1
            continue
        if value >= 10:
            value -= 10
            count += 1
            continue

    return count


# 테스트
default_coin_list = [100, 500, 10, 50]
print(min_coin_count(1440, default_coin_list))
print(min_coin_count(1700, default_coin_list))
print(min_coin_count(23520, default_coin_list))
print(min_coin_count(32590, default_coin_list))