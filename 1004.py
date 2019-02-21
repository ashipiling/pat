if __name__ == '__main__':
    n = int(input())
    max_string = ''
    min_string = ''
    max = 0
    min = 100
    while n >= 1:
        data = input().split()
        if int(data[2]) > max:
            max = int(data[2])
            max_string = data[0]+' '+data[1]
        if int(data[2]) < min:
            min = int(data[2])
            min_string = data[0]+' '+data[1]
        n = n-1
    print(max_string+'\n'+min_string)