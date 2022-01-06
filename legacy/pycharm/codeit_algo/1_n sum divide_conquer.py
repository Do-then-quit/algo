def consecutive_sum(start, end):
    if start == end:
        return start
    half = (start + end) // 2
    return consecutive_sum(start, half) + consecutive_sum(half + 1, end)

# 테스트
print(consecutive_sum(1, 10))
print(consecutive_sum(1, 100))
print(consecutive_sum(1, 253))
print(consecutive_sum(1, 388))