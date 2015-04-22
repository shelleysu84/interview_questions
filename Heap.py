#小项堆

class BinHeap:
    def __init__(self):
        self.heap_list = [0]
        self.current_size = 0
    def perc_up(self, i): #小孩子perm up
        while i // 2 > 0: # >0 means this node is still available
            if self.heap_list[i] < self.heap_list[i // 2]:
                tmp = self.heap_list[i // 2]
                self.heap_list[i // 2] = self.heap_list[i]
                self.heap_list[i] = tmp
            i = i // 2
    def insert(self, k):
        self.heap_list.append(k)
        self.current_size = self.current_size + 1
        self.perc_up(self.current_size)
    def perc_down(self, i):
        while (i * 2) <= self.current_size:
            mc = self.min_child(i)
            if self.heap_list[i] > self.heap_list[mc]:
                tmp = self.heap_list[i]
                self.heap_list[i] = self.heap_list[mc]
                self.heap_list[mc] = tmp
            i = mc
    def min_child(self, i):
        if i * 2 + 1 > self.current_size:
            return i * 2
        else:
            if self.heap_list[i * 2] < self.heap_list[i * 2 + 1]:
                return i * 2
            else:
                return i * 2 + 1
    def del_min(self):
        ret_val = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.current_size]
        self.current_size = self.current_size - 1
        self.heap_list.pop()
        self.perc_down(1)
        return ret_val

    def build_heap(self, a_list):
        i = len(a_list) // 2
        self.current_size = len(a_list)
        self.heap_list = [0] + a_list[:] #append original list
        while (i > 0):
            #build the heap we only need to deal the first part!
            self.perc_down(i)
            i=i-1

a_list=[9, 6, 5, 2, 3];
bh=BinHeap();
bh.build_heap(a_list);
print(bh.heap_list)
print(bh.current_size)
bh.insert(10)
bh.insert(7)
print(bh.heap_list)
bh.del_min();
print(bh.heap_list)
print(bh.current_size)

#heap sort
#大项堆
class Heap(object):
	def Parent (self, i):
		if i%2 == 0:
			return i/2 - 1 
		else :
			return i/2
			
	def Left(self, i):
		return 2*i + 1
	def Right(self, i):
		return 2*i +　2
	def maxHeapify(self, a, i, heap_size):
		l = self.Left(i)
		r = self.Right(i)
		largest = i
		if l < heap_size and a[l] > a[largest]:
			largest = l
		if r < heap_size and a[r] > a[largest]:
			largest = r
		#将largest下标保存，下次递归就从下层开始	
		if largest != i:
			a[i], a[largest] = a[largest], a[i]
			self.maxHeapify(a, largest, heap_size)
		
	def BuildMaxHeap(self, a):
		heap_size = len(a)
		for i in range(heap_size/2 - 1, -1, -1):
			self.maxHeapify(a, i , heap_size)
	def HeapSort(self,a):
		heap_size = len(a)
		self.BuildMaxHeap(a)
		for i in range(len(a)-1, 0, -1): #a[0] is max number
			a[0], a[i] = a[i], a[0]
			heap_size -= 1
			self.maxHeapify(a, 0, heap_size)
H = Heap()
x = [0, 2, 6, 98, 34, -5, 23, 11, 89, 100, 4]
x1= [3,9,8,4,5,2,10,18]
H.HeapSort(x)
H.HeapSort(x1)
print x
print x1			