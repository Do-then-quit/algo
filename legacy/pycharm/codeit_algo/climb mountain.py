def select_stops(water_stops, capacity):
    now = 0
    ans_lis = []
    while True:
        now += capacity
        while True:
            if now in water_stops:
                ans_lis.append(now)
                break
            else:
                now -= 1
        if now == water_stops[-1]:
            break
    return ans_lis


# 테스트
list1 = [1, 4, 5, 7, 11, 12, 13, 16, 18, 20, 22, 24, 26]
print(select_stops(list1, 4))

list2 = [5, 8, 12, 17, 20, 22, 23, 24, 28, 32, 38, 42, 44, 47]
print(select_stops(list2, 6))

# 거의 brute force 가 돼버렸네
