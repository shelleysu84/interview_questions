#include <stdio.h>
#define Cutoff ( 3 )
#include <iostream>
using namespace std;

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
    int a[] = {0,2,1,3,4};
    int k = 2;
    q_select(a,k,0,5);
    cout<<a[0];
    cout<<a[1];
    cout<<a[2];
    cout<<a[3];
    cout<<a[4];
    return 0;