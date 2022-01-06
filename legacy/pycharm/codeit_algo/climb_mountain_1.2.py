def select_stops(water_stops, capacity):
    ans_lis = []
    now = 0
    for i in range(0, len(water_stops)):

        if water_stops[i] - now > capacity:
            now = water_stops[i - 1]
            ans_lis.append(water_stops[i - 1])
            i -=1
    ans_lis.append(water_stops[-1])
    return ans_lis


# 테스트
list1 = [1, 4, 5, 7, 11, 12, 13, 16, 18, 20, 22, 24, 26]
print(select_stops(list1, 4))

list2 = [5, 8, 12, 17, 20, 22, 23, 24, 28, 32, 38, 42, 44, 47]
print(select_stops(list2, 6))

# 이러면 좀 낫지 (greedy)
