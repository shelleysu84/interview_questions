# -*- coding: utf-8 -*-
"""
see if a string is a palindrome
"""
def isPalindrome(s):
	new_s = filter(lambda x : x.isalnum(),s).lower()
	return new_s == new_s[::-1]

"""
see if a number is a palindrome
"""
def isPalindrome(x):
	if x < 0 :
		return False
	div = 1 
	while x / div >= 10:
		div *= 10
	#find 最高位的乘数
	while x :
		left = x/ div
		right = x%10
		if left != right:
			return False
		x = (x % 10) / 10 #去除外围两位
		div = div / 100 #div 也相应除2
	
	
"""
Programming Interview Questions 19: Find Next Palindrome Number
如果是奇数位，只增加中间一位的pow(10, length/2)
如果是偶数位，需要增加中间两位的1.1*pow(10, length/2)

http://www.ardendertat.com/2011/12/01/programming-interview-questions-19-find-next-palindrome-number/
"""
def nextPalinrome(num):
	length = len(str(num))
	oddDigits = (length%2 != 0) #if odd, true
	lelfHalf = getLeftHalf(num) #return a str
	middle = getMiddle(num)     #return a str
	if oddDigits:
		increment = pow(10, length/2)  #only increase mid digits
		newNum = int(lelfHalf + middle + lelfHalf[::-1])
	else:
		increment = int(1.1*10, length/2) #should increase 2 mid digits
		newNum = int(lelfHalf + lelfHalf[::-1])
	
	if newNum > num :
		return newNum
	if middle != '9':
		return newNum + increment
	else : #middle is equal to '9'
		return nextPalinrome(roundUp(num))
	
def getLeftHalf(num):
	return str(num)[:len(str(num))/2]
def getMiddle(num):
	return str(num)[(len(str(num))-1)/2]
def roundUp(num): #比如找198的next Palindrome 先取最上一位 num/increment = 1 需要增加 1 变成200
	length = len(str(num))
	increment = pow(10, (length/2)+1)
	return ((num/increment) + 1)*increment
	
"""
longest palindrome 
"""
def getLongestPalindrome(s, l, r):
	while l >= 0 and r <= len(s) and s[l] == s[r]:
		l -= 1
		r += 1
	return s[l+1:r] #这里注意是l之前已经-1了 所以要加1才算数，r这里本身就指代r - 1
	
def longestPalindrome(s):
	palindrome = ''
	for i in range(s):
		len1 = len(getLongestPalindrome(s,i,i))
		if len1 > len(palindrome):
			palindrome = getLongestPalindrome(s, i, i)
		len2 = len(getLongestPalindrome(s,i,i+1))
		if len2 > len(palindrome):
			palindrome = getLongestPalindrome(s, i, i+1)
	return palindrome

"""
回文的分割 需要穷举出所有符合条件的集合
"""
res = ''
def dfs(s, stringlist):
	if len(s) == 0:
		res.append(stringlist)
	for i in range(1,len(s)+1): #取上限
		if isPalindrome(s[:i]):
			dfs(s[i:], stringlist + [s[:i]])
print res

"""
回文的minCut
"""
def minCut(s):
	dp = [0 for i in range(len(s)+1)]
	p = [[False for i in range(len(s))] for for j in range(len(s))]
	for i in range(len(s)+1):
		dp[i] = len(s) - i
	for i in range(len(s)-1, -1, -1):
		for j in range(i, len(s)):
			if s[i] == s[j] and (((j-i) < 2) or p[i+1][j-1]) :
				p[i][j] = True
				dp[i] = min(1 + dp[j+1], dp[i])
	return dp[0] - 1
		
