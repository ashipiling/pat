if __name__ == '__main__':
    movedata = input().split()
    numdata = input().split()
    new_s = numdata[int(movedata[0])-int(movedata[1]):] + numdata[: int(movedata[0])-int(movedata[1])]
    li = ' '.join(new_s)
    print(li, end='')