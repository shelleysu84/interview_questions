#这种复杂度最低 平均O(n) ，另一种方法是heap
def quickSelect(lines,k):
    if len(lines)!=0:
        pivot=lines[(len(lines)//2)]
        smallerlist=[]
        for i in lines:
            if i<pivot:
                smallerlist.append(i)
        largerlist=[]
        for i in lines:
            if i>pivot:
                largerlist.append(i)
        m=len(smallerlist)
        count=len(lines)-len(smallerlist)-len(largerlist)
        if k >= m and k<m + count:
            return pivot
        elif m > k:
            return quickSelect(smallerlist,k)
        else:
            return quickSelect(largerlist, k - m - count)
			
"""
选取S中一个元素作为枢纽元v，将集合S-{v}分割成S1和S2，就像快速排序那样
如果k <= |S1|，那么第k个最小元素必然在S1中。在这种情况下，返回QuickSelect(S1, k)。
如果k = 1 + |S1|，那么枢纽元素就是第k个最小元素，即找到，直接返回它。
否则，这第k个最小元素就在S2中，即S2中的第（k - |S1| - 1）个最小元素，
我们递归调用并返回QuickSelect(S2, k - |S1| - 1)
"""