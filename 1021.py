import collections
if __name__ == '__main__':
    num = input()
    dict = {}
    li1 = []
    for i in num:
        dict[i] = num.count(i)
    dict2 = collections.OrderedDict(sorted(dict.items()))
    for k,v in dict2.items():
        print(k+':'+str(v))