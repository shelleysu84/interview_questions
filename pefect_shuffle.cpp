//perfect shuffle
// 时间O(n)，空间O(n) 数组下标从1开始  
void pefect_shuffle1(int *a,int n) {  
int n2 = n * 2, i, b[N];  
    for (i = 1; i <= n2; ++i) {  
        b[(i * 2) % (n2 + 1)] = a[i];  
    }  
    for (i = 1; i <= n2; ++i) {  
        a[i] = b[i];  
    }  
}  

//数组下标从1开始，from是圈的头部，mod是要取模的数 mod 应该为 2 * n + 1，时间复杂度O(圈长）  
void cycle_leader(int *a,int from, int mod) {  
int last = a[from],t,i;  
      
    for (i = from * 2 % mod;i != from; i = i * 2 % mod) {  
        t = a[i];  
        a[i] = last;  
        last = t;  
          
    }  
    a[from] = last;  
}  