//二分查找 复习

//关于right的赋值
//right = n-1 => while(left <= right) => right = middle-1;
//right = n => while(left < right) => right = middle;
//middle的计算不能写在while循环外，否则无法得到更新。

int BinarySearch(int array[], int n, int value){
	int left = 0;
	int right = n - 1;
	while(left <= right){
		int middle = lefy + ((right- left)>>1);
		if (array[middle] > value)
			right = middle - 1;
		else if (array[middle] <　value)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}