#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

//��������
ListNode* CreatList(ListNode* p, int n) {
	ListNode* L = p;        //����ͷָ��
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

//��������λ�ò���Ԫ��
ListNode* ListInsert(ListNode* p, int i) {
	cout << "������Ԫ��ֵΪ��";
	int x;
	cin >> x;
	//ͷָ��
	ListNode* L = p;
	for (int t = 1; t < i; t++)
	{
		//�ҵ������λ��
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
	//����ͷָ���Ԫ��
	p = p->next;
	for (int i = 1; i <= n + 1; i++)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
