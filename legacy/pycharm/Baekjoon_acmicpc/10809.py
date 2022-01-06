s = input()

for i in range(ord('a'), ord('z') + 1):
    i = chr(i)
    for j in range(0, len(s)):

        if i == s[j]:
            print('{0} ' .format(j), end = '')
            break
        if j == len(s) - 1:
            print('-1 ' , end = '')
            break


