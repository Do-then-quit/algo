def merge(list1, list2):
    front_index = 0
    back_index = 0
    front_len = len(list1)
    back_len = len(list2)
    new = []
    while (front_index < front_len) or (back_index < back_len):
        if front_index >= front_len:
            new.append(list2[back_index])
            back_index += 1
            continue
        if back_index >= back_len:
            new.append(list1[front_index])
            front_index += 1
            continue

        if list1[front_index] <= list2[back_index]:
            new.append(list1[front_index])
            front_index += 1
            continue
        else:
            new.append(list2[back_index])
            back_index += 1
            continue
    return new
# 합병 정렬

def merge_sort(my_list):
    half = len(my_list) // 2
    front = my_list[:half]
    back = my_list[half:]
    if len(my_list) < 2:
        return my_list

    return merge(merge_sort(front), merge_sort(back))

# 테스트
print(merge_sort([1, 3, 5, 7, 9, 11, 13, 11]))
print(merge_sort([28, 13, 9, 30, 1, 48, 5, 7, 15]))
print(merge_sort([2, 5, 6, 7, 1, 2, 4, 7, 10, 11, 4, 15, 13, 1, 6, 4]))
