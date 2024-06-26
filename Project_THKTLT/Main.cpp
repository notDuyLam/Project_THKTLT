﻿#include "Functions.h"

int main()
{
	REF head = NULL;
	REF tail = NULL;
	// Khởi tạo danh sách liên kết
	stack undo;
	stack redo;
	// Tạo 2 stack undo và redo
	Init(undo);
	Init(redo);
	// Khởi tạo cho 2 stack trên
	file.open("input.txt", ios::in);
	if (file.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return 0;
	}
	int temp = 0;
	while (!file.eof())
	{
		file >> temp;
		ThemVaoCuoi(head, tail, temp);
	}
	file.close();
	string command; // Chứa lệnh người dùng nhập vào
	while (true)
	{
		cout << "LIST PROCESSING: ";
		XuatDanhSach(head);
		cout << endl;
		cout << "Command > ";
		getline(cin, command);
		if (command.substr(0, 6) == "delete") // Kiểm tra có phải lệnh là delete không
		{
			XuLiXoa(undo, head, tail, command);
			cout << endl;
		}
		else if (command.substr(0, 6) == "insert") // Kiểm tra có phải lệnh là insert không
		{
			XuLiThem(undo, head, tail, command);
			cout << endl;
		}
		else if (command == "undo") // Kiểm tra có phải lệnh là undo không
		{
			XuLiUndo(undo, redo, head, tail);
			cout << endl;
		}
		else if (command == "redo") // Kiểm tra có phải lệnh là redo không
		{
			XuLiRedo(undo, redo, head, tail);
			cout << endl;
		}
		else if (command == "save") // Kiểm tra có phải lệnh là saved không
		{
			Save(head);
		}
		else if (command == "reset") // Kiểm tra có phải lệnh là reset không
		{
			Reset(undo, redo, head, tail);
			cout << endl;
		}
		else if (command == "sxtang") // Kiểm tra có phải lệnh là sxtang (sắp xếp tăng dần) không
		{
			SapXepTang(undo, head);
		}
		else if (command == "sxgiam") // Kiểm tra có phải lệnh là sxgiam (sắp xếp giảm dần) không
		{
			SapXepGiam(undo, head);
		}
		else if (command.substr(0, 6) == "update") // Kiểm tra có phải lệnh là update khong
		{
			XuLiUpdate(undo, head, tail, command);
			cout << endl;
		}
		else if (command.substr(0, 8) == "xoatrung") // Kiểm tra có phải lệnh là isort (viết tắt cho decrease sort là sắp xếp giảm dần) không
		{
			XuLiXoaTrung(undo, head, tail, command);
			cout << endl;
		}
		else if (command == "quit") // Kiểm tra có phải lệnh là quit không
		{
			Quit(head);
			break;
		}
		else
		{
			cout << "Command not found..." << endl;
		}
	}
	return 0;
}