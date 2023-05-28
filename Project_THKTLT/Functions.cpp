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
			cout << p->key << " ";
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
	if ((pos < 0) || (pos > n + 1))
	{
		cout << "Vi tri chen khong phu hop" << endl;
		return;
	}
	if (pos == 0)
		ThemVaoDau(head, tail, k);
	else
		if (pos == n + 1)
			ThemVaoCuoi(head, tail, k);
		else
		{
			for (i = 0, q = head; i < pos - 1; i++, q = q->next);
			ThemVaoSau(q, k);
			if (tail->next)
				tail = tail->next;
		}
}

void XoaDau(REF& head, REF& tail)
{
	REF q;
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		q = head;
		head = head->next;
		free(q);
	}
}

void XoaCuoi(REF& head, REF& tail)
{
	REF q;
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		for (q = head; q->next != tail; q = q->next);
		free(tail);
		tail = q;
		q->next = NULL;
	}
}

void XoaGiua(REF q) {
	REF r;
	r = q->next;
	*q = *r;
	free(r);
}

void XoaTaiViTri(REF &head,REF &tail, int pos)
{
	int n, i;
	REF q;
	n = length(head);
	if (pos < 0 || pos >= n) {
		cout << "Vi tri xoa khong phu hop: " << endl;
		return;
	}
	if (pos == 0)
		XoaDau(head, tail);
	else
		if (pos == n - 1)
			XoaCuoi(head, tail);
		else {
			for (i = 1, q = head; i < pos; i++, q = q->next);
			if (q->next == tail)
				tail = q;
			XoaGiua(q);
		}
}

void Init(stack& s)
{
	s.top = -1;
}

bool IsEmpty(stack s)
{
	if (s.top == -1) {
		return true;
	}
	return false;
}

bool IsFull(stack s)
{
	if (s.top == MAX - 1)
	{
		return true;
	}
	return false;
}

void Push(stack& s, string x)
{
	if (!IsFull(s))
	{
		s.top++;
		s.A[s.top] = x;
	}
}

string Pop(stack& s)
{
	string temp;
	if (!IsEmpty(s))
	{
		temp = s.A[s.top];
		s.top--;
		return temp;
	}
}

int LayGiaTriTaiViTri(REF head, int pos) 
{
	REF q = NULL;
	int i;
	for (i = 1, q = head; i < pos; i++, q = q->next);
	return q->key;
}