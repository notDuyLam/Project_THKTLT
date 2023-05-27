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
void XoaTaiViTri(REF& head, REF& tail, int pos)