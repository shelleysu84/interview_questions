# -*- coding: utf-8 -*-
list1 = []
def sumOfkNumber(sum, n):
    # list1(sum,n)= list1(sum-n,n-1)+list1(sum,n-1) 取n和不取n的情况
    if n <= 0 or sum <= 0:
        return
    if sum == n:
        list1.reverse()
        if list1 == []:
            print n
        else:
            print n, " + ", " + ".join(str(x) for x in list1)
        list1.reverse()
    list1.append(n)
    sumOfkNumber(sum - n, n - 1) #
    list1.pop()
    sumOfkNumber(sum, n - 1)