#include<iostream>
using namespace std;
void array_output(int a[],int n);
void insert_sort(int a[], int n);

//测试
int main() {
	int arr[6] = { 1,7,3,9,5,6 };
	insert_sort(arr, 6);
	array_output(arr, 6);
	system("pause");
	return 0;
}

//插入排序（升序）
void insert_sort(int a[], int n) {
	int temp;
	int i;
	for (int p = 1;p < n;p++) {
		temp = a[p];  //取元素
		for ( i = p;i >= 0 & a[i - 1] > temp;i--) {
			a[i] = a[i - 1];  //元素后移
		}
		a[i] = temp;  //放置元素
	}
}

//输出数组
void array_output(int a[],int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << ' ';
	}
}

