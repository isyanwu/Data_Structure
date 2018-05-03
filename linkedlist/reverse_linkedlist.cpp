#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

node * creat_linkedlist();//创建一个空链表
node * append_data(node *head, int data);//在链表末端添加数据
node *reverse_linkedlist(node *head);//反转链表
void print_linkedlist(node *head);//打印链表

int main() {
	node *head = creat_linkedlist();
	head=append_data(head,5);
	head = append_data(head, 6);
	head = append_data(head, 7);
	head = append_data(head, 8);
	head = reverse_linkedlist(head);
	print_linkedlist(head);
	system("pause");
	return 0;
}

node * creat_linkedlist() {
	node *head = NULL;
	return head;
}

//在链表末端添加数据
node *append_data(node *head,int data) {
	node *new_node;
	new_node = new node;//创建新节点，并赋值
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
		return head;
	}
	node *link = head;
	while (link->next!=NULL) {//遍历链表
		link = link->next;
	}
	link->next = new_node;
	return head;
}

//反转链表
node *reverse_linkedlist(node *head) {
	if (head == NULL) {
		return head;
	}
	if(head->next == NULL) {
		return head;
	}
	node *pre = NULL;  //指向前一个节点
	node *last = head; //指向后一个节点
	while (head != NULL) {
		last = head->next;
		head->next = pre;
		pre = head;
		head = last;
	}
	delete last;
	delete head;
	return pre;
}

//打印链表
void print_linkedlist(node *head) {
	node *p = head;
	if (p == NULL) {
		cout << "链表为空" << endl;
	}
	while (p != NULL) {
		cout << p->data << endl;
		p =p->next;
	}
}
