#include <stdio.h>
#include <stdlib.h>
/*原题：输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
  修改之后改为：对任意一个数组寻找任意个数，使其和为指定的值*/
void findSubSum(int* a, int n, int* num, int index, int tmpSum, int sum)
{
    /*a为给定数组
      n为数组长度
      num为存储的数组
      index为当前寻找到的数的下标
      tmpSum为当前和
      sum为指定和
    */
    int j;
    if (tmpSum > sum)
    {
        return;
    }
    if (tmpSum == sum)
    {
        for (j=0; j<index; j++)
        {
            printf("%d ", num[j]);
        }
        printf("\n");
        return;
    }
    if (n < 1)
    {
        return;
    }
    num[index] = *a;
    tmpSum += *a;
    //printf("a %d, n %d, index %d, tmp %d, sum %d\n", *a, n, index, tmpSum, sum);
    findSubSum(a+1, n-1, num, index+1, tmpSum, sum);
    tmpSum -= *a;
    findSubSum(a+1, n-1, num, index, tmpSum, sum);
}
int main()
{
    int a[] = {1, 3, 4, 7, 11, 13, 2, 8};
    int b[255] = {0};
    findSubSum(a, 8, b, 0, 0, 15);
    return 0;
}