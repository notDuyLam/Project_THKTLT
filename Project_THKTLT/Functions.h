#pragma once
#include "Header.h"

REF KhoiTaoNode(int k);
void ThemVaoDau(REF& head, REF& tail, int k);
void XuatDanhSach(REF head);
void ThemVaoCuoi(REF& head, REF& tail, int k);
void ThemVaoSau(REF q, int k);
void ThemVaoTaiViTri(REF& head, REF& tail, int pos, int k);
void XoaDau(REF& head, REF& tail);
void XoaCuoi(REF& head, REF& tail);
void XoaGiua(REF q);
void XoaTaiViTri(REF& head, REF& tail, int pos);
void Init(stack& s);
bool IsEmpty(stack s);
bool IsFull(stack s);
void Push(stack& s, string x);
string Pop(stack& s);
int LayGiaTriTaiViTri(REF head, int pos); 
// Hàm này dùng để lấy giá trị tại vị trí pos trong DSLK, mục đích để lưu lại số sau khi xóa trong danh sách và dùng số đó để 
// s lại sau này
void XuLiXoa(stack& s, REF& head, REF& tail, string command);
// Lấy giá trị pos từ lệnh người dùng nhập vào và xóa, có một tham chiếu là stack s, tùy trường hợp mà ta truyền vào đó là undo hoặc
// redo
void XuLiThem(stack& s, REF& head, REF& tail, string command);
// Lấy giá trị pos val từ lệnh người dùng nhập vào và thêm val tại vị trí pos, tham chiếu stack s tương tự trên
void XuLiUndo(stack& undo, stack& redo, REF& head, REF& tail);
void XuLiRedo(stack& undo, stack& redo, REF& head, REF& tail);
// Các hàm này tương tự nhau có truyền vào 2 tham chiếu là stack undo và redo để sau khi undo thì đưa lại vào redo và ngược
// lại
void Saved(REF head);
//
void Reset(stack& undo, stack& redo, REF& head, REF& tail);
void Quit(REF& head);