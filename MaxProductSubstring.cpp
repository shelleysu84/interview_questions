double MaxProductSubString(double *a, int length){
	double maxEnd = a[0];
	double minEnd = a[0];
	double maxRes = a[0];
	for (int i = 1; i < length; ++i){
		double end1 = maxEnd*a[i], end2 = minEnd*a[i];
		maxEnd = max(max(end1, end2), a[i]);
		minEnd = min(min(end1, end2), a[i]);
		maxRes = max(maxRes, maxEnd);
	}
	return maxRes;
}