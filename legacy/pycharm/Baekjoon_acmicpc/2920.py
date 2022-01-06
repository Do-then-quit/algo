def check_ascending(numbers):
    for i in range(0, 7):
        if numbers[i] != (numbers[i + 1] - 1):
            return 1
    return 0

def check_descending(numbers):
    for i in range(0, 7):
        if numbers[i] != (numbers[i + 1] + 1):
            return 1
    return 0



numbers = list(map(int, input().split(' ')))

if check_ascending(numbers) == 0:
    print("ascending")
elif check_descending(numbers) == 0:
    print("descending")
else:
    print("mixed")





