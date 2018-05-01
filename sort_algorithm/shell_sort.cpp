#include<iostream>
using namespace std;
void array_output(int a[],int n);
void shell_sort(int a[], int n);

//测试
int main() {
	int arr[6] = { 1,7,3,9,5,6 };
	shell_sort(arr, 6);
	array_output(arr, 6);
	system("pause");
	return 0;
}

//希尔排序（升序）
void shell_sort(int a[], int n) {
	int temp;
	int i;
	for (int distance = n / 2;distance > 0;distance = distance / 2) {  //distance代表排序间隔，下面代码是插入排序
		for (int p = distance;p < n;p = p + distance) {
			temp = a[p];
			for (i = p;i >= 0 & a[i - distance] > temp;i = i - distance) {
				a[i] = a[i - distance];
			}
			a[i] = temp;
		}
	}
}

//数组输出
void array_output(int a[],int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << ' ';
	}
}
