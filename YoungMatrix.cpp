//寻找递增矩阵的值
#define ROW 4
#define COL 4
bool YoundMatrix(int array[][COL], int searchKey){
	int i = 0, j = COL - 1;
	int var = array[i][j];
	while(true){
		if (var == searchKey)
			return true;
		else if (var < searchKey && i < ROW - 1)
			var = array[++i][j];
		else if (var > searchKey && j > 0)
			var = array[i][--j];
		else
			return false;
	}
	
}