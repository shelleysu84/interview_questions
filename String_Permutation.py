"""
思路是 例如LSE, permutation N-1 为SE, ES
形成的排列是 L S E 
			S L E
			S E L 
L分别插入 S E 的空格之中
"""

def permutation(word):
	if len(word) <= 1:
		return word
	
	perms = permutation(word[1:])
	char = word[0]
	result = []
	
	for perm in perms:
		for i in range(len(perm)+1):
			result.append(perm[:i] + char + perm[i:])
	return result