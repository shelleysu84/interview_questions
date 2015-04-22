// Example program
#include <iostream>
#include <string>
using namespace std;

//功能：打印螺旋矩阵
//参数说明：matrix ：螺旋矩阵         (x，y) ：第一个元素的坐标
//          start ：第一个元素的值     n ：矩阵的大小
void SetMatrix(int **matrix, int x, int y, int start, int n) {
    int i, j;
    if (n <= 0)
          return;
    if (n == 1) {
          matrix[x][y] = start;
          return;
    }
    for (i = x; i < x + n-1; i++)          /* 上部 */
          matrix[y][i] = start++;
    for (j = y; j < y + n-1; j++)          /* 右边 */
          matrix[j][x+n-1] = start++;
    for (i = x+n-1; i > x; i--)              /* 底部 */
          matrix[y+n-1][i] = start++;
    for (j = y+n-1; j > y; j--)              /* 左边 */
          matrix[j][x] = start++;
    SetMatrix(matrix, x+1, y+1, start, n-2);     /* 递归 */
}
 
int main() {
    int i, j;
    int n;
    int **matrix; //螺旋矩阵（二维数组）
      
    scanf("%d", &n);
    matrix = (int **)malloc(n * sizeof(int *)); //为矩阵分配空间
    for (i = 0; i<n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
      
    SetMatrix(matrix, 0, 0, 1, n);
 
       //打印螺旋矩阵
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
