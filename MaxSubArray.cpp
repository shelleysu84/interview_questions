int MaxSubArray(int* a, int n)
{
    int currSum = 0;
    int maxSum = a[0];       //全负情况，返回最大数

    for (int j = 0; j < n; j++)
    {
        currSum = (a[j] > currSum + a[j]) ? a[j] : currSum + a[j];
        maxSum = (maxSum > currSum) ? maxSum : currSum;

    }
    return maxSum;
}