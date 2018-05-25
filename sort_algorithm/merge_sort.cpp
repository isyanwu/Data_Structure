void merge_sort(int a[], int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void merge(int a[], int start, int mid, int end) {
	int temp[SIZE];
	int i = start;
	int j = mid+1;
	int k = 0;
	while (i <= mid &&j <= end) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];

	for (int i = 0;i < k;i++) {
		a[start + i] = temp[i];
	}

}
