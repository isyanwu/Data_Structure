#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
};

node * creat_linkedlist();//创建一个空链表
node * append_data(node *head, int data);//在链表末端添加数据
int length(node *head);//返回链表长度
node *find_Kth(node *head, int k);//查找第k个节点，返回对应的地址（未找到则返回NULL）
node *insert(node *head, int k, int data);//在链表的第k个位置插入一个节点
node *delete_node(node *head, int k);//删除链表的第k个节点
void print_linkedlist(node *head);//打印链表

int main() {
	node *head = creat_linkedlist();
	head=append_data(head,5);
	head = append_data(head, 6);
	head= insert(head, 2,7);
	head = delete_node(head, 3);
	print_linkedlist(head);
	system("pause");
	return 0;
}



//创建一个空链表,返回头指针
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

//返回链表长度
int length(node *head) {
	node *link = head;
	int len = 0;
	while (link != NULL) {
		link = link->next;
		len++;
	}
	return len;
}

//查找第k个节点，返回对应的地址（未找到则返回NULL）
node *find_Kth(node *head, int k) {
	node *link = head;
	int i = 1;
	while (link != NULL & i < k) {
		link = link->next;
		i++;
	}
	if (i == k) 
		return link;
	else 
		return NULL;
}

//在链表的第k个位置插入一个节点
node *insert(node *head, int k, int data) {
	int len = length(head);
	if (k > len) {
		cout << "链表长度小于插入位置" << endl;
		return NULL;
	}
	if (k == 1) {
		node *new_node;
		new_node = new node;
		new_node->data = data;
		new_node->next = head;
		head = new_node;
		return head;
	}
	node *p = find_Kth(head, k - 1);
	if (p == NULL) {
		cout << "参数k错误" << endl;
		delete p;
		return NULL;
	}
	else {
		node *new_node = new node;
		new_node->data = data;
		new_node->next = p->next;
		p->next = new_node;
		return head;
	}
		
}

//删除链表的第k个节点
node *delete_node(node *head, int k) {
	if (head == NULL) {
		return NULL;
	}
	if (k == 1) {
		node *p = head;
		head = head->next;
		delete p;
		return head;
	}
	node *p = find_Kth(head, k - 1);
	if (p == NULL) {
		cout << "第K-1个节点不存在" << endl;
		return NULL;
	}
	else if (p ->next == NULL) {
		cout << "第K个节点不存在" << endl;
		return NULL;
	}
	else {
		node *temp = p->next;
		p->next = temp->next;
		delete temp;
		return head;
	}
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
