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
		cout << "Vi tri xoa khong phu hop" << endl;
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

void destroyList(REF& head)
{
	REF p;
	while (head)
	{
		p = head;
		head = head->next;
		free(p);
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
	int sokhoangtrang = 0;
	for (int i = 6; i < command.size(); i++) // Vòng lặp này kiểm tra người dùng có nhập đúng định dạng delete pos hay không
	{
		if (command[i] == ' ') // Nếu có bất kì khoảng trắng nào trừ khoàng trắng giữa lệnh delete và giá trị pos thì tức là người dùng nhập sai
		{
			sokhoangtrang++;
			if (sokhoangtrang >= 2)
			{
				cout << "Nhap sai" << endl;
				return;
			}
		}
		else if (command[i] < 48 || command[i] > 57) // Nếu có một kí tự khác số trong pos tức là người dùng nhập sai
		{
			cout << "Nhap sai" << endl;
			return;
		}
	}
	if (sokhoangtrang == 0)
	{
		cout << "Nhap sai" << endl;
		return;
	}
	// Nếu qua được vòng lặp trên tức là người dùng nhập đúng định dạng, từ ở dưới bắt đầu xử lí
	temp = command.substr(7, command.size() - 7); 
	// Do lệnh delete pos ta chỉ cần lấy duy nhất giá trị pos nên ta lấy chuỗi con từ 7 (vị trí đầu tiên sau khoảng trắng)
	// giữa delete và pos, ta lấy số lượng kí tự là từ vị trí của kí tự cuối chuỗi trừ đi 7
	int pos = stoi(temp);
	r_pos = pos;
	int n = length(head);
	if (pos < 0 || pos >= n) {
		cout << "Vi tri xoa khong phu hop" << endl;
		return;
	}
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
	int sokhoangtrang = 0;
	for (int i = 7; i < command.size(); i++)
	{
		if (command[i] == ' ') // Nếu có bất kì khoảng trắng nào trừ 2 khoàng trắng giữa insert và pos, giữa pos và val thì tức là người dùng nhập sai
		{
			sokhoangtrang++;
			if (sokhoangtrang >= 2)
			{
				cout << "Nhap sai" << endl;
				return;
			}
		}
		else if (command[i] < 48 || command[i] > 57) // Nếu có một kí tự khác số trong pos hoặc val tức là người dùng nhập sai
		{
			cout << "Nhap sai" << endl;
			return;
		}
	}
	if (sokhoangtrang == 0) // Ngược lại nếu như chỉ có 1 khoảng trắng giữa insert và pos thì là nhập sai
	{
		cout << "Nhap sai" << endl;
		return;
	}
	// Nếu qua được vòng lặp trên tức là người dùng nhập đúng định dạng, từ ở dưới bắt đầu xử lí
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
	if (IsEmpty(undo))
		return;
	string command = Pop(undo);
	if (command.substr(0, 6) == "delete")
	{
		XuLiXoa(redo, head, tail, command);
	}
	else if (command.substr(0, 6) == "insert")
	{
		XuLiThem(redo, head, tail, command);
	}
	else if (command.substr(0, 6) == "update")
	{
		XuLiUpdate(redo, head, tail, command);
	}
	else // Cho các trường hợp sắp xếp tăng, giảm, xóa trùng thì sẽ đi vào đây
	{
		if(command.substr(0, 2) == "sg" || command.substr(0, 2) == "st")
		{
			string tempcommand = command.substr(3, command.size() - 3);
			destroyList(head);
			head = NULL;
			tail = NULL;
			istringstream iss(tempcommand);
			int number;
			while (iss >> number) {
				ThemVaoCuoi(head, tail, number);
			}
			string reverse;
			if (command.substr(0, 2) == "sg")
			{
				reverse = "sxgiam";
				Push(redo, reverse);
			}
			else
			{
				reverse = "sxtang";
				Push(redo, reverse);
			}
		}
		else
		{
			string tempcommand = command.substr(3, command.size() - 3);
			destroyList(head);
			head = NULL;
			tail = NULL;
			istringstream iss(tempcommand);
			int number;
			int xtval;
			bool firstNumber = true;

			while (iss >> number) {
				if (firstNumber) {
					xtval = number; // Lưu số đầu tiên vào biến xtval
					firstNumber = false;
				}
				else {
					ThemVaoCuoi(head, tail, number); // Đưa các số còn lại vào danh sách liên kết
				}
			}
			string reverse;
			reverse = "xoatrung " + to_string(xtval);
			Push(redo, reverse);
		}
	}
}

void XuLiRedo(stack& undo, stack& redo, REF& head, REF& tail)
{
	if (IsEmpty(redo))
		return;
	string command = Pop(redo);
	if (command.substr(0, 6) == "delete")
	{
		XuLiXoa(undo, head, tail, command);
	}
	else if (command.substr(0, 6) == "insert")
	{
		XuLiThem(undo, head, tail, command);
	}
	else if (command.substr(0, 6) == "update")
	{
		XuLiUpdate(undo, head, tail, command);
	}
	else if (command == "sxtang") // Kiểm tra có phải lệnh là sxtang (sắp xếp tăng dần) không
	{
		SapXepTang(undo, head);
	}
	else if (command == "sxgiam") // Kiểm tra có phải lệnh là sxgiam (sắp xếp giảm dần) không
	{
		SapXepGiam(undo, head);
	}
	else if (command.substr(0, 8) == "xoatrung") 
	{
		XuLiXoaTrung(undo, head, tail, command);
		cout << endl;
	}
}

void Save(REF head)
{
	// Kiểm tra file mở được hay không
	file.open("output.txt", ios::out);
	if (file.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	// Tạo con trỏ p duyệt qua danh sách và ghi vào file
	REF p;
	for (p = head; p; p = p->next)
	{
		file << p->key << " ";
	}
	file.close();
	cout << "Numbers have been stored." << endl;
}

void Reset(stack& undo, stack& redo, REF& head, REF& tail)
{
	// Tạo con trỏ q duyệt qua danh sách và xóa 
	REF q = head;
	while (q != NULL)
	{
		REF next = q->next;
		delete q;
		q = next;
	}
	// Tạo danh sách liên kết rỗng 
	head = NULL;
	tail = NULL;
	// Tạo lại ngăn xếp mới 
	Init(undo);
	Init(redo);
	// Mở file để đọc dữ liệu từ input
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
	// Lưu danh sách liên kết 
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
	// Tạo con trỏ temp để xóa và giải phóng danh sách liên kết 
	REF temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void SapXepTang(stack& undo, REF& head)
{
	if (head == NULL || head->next == NULL)
		return;
	REF q = head;
	REF a = NULL;
	int temp;
	string result;
	REF current = head;
	while (current != NULL) {
		result += to_string(current->key);
		if (current->next != NULL) {
			result += " ";
		}
		current = current->next;
	}
	string reverse;
	reverse = "st " + result;
	Push(undo, reverse);
	while (q != NULL)
	{
		a = q->next;

		while (a != NULL)
		{
			if (q->key > a->key)
			{
				temp = q->key;
				q->key = a->key;
				a->key = temp;
			}
			a = a->next;
		}
		q = q->next;
	}
	cout << "Danh sach da duoc sap xep tang dan" << endl;

}

void SapXepGiam(stack& undo, REF& head)
{
	if (head == NULL || head->next == NULL)
		return;

	REF q = head;
	REF a = NULL;
	int temp;
	string result;
	REF current = head;
	while (current != NULL) {
		result += to_string(current->key);
		if (current->next != NULL) {
			result += " ";
		}
		current = current->next;
	}
	string reverse;
	reverse = "st " + result;
	Push(undo, reverse);
	while (q != NULL)
	{
		a = q->next;

		while (a != NULL)
		{
			if (q->key < a->key)
			{
				temp = q->key;
				q->key = a->key;
				a->key = temp;
			}
			a = a->next;
		}
		q = q->next;
	}
	cout << "Danh sach da duoc sap xep giam dan" << endl;

}

void Update(REF& head, REF& tail, int pos, int k)
{
	int n, i;
	REF q;
	n = length(head);
	if ((pos < 0) || (pos > n))
	{
		cout << "Vi tri cap nhat khong phu hop" << endl;
		return;
	}
	if (pos == 0)
		head->key = k;
	else
		if (pos == n)
			tail->key = k;
		else
		{
			for (i = 0, q = head; i < pos - 1; i++, q = q->next);
			q->key = k;
		}
}

void XuLiUpdate(stack& s, REF& head, REF& tail, string command)
{
	string reverse;
	string temp;
	int r_pos = 0;
	int r_val = 0;
	// biến này chứa giá trị r_pos và r_val, để lát nữa đưa vô biến reverse và push vào stack undo hoặc redo
	int pos = 0, val = 0;
	int vitrikhoangtrang = 0;
	int sokhoangtrang = 0;
	for (int i = 7; i < command.size(); i++)
	{
		if (command[i] == ' ') // Nếu có bất kì khoảng trắng nào trừ 2 khoàng trắng giữa update và pos, giữa pos và val thì tức là người dùng nhập sai
		{
			sokhoangtrang++;
			if (sokhoangtrang >= 2)
			{
				cout << "Nhap sai" << endl;
				return;
			}
		}
		else if (command[i] < 48 || command[i] > 57) // Nếu có một kí tự khác số trong pos hoặc val tức là người dùng nhập sai
		{
			cout << "Nhap sai" << endl;
			return;
		}
	}
	if (sokhoangtrang == 0) // Ngược lại nếu như chỉ có 1 khoảng trắng giữa update và pos thì là nhập sai
	{
		cout << "Nhap sai" << endl;
		return;
	}
	// Nếu qua được vòng lặp trên tức là người dùng nhập đúng định dạng, từ ở dưới bắt đầu xử lí
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
	int n = length(head);
	if ((pos < 0) || (pos > n))
	{
		cout << "Vi tri cap nhat khong phu hop" << endl;
		return;
	}
	r_val = LayGiaTriTaiViTri(head, pos);
	reverse = "update " + to_string(r_pos) + " " + to_string(r_val);
	Push(s, reverse);
	Update(head, tail, pos, val);
}

void XoaTrung(REF& head, REF& tail, int x)
{
	REF p = NULL;
	bool first = true;
	bool hoanthanh = false;
	for (p = head;p; p = p->next)
	{
		if (p->key == x)
		{
			if (first == false)
			{
				while (p->key == x)
				{
					if (p->next == tail)
					{
						XoaCuoi(head, tail);
						XoaCuoi(head, tail);
						hoanthanh = true;
						break;
					}
					else
						XoaGiua(p);
				}
			}
			else
				first = false;
		}
		if (hoanthanh == true)
			break;
	}
}

void XuLiXoaTrung(stack& undo, REF& head, REF& tail, string command)
{
	string temp;
	string reverse;
	int sokhoangtrang = 0;
	for (int i = 8; i < command.size(); i++) // Vòng lặp này kiểm tra người dùng có nhập đúng định dạng xoatrung val hay không
	{
		if (command[i] == ' ') // Nếu có bất kì khoảng trắng nào trừ khoàng trắng giữa lệnh delete và giá trị pos thì tức là người dùng nhập sai
		{
			sokhoangtrang++;
			if (sokhoangtrang >= 2)
			{
				cout << "Nhap sai" << endl;
				return;
			}
		}
		else if (command[i] < 48 || command[i] > 57) // Nếu có một kí tự khác số trong pos tức là người dùng nhập sai
		{
			cout << "Nhap sai" << endl;
			return;
		}
	}
	if (sokhoangtrang == 0)
	{
		cout << "Nhap sai" << endl;
		return;
	}
	// Nếu qua được vòng lặp trên tức là người dùng nhập đúng định dạng, từ ở dưới bắt đầu xử lí
	temp = command.substr(9, command.size() - 9);
	// Do lệnh delete pos ta chỉ cần lấy duy nhất giá trị pos nên ta lấy chuỗi con từ 7 (vị trí đầu tiên sau khoảng trắng)
	// giữa delete và pos, ta lấy số lượng kí tự là từ vị trí của kí tự cuối chuỗi trừ đi 7
	int val = stoi(temp);
	int n = length(head);
	string result;
	REF current = head;
	while (current != NULL) {
		result += to_string(current->key);
		if (current->next != NULL) {
			result += " ";
		}
		current = current->next;
	}
	reverse = "xt " + to_string(val) + " " + result;
	Push(undo, reverse);
	XoaTrung(head, tail, val);

}

