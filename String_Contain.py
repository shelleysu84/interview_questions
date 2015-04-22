# -*- coding: utf-8 -*-
"""
可以先把长字符串a中的所有字符都放入一个Hashtable里，
然后轮询短字符串b，看短字符串b的每个字符是否都在Hashtable里，
如果都存在，说明长字符串a包含短字符串b，否则，说明不包含。

再进一步，我们可以对字符串A，用位运算（26bit整数表示)
计算出一个“签名”，再用B中的字符到A里面进行查找
"""

def StringContain(a, b):
        _hash = 0
	for astr in a :
		_hash |= (1<<ord(astr)-ord('A'))
	print _hash
	
	for bstr in b:
		if (_hash & (1<<ord(bstr)-ord('A'))) == 0:
			return False
	return True