//求一个数组中最小k的数
//选取S中一个元素作为枢纽元v，将集合S-{v}分割成S1和S2，就像快速排序那样
//如果k <= |S1|，那么第k个最小元素必然在S1中。在这种情况下，返回QuickSelect(S1, k)。
//如果k = 1 + |S1|，那么枢纽元素就是第k个最小元素，即找到，直接返回它。
//否则，这第k个最小元素就在S2中，即S2中的第（k - |S1| - 1）个最小元素，我们递归调用并返回QuickSelect(S2, k - |S1| - 1)。
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define Cutoff ( 3 )

void swap( int *a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int median3( int a[ ], int left, int right )
{
    int Center = ( left + right ) / 2;

    if( a[ left ] > a[ Center ] )
        swap( &a[ left ], &a[ Center ] );
    if( a[ left ] > a[ right ] )
        swap( &a[ left ], &a[ right ] );
    if( a[ Center ] > a[ right ] )
        swap( &a[ Center ], &a[ right ] );

    swap( &a[ Center ], &a[ right - 1 ] );  
    return a[ right - 1 ];                
}
void insert_sort( int a[ ], int n )
{
    int j, p, tmp; 
    for( p = 1; p < n; p++ )
    {
        tmp = a[ p ];
        for( j = p; j > 0 && a[ j - 1 ] > tmp; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
    }
}

void q_select( int a[ ], int k, int left, int right )
{
    int i, j;
    int Pivot;

    if( left + Cutoff <= right )
    {
        Pivot = median3( a, left, right );
        //取三数中值作为枢纽元，可以消除最坏情况而保证此算法是O（N）
        i = left; j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < Pivot ){ }
            while( a[ --j ] > Pivot ){ }
            if( i < j )
                swap( &a[ i ], &a[ j ] );
            else
                break;
        }
        swap( &a[ i ], &a[ right - 1 ] );  /* 重置枢纽元 */

        if( k <= i )
            q_select( a, k, left, i - 1 );
        else if( k > i + 1 )
            q_select( a, k, i + 1, right );
    }
    else  
        insert_sort( a + left, right - left + 1 );
}

int main(int argc, const char *argv[])
{
    int a[] = {0,2,9,3,4};
    int k = 5;
    q_select(a,k,0,5);
    printf("%d\n",a[k-1]);
    return 0;
}