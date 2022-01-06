def binary_search(element, some_list):
    last = len(some_list) - 1
    first = 0

    while first <= last:
        mid = int((first + last) / 2)

        if element < some_list[mid]:
            last = mid - 1
        elif element > some_list[mid]:
            first = mid + 1
        else:
            return mid


print(binary_search(2, [2, 3, 5, 7, 11]))
print(binary_search(0, [2, 3, 5, 7, 11]))
print(binary_search(5, [2, 3, 5, 7, 11]))
print(binary_search(3, [2, 3, 5, 7, 11]))
print(binary_search(11, [2, 3, 5, 7, 11]))
