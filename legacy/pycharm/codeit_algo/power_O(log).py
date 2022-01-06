def power(x, y):
    if y == 1:
        return x
    half = y // 2
    half_result = power(x, half)

    if y % 2 == 0:
        return half_result * half_result
    else:
        return half_result * half_result * x


# 테스트
print(power(3, 5))
print(power(5, 6))
print(power(7, 9))

# 이건 따지면 메모이제이션일까?
