import re
if __name__== "__main__":
    n = int(input())
    dataset = []
    while n >= 1:
        dataset.append(input())
        n = n - 1
    for i in dataset:
        pa = re.compile(r"A*PA+TA*")
        if pa.match(i):
            s = re.split(r"P|T",i)
            if len(s[0])*len(s[1]) == len(s[2]):
                print("YES")
            else:
                print("NO")
        else:
            print("NO")