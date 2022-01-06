s = input()
word_count = 0
check = 0
for i in s:
    if 'a' <= i <= 'z' or 'A' <= i <= 'Z':
        if check == 1:
            continue

        word_count += 1
        check = 1
    if ' ' == i:
        check = 0

print(word_count)
