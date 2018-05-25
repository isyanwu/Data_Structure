#include<iostream>
using namespace std;
const int SIZE = 6;
void print_arr(int a[], int length);
void merge_sort(int a[], int start, int end);
void merge(int a[],int start, int mid, int end);

int main() {
	int a[6] = { 5,6,2,6,3,9 };
	merge_sort(a, 0, 5);
	print_arr(a, 6);
	system("pause");

}

void print_arr(int a[], int length) {
	for (int i = 0; i < length;i++) {
		cout << a[i] << endl;
	}
}

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
