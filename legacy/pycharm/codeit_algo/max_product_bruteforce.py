def max_product(left_cards, right_cards):
    l_len = len(left_cards)
    r_len = len(right_cards)
    ans = 0

    for i in range(0, l_len):
        for j in range(0, r_len):
            temp = left_cards[i] * right_cards[j]
            if ans < temp:
                ans = temp
    return ans


print(max_product([1, 6, 5], [4, 2, 3]))
print(max_product([1, -9, 3, 4], [2, 8, 3, 1]))
print(max_product([-1, -7, 3], [-4, 3, 6]))