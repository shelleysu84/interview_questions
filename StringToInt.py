"""StringToInt"""

def atoi(str):
	str = str.strip()
	if len(str) == 0 : return 0
	
	res = 0
	i = 0 #index of number begin see if it has sign
	sign = ''
	length = 0 #length of number
	
	if str[0] in '+-':
		sign = str[0]
		i = 1
		
	for i in xrange(i, len(str)):
		if '0' <= str[i] <= '9':
			res = res * 10 + ord(str[i]) - ord('0')
			length += 1
		else:
			break
			
	if res == 0 and (sign or length == 0):
		return 0
	elif res > 0 and sign == '-':
		res *= -1
	if res > 2147483647:
		res = 2147483647
	if res < -2147483648:
		res = -2147483648
	return res
	
	