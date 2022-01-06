def find_same_number(some_list):
    save_list = []

    for i in range(len(some_list)):
        if some_list[i] in save_list:
            return some_list[i]
        save_list.append(some_list[i])
    return None


# 중복되는 수 ‘하나’만 리턴합니다.
print(find_same_number([1, 4, 3, 5, 3, 2]))
print(find_same_number([4, 1, 5, 2, 3, 5]))
print(find_same_number([5, 2, 3, 4, 1, 6, 7, 8, 9, 3]))

# 이걸 brute force 말고 쓸 방법이 있나?
