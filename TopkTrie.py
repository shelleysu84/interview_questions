def mapCharToNum(char):
    return ord(char) - ord("a")
    
def mapNumToChar(num):
    return chr(num + ord("a"))

class Node:
    def __init__(self):
        self.count = 0
        self.next = [None for i in range(26)] #map [a-z] to [0-25]

class Trie:
    def __init__(self):
        self.root = Node()
        self.ret = {}
        
    def insert(self, word):
        cur = self.root
        
        for char in word:
            idx = mapCharToNum(char)
            if cur.next[idx] == None:
                cur.next[idx] = Node()
            cur = cur.next[idx]
        
        cur.count = cur.count + 1
    
    def search(self, word):
        cur = self.root
        
        for char in word:
            idx = mapCharToNum(char)
            if cur.next[idx] == None:
                return False
            cur = cur.next[idx]
        
        return cur.count != 0
    
    def getFrequency(self):
        cur = self.root
        
        def inDFS(cur, word):
            if cur.count != 0:
                self.ret[word] = cur.count
            for i in range(26):
                if cur.next[i] != None:
                    inDFS(cur.next[i], word + mapNumToChar(i))
                    
        inDFS(cur, "")

tree = Trie()
tree.insert('book')
tree.insert('big')
tree.insert('bigbang')
tree.insert('book')
tree.insert('as')
tree.insert('book')
tree.insert('ass')
tree.insert('book')
tree.insert('bigbang')
tree.insert('bigbang')
tree.insert('bigbang')
tree.insert('bigbang')

print(tree.search('book'))
print(tree.search('bigbang'))
print(tree.search('as'))
print(tree.search('assert'))
print(tree.search('a'))

tree.getFrequency()
print(tree.ret)
#tree.ret : {'ass': 1, 'big': 1, 'hook': 1, 'as': 1, 'bigbang': 2, 'book': 3}

import heapq
 
class TopkHeap(object):
    def __init__(self, k):
        self.k = k
        self.data = list(tuple())
 
    def Push(self, elem):
        if len(self.data) < self.k:
            heapq.heappush(self.data, elem)
        else:
            topk_small = self.data[0][1]
            if elem[1] > topk_small:
                heapq.heapreplace(self.data, elem)
 
    def TopK(self):
        return [x for x in reversed([heapq.heappop(self.data) for x in xrange(len(self.data))])]
    
Kheapq = TopkHeap(2)
for key,value in tree.ret.items():
    Kheapq.Push((key,value))
print Kheapq.TopK()