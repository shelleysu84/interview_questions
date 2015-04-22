def balance_point(li):
	start = 0
	end = len(li) - 1 
	sum_start = li[start]
	sum_end = li[end]
	while start < end:
		if sum_start == sum_end and end - start == 2:
			return start + 1
		if sum_start < sum_end:
			start += 1 #先指后一项
			sum_start += li[start] #再加起来
		else:
			end -= 1
			sum_end += li[end]
	return -1