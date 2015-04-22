//find majority number
int findMajorityNum(int *a, int length){
	int candidate = a[0];
	int nTimes = 1;
	for (int i = 1; i < length; i++){
		if(nTimes == 0){
			candidate = a[i];
			nTimes = 1;
		}
		else{
			if(candidate==a[i])
				nTimes++;
			else
				nTimes--;
		}
	}
	return candidate;
}