void quick_sort(int a[], int start, int end) {
	if (start >= end) return;
	int mid = partition(a, start, end);
	quick_sort(a, start, mid - 1);
	quick_sort(a, mid + 1, end);
}

int partition(int a[], int start,int end) {
	int p = a[start];
	while (start < end) {
		while (start < end&&a[end] >= p) end--;
		a[start] = a[end];
		while (start < end&&a[start] <= p) start++;
		a[end] = a[start];
	}
	a[start] = p;
	return start;
}
