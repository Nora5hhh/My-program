#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

//创建链表
ListNode* CreatList(ListNode* p, int n) {
	ListNode* L = p;        //创建头指针
	int x;
	for (int i = 1; i <= n; i++)
	{
		cout << "Please enter the element:";
		cin >> x;
		ListNode* newNode = new ListNode(x);
		p->next = newNode;
		p = newNode;
	}
	return L;
}

//在想插入的位置插入元素
ListNode* ListInsert(ListNode* p, int i) {
	cout << "想插入的元素值为：";
	int x;
	cin >> x;
	//头指针
	ListNode* L = p;
	for (int t = 1; t < i; t++)
	{
		//找到插入的位置
		p = p->next;
	}
	ListNode* newNode = new ListNode(x);
	newNode->next = p->next;
	p->next = newNode;
	return L;
}

int main()
{
	ListNode* p = new ListNode(0);
	cout << "Please enter the size of the list:";
	int n;
	cin >> n;
	p = CreatList(p, n);
	cin.clear();
	cin.ignore();
	int pos;
	cout << "Please enter the position:";
	cin >> pos;
	p = ListInsert(p, pos);
	//跳过头指针的元素
	p = p->next;
	for (int i = 1; i <= n + 1; i++)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
