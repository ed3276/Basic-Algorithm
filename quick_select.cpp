int partition(vector<int>& A, int p, int r)
{
	int x = A[r];
	int i = p-1;
	for (int j=p; j<=r-1; ++j) {
		if(A[j]<=x) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r])
	return i+1;
}

int quickselect(vector<int>& A, int p, int r, int i) {
	if (p==r) {
		return A[p];
	}
	q = partition(A, p, r);
	int k = q-p+1;
	if (i == k) {
		return A[q];
	} else if (i<k) {
		return quickselect(A, p, q-1, i);
	} else {
		return quickselect(A, q+1, r, i-k);
	}
}
