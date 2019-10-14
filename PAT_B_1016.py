if __name__ == '__main__':
    dataset = input().split()
    string1 = ''
    for i in dataset[0]:
        if i == dataset[1]:
            string1 += i
    if string1 != '':
        str_int1 = int(string1)
    else:
        str_int1 = 0
    string2 = ''
    for j in dataset[2]:
        if j == dataset[3]:
            string2 += j
    if string2 != '':
        str_int2 = int(string2)
    else:
        str_int2 = 0
    print(int(str_int1) + int(str_int2))