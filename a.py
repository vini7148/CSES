n = input()
a = [int(i) for i in raw_input().split()]
a.sort()
summ = 0
for i in a:
    if i > summ+1:
        print summ + 1
        break
    summ += i
else:
    print summ + 1