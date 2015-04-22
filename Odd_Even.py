#奇偶掉序

def isOddNumber(data):
    return data & 1 == 1

def oddEvenSort1(data, length):
    if length == 0:
        return
    begin = 0
    end = length -1
    while begin < end:
        if isOddNumber(data[begin]): #前面正常
            begin += 1
        elif not isOddNumber(data[end]):#后面正常
            end -= 1
        else:
            data[begin], data[end] = data[end], data[begin]