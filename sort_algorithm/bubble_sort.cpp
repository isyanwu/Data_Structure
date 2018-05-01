#include<iostream>
using namespace std;
void array_output(int a[],int n);
void bubble_sort(int a[],int n);

//测试
int main() {
	int a[6] = { 1,7,3,9,5,6 };
	bubble_sort(a, 6);
	array_output(a, 6);
	system("pause");
	return 0;
}

//冒泡排序（升序）
void bubble_sort(int a[], int n) {
	int temp;
	int flag = 0;
	for (int p = n - 1;p >= 0;p--) {
		for (int i = 0;i < p;i++) {	//一次冒泡过程
			if (a[i] > a[i + 1]) {
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;//flag==0代表一次冒泡过程中没有数据的交换
	}
}

//输出数组
void array_output(int a[],int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << ' ';
	}
}

