int firstMissingPositive(int A[], int n){
	sort(A, A+n);
	int res = 0;
	int i = 0;
	while (i<n && A[i] <= 0) i++; //过滤掉负数
	for (; i < n; i++){
		if (i >0 && A[i] == A[i-1]) continue;
		if (A[i] - res != 1) return res + 1;
		else res = A[i]; //每次都纪录好过去的A[i]
	}
}