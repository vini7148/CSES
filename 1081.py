n=input()
a=[int(i) for i in raw_input().split()]
arr=[0 for i in range(10**6+1)]
for i in a:
    arr[i]+=1
maxx=1
for i in range(2,10**6+1):
    ct=0
    for j in range(i,10**6+1,i):
        ct+=arr[j]
        if ct>1:
            maxx=i
            break
print maxx