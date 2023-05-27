#include "Functions.h"

REF KhoiTaoNode(int k)
{
	REF p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		exit(0);
	}
	p->next = NULL;
	p->key = k;
	return p;
}

void ThemVaoDau(REF& head, REF& tail, int k)
{
	REF p = KhoiTaoNode(k);
	if (head == NULL)
		head = tail = p;
	else
	{
		p->next = head;
		head = p;
	}
}

void XuatDanhSach(REF head)
{
	REF p;
	if (head == NULL)
		cout << "Danh sach rong" << endl;
	else
		for (p = head; p; p = p->next)
			cout << p->key << endl;
}

void ThemVaoCuoi(REF& head, REF& tail, int k)
{
	REF p = KhoiTaoNode(k);
	if (head == NULL)
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
}

int length(REF head)
{
	REF p;
	int count = 0;
	for (p = head; p; p = p->next)
	{
		count++;
	}
	return count;
}

void ThemVaoSau(REF q, int k)
{
	REF p;
	p = new node;
	if (p == NULL)
	{
		cout << "Loi khong du bo nho " << endl;
		return;
	}
	*p = *q;
	q->next = p;
	q->key = k;
}

void ThemVaoTaiViTri(REF& head, REF& tail, int pos, int k)
{

	int n, i;
	REF q;
	n = length(head);
	if ((pos < 0) || (pos > n))
	{
		cout << "Vi tri chen khong phu hop" << endl;
		return;
	}
	if (pos == 0)
		ThemVaoDau(head, tail, k);
	else
		if (pos == n)
			ThemVaoCuoi(head, tail, k);
		else
		{
			for (i = 0, q = head; i < pos - 1; i++, q = q->next);
			ThemVaoSau(q, k);
			if (tail->next)
				tail = tail->next;
		}
}

