#include<iostream>
using namespace std;
void array_output(int a[],int n);
void bubble_sort(int a[],int n);
void insert_sort(int a[], int n);
void shell_sort(int a[], int n);
//测试
int main() {
	int a[6] = { 1,7,3,9,5,6 };
	//bubble_sort(a, 6);
	//insert_sort(a, 6);
	shell_sort(a, 6);
	array_output(a, 6);
	system("pause");
	return 0;
}

//冒泡排序
void bubble_sort(int a[], int n) {
	int temp;
	int flag = 0;
	for (int p = n - 1;p >= 0;p--) {
		for (int i = 0;i < p;i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

//输出数组
void array_output(int a[],int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << ' ';
	}
}

