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
// undo lại sau này