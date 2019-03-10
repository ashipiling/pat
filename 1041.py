n = int(input())
dic = {}
while n>0:
    li = input().split()
    dic[li[1]] = [li[0],li[2]]
    n -= 1
out_n = int(input())
out_l = input().split()

for i in out_l:
    str = ''
    str += dic[i][0]+' '+dic[i][1]
    print(str)