bool IsPostOrderOfBST(int array[], int low, int high){
	if (low >= high){
		return true;
	}
	int split = -1, i;
	for (i = low; i < high; i++){
		if(split != -1 && array[i] < array[high])
			return false; //split已经分割但是当时的[i] 却小于high
		if(split == -1 && array[i] > array[high])
			split = i; //当split没有分割 并且找到了新分割点
	}
	if(split == -1) //全是左子树
		return IsPostOrderOfBST(array, low, high - 1);
	return IsPostOrderOfBST(array, low, split - 1) && IsPostOrderOfBST(array,split,high-1);
}
//不知道这种方法对不对呢。。。

//序列array有n个元素
//如果这n个元素是二叉排序树的后续遍历结果 返回true
//否则 返回false
bool isBST(int * array, size_t n)
{
	assert(array != NULL);
	if (n <= 1)
	{
		return true; // 有一个节点 或0个节点 符合树的性质
	}
	size_t i = 0;
	for (i = 0; i < n-1; ++i)
	{
		if (array[i] > array[n-1]) //array[n-1] 为数组最后一个元素 如果是后续遍历 应该是树的根节点。根节点应该大于左子树中的所有节点
		{
			break;
		}
	}
	if (i == n-1)
	{
		//全是左子树中的点
		return isBST(array, n-1); //判断左子树是否成立
	}
	size_t l_end = i;
	for (i; i < n-1; ++i)
	{
		if (array[i] < array[n-1])
		{
			break;		//右子树中的所有节点应该大于根节点
		}
	}
	if (i == n-1)
	{
		// 判断左右子树是否合法
		return isBST(array, l_end) && isBST(array+l_end, n - 1 - l_end);
	}
	return false;
}