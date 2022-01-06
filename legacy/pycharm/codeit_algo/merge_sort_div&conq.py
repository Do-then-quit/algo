def merge(list1, list2):
    half_1 = len(list1) // 2
    half_2 = len(list2) // 2
    if half_1 == 0 or half_2 == 0:
        if len(list1) == 0 or len(list2) == 0:
            return list1 + list2
        else:
            if list1[half_1] < list2[half_2]:
                return list1 + list2
            else:
                return list2 + list1
    else:
        front = merge(list1[:half_1], list1[half_1:])
        back = merge(list2[:half_2], list2[half_2:])
        front_index = 0
        back_index = 0
        front_len = len(front)
        back_len = len(back)
        new = []
        while (front_index < front_len) or (back_index < back_len):

            if front_index >= front_len:
                new.append(back[back_index])
                back_index += 1
                continue
            if back_index >= back_len:
                new.append(front[front_index])
                front_index += 1
                continue

            if front[front_index] <= back[back_index]:
                new.append(front[front_index])
                front_index += 1
                continue
            else:
                new.append(back[back_index])
                back_index += 1
                continue
        return new



# 코드를 작성하세요.

# 테스트
print(merge([1], []))
print(merge([], [1]))
print(merge([2], [1]))
print(merge([1, 2, 3, 4], [5, 6, 7, 8]))
print(merge([5, 6, 7, 8], [1, 2, 3, 4]))
print(merge([4, 7, 8, 9], [1, 3, 6, 10]))