#include<iostream>
using namespace std;
void print_array(int a[],int length);
void quick_sort(int a[], int start, int end);
int partition(int a[], int start, int end);

int main() {
	int a[5] = {2,1 ,9 ,7,0};
	quick_sort(a,0,4);
	print_array(a,5);
	system("pause");
	return 0;
}

void print_array(int a[],int length) {
	for (int i = 0;i < length;i++) {
		cout << a[i] << endl;
	}
}

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
