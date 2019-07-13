#include<iostream>
using namespace std;

//创建链表结构
struct ListNode
{
	char val;
	ListNode* next;
	ListNode(char x):val(x),next(NULL) {}
};

//创建连接好的链表
ListNode* CreatList(ListNode* p,int n)
{
	//创建头指针
	ListNode* L = p;
	char x;
	cout << "请输入" << n << "个数";
	for(int i=1;i<=n;i++)
	{
		cout << endl << "请输入第" << i << "个数：";
		cin >> x;
		ListNode* newNode = new ListNode(x);
		p->next = newNode;
		p = newNode;
	}
	return L;
}

//将链表反转
ListNode* ReverseNode(ListNode* L) {
	ListNode* Revers_L = new ListNode(' ');
	ListNode* head;
	head = Revers_L;
	while (L->next!=NULL)
	{
		ListNode* newNode = new ListNode(L->next->val);
		newNode->next = Revers_L->next;
		Revers_L->next = newNode;
		L = L->next;
	}
	return head;
}

int main()
{
	ListNode* p = new ListNode(' ');
	cout << "Please enter the size of the list:";
	int n;
	cin >> n;
	p = CreatList(p, n);
	cin.clear();
	cin.ignore();
	p = ReverseNode(p);
	//跳过头指针的元素
	p = p->next;
	for (int i = 1; i <= n + 1; i++)
	{
		cout << p->val << " ";
		p = p->next;
	}

}