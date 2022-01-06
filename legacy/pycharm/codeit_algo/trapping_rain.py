def trapping_rain(buildings):
    search = max(buildings)
    ans = 0
    for i in range(search, 0, -1):
        for j in range(0, len(buildings)):
            if buildings[j] >= i:
                for k in range(j + 1, len(buildings)):
                    if buildings[k] >= i:
                        ans = ans + k - j - 1
                        break

    return ans

print(trapping_rain([3, 0, 0, 2, 0, 4]))
print(trapping_rain([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))