#include "Functions.h"

int main()
{
	REF head = NULL;
	REF tail = NULL;
	stack s;
	Init(s);
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
	string command;
	string temp1;
	string reverse; // Biến này chứa command đảo ngược với command của người dùng, mục đích để phục vụ cho việc undo và redo
	while (command != "quit")
	{
		cout << "LIST PROCESSING: ";
		XuatDanhSach(head);
		cout << endl;
		cout << "Command > ";
		getline(cin, command);
		cout << endl;
		if (command.substr(0, 6) == "delete")
		{
			int r_pos = 0;
			int r_val = 0;
			for (int i = 7;; i++)
			{
				if (i == command.size() - 1)
				{
					temp1 = command.substr(7, i);
					int pos = stoi(temp1);
					r_pos = pos;
					r_val = LayGiaTriTaiViTri(head, pos);
					XoaTaiViTri(head, tail, pos);
					reverse = "insert " + to_string(r_pos) + " " + to_string(r_val);
					Push(s, reverse);
					break;
				}
			}
			continue;
		}
		if (command.substr(0, 6) == "insert")
		{
			int r_pos = 0;
			int pos = 0, val = 0;
			int vitrikhoangtrang = 0;
			for (int i = 7;; i++)
			{
				if (i == command.size() - 1)
				{
					temp1 = command.substr(vitrikhoangtrang + 1, i);
					val = stoi(temp1);
					break;
				}
				else if (vitrikhoangtrang == 0)
				{
					if (command[i + 1] == ' ')
					{
						temp1 = command.substr(7, i - 7 + 1);
						pos = stoi(temp1);
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
		if (command == "undo")
		{

		}
	}
	return 0;
}