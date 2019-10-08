n = int(input())
data = input().split()

list = []
s = set()
for i in data:
    num = int(i)
    if num not in s:
        list.append(num)
        while num > 1 and num not in s:
            s.add(num)
            if num % 2 == 0:
                num = num / 2
            else:
                num = (3 * num + 1) / 2
        if num in list:
            list.remove(num)

list.sort(reverse=True)
print(str(list)[1:-1].replace(',','').replace("'",''))