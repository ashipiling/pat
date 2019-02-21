import math
def prime(num):
    for j in range(2,int(math.sqrt(num))+1,1):
        if num % j == 0:
            return False
    return True
if __name__ == '__main__':
    n = int(input())
    list = []
    for i in range(2,n + 1):
        if prime(i) and prime(i + 2) and (i + 2 <= n):
            list.append(i)
    print(len(list))