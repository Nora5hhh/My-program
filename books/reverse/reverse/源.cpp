#include<iostream>
using namespace std;

//��������ṹ
struct ListNode
{
	char val;
	ListNode* next;
	ListNode(char x):val(x),next(NULL) {}
};

//�������Ӻõ�����
ListNode* CreatList(ListNode* p,int n)
{
	//����ͷָ��
	ListNode* L = p;
	char x;
	cout << "������" << n << "����";
	for(int i=1;i<=n;i++)
	{
		cout << endl << "�������" << i << "������";
		cin >> x;
		ListNode* newNode = new ListNode(x);
		p->next = newNode;
		p = newNode;
	}
	return L;
}

//������ת
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
	//����ͷָ���Ԫ��
	p = p->next;
	for (int i = 1; i <= n + 1; i++)
	{
		cout << p->val << " ";
		p = p->next;
	}

}