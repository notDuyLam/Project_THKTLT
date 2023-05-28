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

void XuLiXoa(stack& s, REF& head, REF& tail, string command)
{
	string temp;
	string reverse; // Biến này để chứa lệnh đảo ngược với command người dùng đưa vào
	int r_pos = 0;
	int r_val = 0;
	// 2 biến này chứa giá trị r_pos, r_val để lát nữa đưa vô biến reverse và push vào stack undo hoặc redo
	temp = command.substr(7, command.size() - 7); 
	// Do lệnh delete pos ta chỉ cần lấy duy nhất giá trị pos nên ta lấy chuỗi con từ 7 (vị trí đầu tiên sau khoảng trắng)
	// giữa delete và pos, ta lấy số lượng kí tự là từ vị trí của kí tự cuối chuỗi trừ đi 7
	int pos = stoi(temp);
	r_pos = pos;
	r_val = LayGiaTriTaiViTri(head, pos);
	XoaTaiViTri(head, tail, pos);
	reverse = "insert " + to_string(r_pos) + " " + to_string(r_val);
	Push(s, reverse);
}

void XuLiThem(stack& s, REF& head, REF& tail, string command)
{
	string reverse;
	string temp;
	int r_pos = 0;
	// biến này chứa giá trị r_pos, để lát nữa đưa vô biến reverse và push vào stack undo hoặc redo
	int pos = 0, val = 0;
	int vitrikhoangtrang = 0;
	for (int i = 7;; i++)
	{
		if (i == command.size() - 1)
		{
			temp = command.substr(vitrikhoangtrang + 1, i);
			val = stoi(temp);
			break;
		}
		else if (vitrikhoangtrang == 0)
		{
			if (command[i + 1] == ' ')
			{
				temp = command.substr(7, i - 7 + 1);
				pos = stoi(temp);
				r_pos = pos;
				vitrikhoangtrang = i + 1;
			}
			else
				continue;
		}
	}
	reverse = "delete " + to_string(r_pos);
	Push(s, reverse);
	ThemVaoTaiViTri(head, tail, pos, val);
}

void XuLiUndo(stack& undo, stack& redo, REF& head, REF& tail)
{
	string command = Pop(undo);
	if (command.substr(0, 6) == "delete")
	{
		XuLiXoa(redo, head, tail, command);
	}
	else if (command.substr(0, 6) == "insert")
	{
		XuLiThem(redo, head, tail, command);
	}
}

void XuLiRedo(stack& undo, stack& redo, REF& head, REF& tail)
{
	string command = Pop(redo);
	if (command.substr(0, 6) == "delete")
	{
		XuLiXoa(undo, head, tail, command);
	}
	else if (command.substr(0, 6) == "insert")
	{
		XuLiThem(undo, head, tail, command);
	}
}
void Saved(REF head)
{
	file.open("output.txt", ios::out);
	if (file.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	REF p;
	for (p = head; p; p = p->next)
	{
		file << p->key << " ";
	}
	file.close();
	cout << "Numbers have been stored" << endl;
}
void Reset(stack& undo, stack& redo, REF& head, REF& tail)
{
	REF q = head;
	while (q != NULL)
	{
		REF next = q->next;
		delete q;
		q = next;
	}
	head = NULL;
	tail = NULL;
	Init(undo);
	Init(redo);
	system("cls");
	file.open("input.txt", ios::in);
	if (file.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	int temp = 0;
	while (!file.eof())
	{
		file >> temp;
		ThemVaoCuoi(head, tail, temp);
	}
	file.close();
}
void Quit(REF& head) {
	file.open("output.txt", ios::out);
	if (file.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	REF p;
	for (p = head; p; p = p->next)
	{
		file << p->key << " ";
	}
	file.close();
	REF temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}