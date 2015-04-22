# -*- coding: utf-8 -*-
import string
"""1.1 旋转字符串

题目描述

给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，
如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串“cdefab”。
请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。

思路例如，字符串 abcdef ，若要让def翻转到abc的前头，只要按照下述3个步骤操作即可：

1. 首先将原字符串分为两个部分，即X:abc，Y:def；
2. 将X反转，X->X^T，即得：abc->cba；将Y反转，Y->Y^T，即得：def->fed。
3. 反转上述步骤得到的结果字符串X^TY^T，即反转字符串cbafed的两部分
（cba和fed）给予反转，cbafed得到defabc，形式化表示为(X^TY^T)^T=YX，这就实现了整个反转。
"""

def RotateString(s, _from, _to):
	s = list(s)
	while _from < _to:
		temp = s[_from]
		s[_from] = s[_to]
		s[_to] = temp
		_from += 1
		_to -= 1
	return ''.join(s)
	
def LeftRotateString(s, end, start):
	mid = start%end
	pre = RotateString(s, 0, mid)
	back = RotateString(s, mid+1, end)
	#print pre[:mid+1], back[mid+1:]
	newstring = ''.join(pre[:mid+1]+back[mid+1:])
	#print newstring
	return RotateString(newstring, 0, end)
	

#链表翻转 leetcode 原题

class ListNode(object):
	def __init__(self, val):
		self.val = val
		self.next = None

def RotateList(Listhead, _from, _to):
	if Listhead == None or Listhead.next == None:
	    return Listhead
	dummy = ListNode(0)
	dummy.next = Listhead
	#connect dummy and listhead
	head1 = dummy
	for i in range(_from-1):
		head1 = head1.next
	p = head1.next
	for i in range(_to - _from):
	#each time head1 fixed, rest nodes extract to head1.next
		temp = head1.next
		head1.next = p.next
		p.next = p.next.next
		head1.next.next = temp
	return dummy.next

Listhead = ListNode(1)
Listhead.next = ListNode(2)
Listhead.next.next = ListNode(3)
Listhead.next.next.next = ListNode(4)
Listhead.next.next.next.next = ListNode(5)

"""
单词翻转 Programming Interview Questions 12: Reverse Words in a String
"""

def reverseWords3(text):
    words=[]
    length=len(text)
    space=set(string.whitespace)
    index=0
    while index<length:
        if text[index] not in space:
            wordStart=index
            while index<length and text[index] not in space:
                index+=1
            words.append(text[wordStart:index])
        index+=1
 
    print " ".join(reversed(words))
	
def reverseWords4(text):
    words=text[::-1].split()
    print " ".join([word[::-1] for word in words])
