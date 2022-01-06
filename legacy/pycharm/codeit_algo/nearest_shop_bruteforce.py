# 제곱근 사용을 위한 sqrt 함수
from math import sqrt

# 두 매장의 직선 거리를 계산해 주는 함수
def distance(store1, store2):
    return sqrt((store1[0] - store2[0]) ** 2 + (store1[1] - store2[1]) ** 2)

# 가장 가까운 두 매장을 찾아주는 함수
def closest_pair(coordinates):
    num_shop = len(coordinates)

    for a in range(0, num_shop):
        for b in range(a + 1, num_shop):
            temp = distance(coordinates[a], coordinates[b])
            if b == 1:
                ans = temp
                ans_a = a
                ans_b = b
                continue
            if ans > temp:
                ans_a = a
                ans_b = b
                ans = temp
    # 여기 코드를 쓰세요
    pair = [coordinates[ans_a], coordinates[ans_b]]
    return pair
# 테스트
test_coordinates = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
print(closest_pair(test_coordinates))