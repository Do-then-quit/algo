def min_fee(pages_to_print):
    waitline = len(pages_to_print)
    if waitline == 0:
        return 0

    choose = min(pages_to_print)
    pages_to_print.remove(choose)
    return choose * waitline + min_fee(pages_to_print)


# 테스트
print(min_fee([6, 11, 4, 1]))
print(min_fee([3, 2, 1]))
print(min_fee([3, 1, 4, 3, 2]))
print(min_fee([8, 4, 2, 3, 9, 23, 6, 8]))
