//兑换硬币
//动态规划 
#include<iostream>
using namespace std; 

const int N = 4;  
int dimes[] = {1, 2, 5, 10};  
int arr[N+1] = {1};  
  
int coinExchangeRecursion(int n, int m) //递归方式实现，更好理解
{  
    if (n == 0)    //跳出递归的条件
        return 1;  
    if (n < 0 || m == 0)  
        return 0;  
    return (coinExchangeRecursion(n, m-1) + coinExchangeRecursion(n-dimes[m-1], m));  
	//分为两种情况，如果没有换当前硬币，那么是多少？加上，如果换了当前硬币，总值减少，此时又是多少种兑换方法？
}

int main()
{
	int num=coinExchangeRecursion(N, 4); 
	cout<<num<<endl; 

	return 0; 
}