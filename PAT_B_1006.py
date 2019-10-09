if __name__ == '__main__':
    num = input()
    string = ''
    if len(num) == 3:
        string += int(num[0])*'B'+int(num[1])*'S'+str([i for i in range(1,int(num[2])+1)])[1:-1].replace(", ",'')

    elif len(num) == 2:
        string += int(num[0]) * 'S' + str([i for i in range(1, int(num[1]) + 1)])[1:-1].replace(", ",'')

    else:
        string += str([i for i in range(1, int(num[0]) + 1)])[1:-1].replace(", ", '')
    print(string)