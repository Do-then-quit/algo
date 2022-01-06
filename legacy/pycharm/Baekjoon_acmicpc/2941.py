s = input()
a = len(s)
croan = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
for i in croan:
    a = a - s.count(i)
print(a)

