li = list(map(int,input().split()))
li2 = []
for i in range(len(li)):
    for j in range(li[i]):
        li2.append(i)
if li2[0] == 0:
    k = 0
    while li2[k] == 0:
        k += 1
    out = li2.pop(k)
    li2.insert(0,out)
for i in li2:
    print(i,end = '')