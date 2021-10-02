#pragma once
#include <iostream>
#include <stdio.h>
#include "mylib.h"
#include <conio.h>
#include "KhaiBao.h"

using namespace std;
char c = char(254);

void rectangle(int x, int y, int w, int h, int color);
void themSuaXoa(int x, int y);
void chuyenTrang(int x, int y);
void hightlight(int x, int y);
void rsRectangle(int x, int y, int w, int h, int color);
void giaoDienNhapSV(int x, int y, int w, int h, int color);
void clearMesseger(int x, int y, int w, int h);
string toUpCaps(string s);

void messeger(int x, int y, int w, int h, int color, string noidung, int delay) {
	rectangle(x, y, w, h, color);
	gotoxy(x + 3, y + 1); cout << noidung;
	Sleep(delay * 1000);
	clearMesseger(x, y, w, h);
}

void clearMesseger(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w+2; j++)
		{
			gotoxy(x + j, y + i); cout << " ";
		}
	}
}

void khungDangNhap(int x, int y, int w, int h) {
	SetColor(9);
	rectangle(x, y, w, h, 9);
	gotoxy(x + w / 2 - 2, y - 1); cout << "LOGIN" << endl;
	gotoxy(x + 3, y + 3); cout << "Ten Dang Nhap";
	gotoxy(x + 3, y + 6); cout << "Mat Khau";
	rectangle(x + 20, y + 2, w / 2, 3, 13);
	rectangle(x + 20, y + 5, w / 2, 3, 13);
	SetColor(2);
	rectangle(x + w / 2 - 6, y + h + 2, 12, 3, 13);
	gotoxy(x + w / 2 - 6 + 2, y + h + 3); cout << "Dang nhap";
	rectangle(x + w / 2 - 6, y + h + 6, 12, 3, 13);
	gotoxy(x + w / 2 - 6 + 2, y + h + 7); cout << "  Thoat";
	gotoxy(0, 30);
}

void menuGiangVien() {
	//ShowCursor(0);
	SetColor(13);
	gotoxy(43, 3); cout << "     " << c << c << c << c << "    " << c << c << c << c << c << c << c << "    " << c << c << c << c << "      " << c << "        " << c << "       " << c << "    " << c << "           " << c << c << c << c << "    " << c << c << c << c << c << c << c;
	gotoxy(43, 4); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "         " << c << "     " << c << "    " << c << " " << c << "        " << c << "            " << c;
	gotoxy(43, 5); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "          " << c << "   " << c << "    " << c << " " << c << " " << c << "       " << c << "    " << c << c << c << "     " << c;
	gotoxy(43, 6); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "           " << c << " " << c << "    " << c << "     " << c << "      " << c << "     " << c << "      " << c;
	gotoxy(43, 7); cout << "     " << c << c << c << c << "       " << c << "       " << c << c << c << c << "      " << c << c << c << c << c << "        " << c << "    " << c << "       " << c << "       " << c << c << c << " " << c << "      " << c;
	SetColor(10);
	gotoxy(72, 10);
	cout << "CHUONG TRINH THI TRAC NGHIEM" << endl;
	SetColor(12);
	gotoxy(65, 12); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 13);	cout << "+" << "         " << c << " 1: NHAP LOP                 +" << endl;
	gotoxy(65, 14);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 15); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 16);	cout << "+" << "         " << c << " 2: IN DANH SACH LOP         +" << endl;
	gotoxy(65, 17);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 18);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 19);	cout << "+" << "         " << c << " 3: NHAP SINH VIEN           +" << endl;
	gotoxy(65, 20);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 21);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 22);	cout << "+" << "         " << c << " 4: NHAP MON HOC	  	 +" << endl;
	gotoxy(65, 23);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 24);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 25);	cout << "+" << "         " << c << " 5: NHAP CAU HOI THI         +" << endl;
	gotoxy(65, 26);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 27);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 28);	cout << "+" << "         " << c << " 6: THI TRAC NGHIEM          +" << endl;
	gotoxy(65, 29); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 30);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 31);	cout << "+" << "         " << c << " 7: IN BANG DIEM             +" << endl;
	gotoxy(65, 32); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 33);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 34);	cout << "+" << "         " << c << " ESC: DANG XUAT              +" << endl;
	gotoxy(65, 35);	cout << "+---------------------------------------+" << endl;
	SetColor(10);
}

void menuSinhVien() {
	system("cls");
	SetColor(13);
	gotoxy(43, 4); cout << "     " << c << c << c << c << "    " << c << c << c << c << c << c << c << "    " << c << c << c << c << "      " << c << "        " << c << "       " << c << "    " << c << "           " << c << c << c << c << "    " << c << c << c << c << c << c << c;
	gotoxy(43, 5); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "         " << c << "     " << c << "    " << c << " " << c << "        " << c << "            " << c;
	gotoxy(43, 6); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "          " << c << "   " << c << "    " << c << " " << c << " " << c << "       " << c << "    " << c << c << c << "     " << c;
	gotoxy(43, 7); cout << "   " << c << "            " << c << "       " << c << "    " << c << "    " << c << "           " << c << " " << c << "    " << c << "     " << c << "      " << c << "     " << c << "      " << c;
	gotoxy(43, 8); cout << "     " << c << c << c << c << "       " << c << "       " << c << c << c << c << "      " << c << c << c << c << c << "        " << c << "    " << c << "       " << c << "       " << c << c << c << " " << c << "      " << c;
	SetColor(10);
	gotoxy(72, 12);
	cout << "CHUONG TRINH THI TRAC NGHIEM" << endl;
	SetColor(12);
	gotoxy(65, 14); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 15);	cout << "+" << "         " << c << " 1: VAO THI                  +" << endl;
	gotoxy(65, 16);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 17);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 18);	cout << "+" << "         " << c << " 2: IN DIEM THI              +" << endl;
	gotoxy(65, 19); cout << "+---------------------------------------+" << endl;
	gotoxy(65, 20);	cout << "+---------------------------------------+" << endl;
	gotoxy(65, 21);	cout << "+" << "         " << c << " ESC: DANG XUAT              +" << endl;
	gotoxy(65, 22);	cout << "+---------------------------------------+" << endl;
	SetColor(10);
}

void giaoDienNhapLop(int x, int y, int w, int h) {
	SetColor(9);
	gotoxy(x + 17, y - 1); cout << "NHAP THONG TIN LOP";
	gotoxy(x + 4, y + 3); cout << "Ma lop ";
	gotoxy(x + 4, y + 7); cout << "Ten lop ";
	rectangle(x + 15, y + 2, 25, 3, 13);
	rectangle(x + 15, y + 6, 25, 3, 13);
	SetColor(15);
	rectangle(x, y, w, h, 15);
	// Chuc nang
	rectangle(x + w / 3, y + h + 2, w / 3, 3, 13);
	gotoxy(x + w / 3 + 6, y + h + 3); cout << "Them";
	rectangle(x + w / 3, y + h + 5, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 6); cout << "Sua";
	rectangle(x + w / 3, y + h + 8, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 9); cout << "Xoa";
}

//void giaoDienChonSV(int x, int y, int w, int h) {
//	SetColor(9);
//	gotoxy(x + w / 2 - 6, y - 1); cout << "DANH SACH SINH VIEN";
//	gotoxy(x + 2, y + 1); cout << "STT";
//	gotoxy(x + (w - 5) / 4 + 3, y + 1); cout << "MA SINH VIEN";
//	gotoxy(x + (w - 5) * 3 / 4 + 3, y + 1); cout << "TEN SINH VIEN";
//	SetColor(15);
//	rectangle(x, y, w, h, 15);
//	for (int i = 0; i < h; i++)
//	{
//		gotoxy(x + 6, y + i); cout << char(186);
//		gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(186);
//		if (i == 0) {
//			gotoxy(x + 6, y + i); cout << char(203);
//			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(203);
//		}
//		if (i == 2) {
//			for (int j = 0; j < w; j++)
//			{
//				gotoxy(x + j, y + i);  cout << char(205);
//			}
//			gotoxy(x, y + i); cout << char(204);
//			gotoxy(x + w, y + i); cout << char(185);
//			gotoxy(x + 6, y + i); cout << char(206);
//			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(206);
//		}
//		if (i == h - 1) {
//			gotoxy(x + 6, y + i); cout << char(202);
//			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(202);
//		}
//	}
//	// Chuc nang
//	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
//	chuyenTrang(x + w / 2 - 21, 31);
//}

//void xoaBangChonSV(int x, int y, int w, int h) {
//	SetColor(15);
//	for (int i = 0; i < h - 4; i++)
//	{
//		gotoxy(x + 1, y + i + 3);
//		for (int j = 0; j < w - 3; j++)
//		{
//			SetBGColor(43);
//			cout << " ";
//			if (j == 4 || j == (w - 8) / 2 + 3) cout << char(186);
//		}
//	}
//}

void giaoDienDSLop(int x, int y, int w, int h) {
	SetColor(9);
	gotoxy(x + w / 2 - 6, y - 1); cout << "DANH SACH LOP";
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + (w - 5) / 4 + 3, y + 1); cout << "MA LOP";
	gotoxy(x + (w - 5) * 3 / 4 + 3, y + 1); cout << "TEN LOP";
	SetColor(15);
	rectangle(x, y, w, h, 15);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x + 6, y + i); cout << char(186);
		gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(186);
		if (i == 0) {
			gotoxy(x + 6, y + i); cout << char(203);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(203);
		}
		if (i == 2) {
			for (int j = 0; j < w; j++)
			{
				gotoxy(x + j, y + i);  cout << char(205);
			}
			gotoxy(x, y + i); cout << char(204);
			gotoxy(x + w, y + i); cout << char(185);
			gotoxy(x + 6, y + i); cout << char(206);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(206);
		}
		if (i == h - 1) {
			gotoxy(x + 6, y + i); cout << char(202);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(202);
		}
	}
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << 1 << "/" << 2;

	// Chuc nang
	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
	chuyenTrang(x + w / 2 - 21, 31);
}

void xoaBangLop(int x, int y, int w, int h) {
	SetColor(15);
	for (int i = 0; i < h - 4; i++)
	{
		gotoxy(x + 1, y + i + 3);
		for (int j = 0; j < w - 3; j++)
		{
			cout << " ";
			if (j == 4 || j == (w - 8) / 2 + 3) cout << char(186);
		}
	}
}

void giaoDienNhapSV(int x, int y, int w, int h, int color) {
	SetColor(9);
	gotoxy(x + 15, y - 1); cout << "NHAP THONG TIN SINH VIEN";
	gotoxy(x + 5, y + 3); cout << "Ma";
	gotoxy(x + 5, y + 6); cout << "Ho";
	gotoxy(x + 5, y + 9); cout << "Ten";
	gotoxy(x + 5, y + 12); cout << "Phai";
	gotoxy(x + 5, y + 15); cout << "Password";
	rectangle(x, y, w, h, color);
	rectangle(x + 18, y + 2, 25, 3, 13);
	rectangle(x + 18, y + 5, 25, 3, 13);
	rectangle(x + 18, y + 8, 25, 3, 13);
	rectangle(x + 18, y + 11, 6, 3, 13);
	rectangle(x + 18, y + 14, 25, 3, 13);

	//chuc nang
	rectangle(x + w / 3, y + h + 2, w/3, 3, 13);
	gotoxy(x + w / 3 + 6, y + h + 3); cout << "Them";
	rectangle(x + w / 3, y + h + 5, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 6); cout << "Sua";
	rectangle(x + w / 3, y + h + 8, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 9); cout << "Xoa";
}

void giaoDienDVSVChiTiet(int x, int y, int w, int h, int color) {
	SetColor(9);
	gotoxy(x + w / 2 - 6, y - 1); cout << "DANH SACH SINH VIEN";
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + 10, y + 1); cout << "MA";
	gotoxy(x + (w - 8) / 5 + 10, y + 1); cout << "HO";
	gotoxy(x + 2 * (w - 8) / 5 + 10, y + 1); cout << "TEN";
	gotoxy(x + 3 * (w - 8) / 5 + 10, y + 1); cout << "PHAI";
	gotoxy(x + 4 * (w - 8) / 5 + 10, y + 1); cout << "PASSWORD";
	rectangle(x, y, w, h, color);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x + 6, y + i); cout << char(186);
		gotoxy(x + (w - 8) / 5 + 6, y + i); cout << char(186);
		gotoxy(x + 2 * (w - 8) / 5 + 6, y + i); cout << char(186);
		gotoxy(x + 3 * (w - 8) / 5 + 6, y + i); cout << char(186);
		gotoxy(x + 4 * (w - 8) / 5 + 6, y + i); cout << char(186);
		if (i == 0) {
			gotoxy(x + 6, y + i); cout << char(203);
			gotoxy(x + (w - 8) / 5 + 6, y + i); cout << char(203);
			gotoxy(x + 2 * (w - 8) / 5 + 6, y + i); cout << char(203);
			gotoxy(x + 3 * (w - 8) / 5 + 6, y + i); cout << char(203);
			gotoxy(x + 4 * (w - 8) / 5 + 6, y + i); cout << char(203);
		}
		if (i == 2) {
			for (int j = 0; j < w; j++)
			{
				gotoxy(x + j, y + i);  cout << char(205);
			}
			gotoxy(x, y + i); cout << char(204);
			gotoxy(x + w, y + i); cout << char(185);
			gotoxy(x + 6, y + i); cout << char(206);
			gotoxy(x + (w - 8) / 5 + 6, y + i); cout << char(206);
			gotoxy(x + 2 * (w - 8) / 5 + 6, y + i); cout << char(206);
			gotoxy(x + 3 * (w - 8) / 5 + 6, y + i); cout << char(206);
			gotoxy(x + 4 * (w - 8) / 5 + 6, y + i); cout << char(206);
		}
		if (i == h - 1) {
			gotoxy(x + 6, y + i); cout << char(202);
			gotoxy(x + (w - 8) / 5 + 6, y + i); cout << char(202);
			gotoxy(x + 2 * (w - 8) / 5 + 6, y + i); cout << char(202);
			gotoxy(x + 3 * (w - 8) / 5 + 6, y + i); cout << char(202);
			gotoxy(x + 4 * (w - 8) / 5 + 6, y + i); cout << char(202);
		}
	}

	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
	chuyenTrang(x + w / 2 - 21, 31);
}

void xoaBangSVChiTiet(int x, int y, int w, int h, int color) {
	SetColor(color);
	ShowCursor(0);
	for (int i = 0; i < h - 4; i++)
	{
		gotoxy(x + 1, y + i + 3);
		for (int j = 0; j < w - 6; j++) {
			cout << " ";
			if (j == 4 || j == (w - 4) / 5 + 2 || j == 2 * (w - 4) / 5 || j == 3 * (w - 4) / 5 - 1 || j == 4 * (w - 4) / 5 - 3) {
				cout << char(186);
			}
		}
	}
}

void giaoDienNhapMonHoc(int x, int y, int w, int h, int color) {
	SetColor(9);
	gotoxy(x + 15, y - 1); cout << "NHAP THONG TIN MON HOC";
	gotoxy(x + 5, y + 3); cout << "Ma mon hoc";
	gotoxy(x + 5, y + 6); cout << "Ten mon hoc";
	rectangle(x, y, w, h, color);
	rectangle(x + 20, y + 2, w / 2, 3, 13);
	rectangle(x + 20, y + 5, w / 2, 3, 13);
	
	// chuc nang
	rectangle(x + w/3, y + h + 2, w / 3, 3, 13);
	gotoxy(x + w / 3 + 6, y + h + 3); cout << "Them";
	rectangle(x + w/3, y + h + 5, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 6); cout << "Sua";
	rectangle(x + w/3, y + h + 8, w / 3, 3, 13);
	gotoxy(x + w / 3 + 7, y + h + 9); cout << "Xoa";
}

void giaoDienDSMH(int x, int y, int w, int h, int color) {
	SetColor(9);
	gotoxy(x + w / 2 - 3, y - 1); cout << "DANH SACH MON HOC";
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + (w - 5) / 4 + 3, y + 1); cout << "MA MON HOC";
	gotoxy(x + (w - 5) * 3 / 4 , y + 1); cout << "TEN MON HOC";
	SetColor(15);
	rectangle(x, y, w, h, 15);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x + 6, y + i); cout << char(186);
		gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(186);
		if (i == 0) {
			gotoxy(x + 6, y + i); cout << char(203);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(203);
		}
		if (i == 2) {
			for (int j = 0; j < w; j++)
			{
				gotoxy(x + j, y + i);  cout << char(205);
			}
			gotoxy(x, y + i); cout << char(204);
			gotoxy(x + w, y + i); cout << char(185);
			gotoxy(x + 6, y + i); cout << char(206);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(206);
		}
		if (i == h - 1) {
			gotoxy(x + 6, y + i); cout << char(202);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(202);
		}
	}
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << 1 << "/" << 2;

	// Chuc nang
	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
	chuyenTrang(x + w / 2 - 21, 31);
}

void xoaBangMonHoc(int x, int y, int w, int h, int color) {
	SetColor(13);
	for (int i = 0; i < h - 4; i++)
	{
		gotoxy(x + 1, y + 3 + i);
		for (int j = 0; j < w - 4; j++) {
			cout << " ";
			if (j == 4 || j == (w - 5) / 3 + 2 || j == 2 * (w - 5) / 3 + 1) {
				cout << char(186);
			}
		}
	}
}

void giaoDienNhapCauHoi(string tenMH, int x, int y, int w, int h, int color) {
	system("cls");
	SetColor(9);

	gotoxy(x + w / 2, y -1); cout << "NHAP CAU HOI THI " + toUpCaps(tenMH);
	gotoxy(x, y + 2); cout << "NOI DUNG:";
	gotoxy(x, y + h + 3); cout << "A:";
	gotoxy(x, y + h + 6 + h / 2); cout << "B:";
	gotoxy(x, y + h + 8 + h); cout << "C:";
	gotoxy(x, y + h + 11 + 3 * h / 2); cout << "D:";

	SetColor(13);
	rectangle(x - 5, y - 2, w + w/2, 10 * h - 1, 15);
	// cau hoi
	rectangle(x + 10, y + 1, w, h, color);

	// dap an 
	rectangle(x + 10, y + h + 2, w, h, color);
	rectangle(x + 10, y + 2 * h + 3, w, h, color);
	rectangle(x + 10, y + 3 * h + 4, w, h, color);
	rectangle(x + 10, y + 4 * h + 5, w, h, color);
	// o dap an
	rectangle(x + w / 2 + 1, y + 6 * h + 4, 14, 3, 13);
	gotoxy(x + w / 2 + 5, y + 6 * h + 3); cout << "DAP AN";
	
	rectangle(x + w / 2 + 1, y + 8 * h + 4, 14, 3, 13);
	gotoxy(x + w / 2 + 6, y + 8 * h + 5); cout << "Them";
}

void resetNhapCauHoi(int x, int y, int w, int h, int color) {
	// cau hoi
	rsRectangle(x + 10, y + 1, w, h, color);

	// dap an 
	rsRectangle(x + 10, y + h + 2, w, h, color);
	rsRectangle(x + 10, y + 2 * h + 3, w, h, color);
	rsRectangle(x + 10, y + 3 * h + 4, w, h, color);
	rsRectangle(x + 10, y + 4 * h + 5, w, h, color);
	// o dap an
	rsRectangle(x + w / 2 + 1, y + 6 * h + 4, 14, 3, 13);
	gotoxy(x + w / 2 + 5, y + 6 * h + 3); cout << "DAP AN";
}

void giaoDienChonDeThi(string tenMH, int x, int y, int  w, int h, int color) {
	SetColor(9);
	SetColor(9);
	gotoxy(x + 16, y - 1); cout << "CHON DE THI " + toUpCaps(tenMH);
	gotoxy(x + 4, y + 3); cout << "So phut thi";
	gotoxy(x + 4, y + 7); cout << "So cau hoi ";
	rectangle(x + 20, y + 2, 25, 3, 13);
	rectangle(x + 20, y + 6, 25, 3, 13);
	SetColor(15);
	rectangle(x, y, w, h, 15);

	rectangle(x + w / 3, y + h + 2, w/3, 3, 13);
	gotoxy(x + w / 3 + 3, y + h + 3); cout << "Bat dau thi";
}

void giaoDienkhungCauHoi( int x, int y, int w, int h) {
	system("cls");
	SetColor(9);
	// Khung time
	rectangle(x + 70, y, 15, 4, 4);
	gotoxy(118, 3); cout << "THOI GIAN";

	// Cau hoi
	rectangle(x, y + 4, w, h, 15);

	// Khung Tra Loi Trai Tren
	rectangle(x + 3, y + 11, 35, h, 13);

	// Khung Tra Loi Ben Trai Duoi
	rectangle(x + 3, y + 18, 35, h, 13);

	// Khung Tra Loi Phai Tren
	rectangle(x + 47, y + 11, 35, h, 13);

	// Khung Tra Loi Phai Duoi
	rectangle(x + 47, y + 18, 35, h, 13);

	// Khung Tra Loi
	rectangle(x + 35, y + 25, 15, h - 1, 13);
	SetColor(2);
	gotoxy(x + 40, y + 26); cout << "DAP AN";

	// Khung Chuc Nang Cau Hoi
	rectangle(x, y + 32, w, 3, 12);
	gotoxy(x + 3, y + 33); cout << "PgUp: Cau truoc";
	gotoxy(x + 38, y + 33); cout << "PgDn: Cau sau";
	gotoxy(x + 70, y + 33); cout << "Enter: Nop bai";
}

void thongTinCauHoi(CAUHOI cauhoi, int x, int y, int w, int h) {

	// Cau hoi
	gotoxy(x + 3, y + 5); cout << cauhoi.noiDung;

	// Khung Tra Loi Trai Tren
	gotoxy(x + 5, y + 12); cout << cauhoi.dapAnA;

	// Khung Tra Loi Ben Trai Duoi
	gotoxy(x + 5, y + 19); cout << cauhoi.dapAnC;

	// Khung Tra Loi Phai Tren
	gotoxy(x + 49, y + 12); cout << cauhoi.dapAnB;

	// Khung Tra Loi Phai Duoi
	gotoxy(x + 49, y + 19); cout << cauhoi.dapAnD;
}

void hightlightCH(CAUHOI cauhoi[], int CHCurrent, int x, int y, int h) {
	if (cauhoi[CHCurrent].dapAnDung == "A")
	{
		rectangle(x + 3, y + 11, 35, h, 2);
		rectangle(x + 47, y + 11, 35, h, 13);
		rectangle(x + 3, y + 18, 35, h, 13);
		rectangle(x + 47, y + 18, 35, h, 13);
	}
	else if (cauhoi[CHCurrent].dapAnDung == "B")
	{
		rectangle(x + 3, y + 11, 35, h, 13);
		rectangle(x + 47, y + 11, 35, h, 2);
		rectangle(x + 3, y + 18, 35, h, 13);
		rectangle(x + 47, y + 18, 35, h, 13);
	}
	else if (cauhoi[CHCurrent].dapAnDung == "C")
	{
		rectangle(x + 3, y + 11, 35, h, 13);
		rectangle(x + 47, y + 11, 35, h, 13);
		rectangle(x + 3, y + 18, 35, h, 2);
		rectangle(x + 47, y + 18, 35, h, 13);
	}
	else if (cauhoi[CHCurrent].dapAnDung == "D")
	{
		rectangle(x + 3, y + 11, 35, h, 13);
		rectangle(x + 47, y + 11, 35, h, 13);
		rectangle(x + 3, y + 18, 35, h, 13);
		rectangle(x + 47, y + 18, 35, h, 2);
	}
}

void xoaKhungCauHoi(int x, int y, int w, int h) {
	// Xoa khung cau hoi
	rsRectangle(x, y + 4, w, h, 15);

	// Khung Tra Loi Trai Tren
	rsRectangle(x + 3, y + 11, 35, h, 13);

	// Khung Tra Loi Ben Trai Duoi
	rsRectangle(x + 3, y + 18, 35, h, 13);

	// Khung Tra Loi Phai Tren
	rsRectangle(x + 47, y + 11, 35, h, 13);

	// Khung Tra Loi Phai Duoi
	rsRectangle(x + 47, y + 18, 35, h, 13);

	// Khung Tra Loi
	rsRectangle(x + 35, y + 25, 15, h - 1, 13);
	gotoxy(x + 40, y + 26); cout << "DAP AN";
}

void bangDiemTheoLop(string tenLop, string tenMH, int x, int y, int w, int h, int color) {
	system("cls");
	SetColor(9);
	gotoxy(x + w / 2 - 3, y - 3); cout << "BANG DIEM";
	gotoxy(x + 2, y - 1); cout << "TEN LOP: "<< toUpCaps(tenLop);
	gotoxy(x + 40, y - 1); cout << "MON HOC: "<< toUpCaps(tenMH);
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + (w - 5) / 4 + 3, y + 1); cout << "HO TEN";
	gotoxy(x + (w - 5) * 3 / 4 + 3, y + 1); cout << "DIEM";
	rectangle(x, y, w, h, 15);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x + 6, y + i); cout << char(186);
		gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(186);
		if (i == 0) {
			gotoxy(x + 6, y + i); cout << char(203);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(203);
		}
		if (i == 2) {
			for (int j = 0; j < w; j++)
			{
				gotoxy(x + j, y + i);  cout << char(205);
			}
			gotoxy(x, y + i); cout << char(204);
			gotoxy(x + w, y + i); cout << char(185);
			gotoxy(x + 6, y + i); cout << char(206);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(206);
		}
		if (i == h - 1) {
			gotoxy(x + 6, y + i); cout << char(202);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(202);
		}
	}
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << 1 << "/" << 2;

	// Chuc nang
	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
	chuyenTrang(x + w / 2 - 21, 31);
}

void giaoDienCauTrlSV() {
	system("cls");
	SetColor(9);
	gotoxy(77, 7); cout << "THONG TIN CHI TIET CAU HOI";
	gotoxy(67, 11); cout << "Ten mon thi: ";
	SetColor(13);
	gotoxy(60, 9); cout << char(201);
	for (int i = 0; i < 55; i++) {
		cout << char(205);
	}
	cout << char(187);
	gotoxy(116, 11); cout << char(185);
	for (int i = 0; i < 3; i++)
	{
		gotoxy(60, 10 + i); cout << char(186);
		gotoxy(116, 10 + i); cout << char(186);
	}
	gotoxy(60, 13); cout << char(200);
	for (int i = 0; i < 55; i++) {
		cout << char(205);
	}
	cout << char(188);

	SetColor(2);
	gotoxy(80, 15); cout << "Enter de tiep tuc";
	gotoxy(80, 16); cout << "Esc de tro ve menu";
}

//void chiTietCauHoiSV() {
//	system("cls");
//	SetColor(9);
//	gotoxy(72, 3); cout << "CHI TIET CAU HOI 1 MON HOC DA THI";
//	gotoxy(35, 5); cout << "Mon hoc: ";
//	SetColor(13);
//	gotoxy(30, 6); cout << char(201);
//	for (int i = 0; i < 113; i++) {
//		cout << char(205);
//	}
//	cout << char(187);
//	for (int i = 0; i < 25; i++)
//	{
//		gotoxy(30, 7 + i); cout << char(186);
//		gotoxy(144, 7 + i); cout << char(186);
//	}
//	gotoxy(30, 32); cout << char(200);
//	for (int i = 0; i < 113; i++) {
//		cout << char(205);
//	}
//	cout << char(188);
//	gotoxy(84, 33); cout << 1 << "/" << 2;
//	//gotoxy(84, 28); cout << "Trang " << index << "/" << soTrang;
//
//	// Khung Chuc 
//	SetColor(2);
//	gotoxy(35, 35); cout << char(201);
//	for (int i = 0; i < 104; i++) {
//		cout << char(205);
//	}
//	cout << char(187);
//	gotoxy(35, 36); cout << char(186);
//	gotoxy(40, 36); cout << "PgUp: Trang ke tiep";
//	gotoxy(80, 36); cout << "PgDn: Trang truoc";
//	gotoxy(120, 36); cout << "Esc: ve menu";
//	gotoxy(140, 36); cout << char(186);
//	gotoxy(35, 37); cout << char(200);
//	for (int i = 0; i < 104; i++) {
//		cout << char(205);
//	}
//	cout << char(188);
//}

void search(int x, int y, int w, int color) {
	gotoxy(x, y); cout << "Search";
	rectangle(x + 10, y - 1, w, 3, color);
	gotoxy(x + 13, y); cout << "Press F1 to search";
}

void rectangle(int x, int y, int w, int h, int color) {
	SetColor(color);
	for (int i = 0; i < h; i++)
	{
		if (i == 0) {
			gotoxy(x, y + i); cout << char(201);
			for (int j = 1; j < w; j++)
			{
				cout << char(205);
			}
			gotoxy(x + w, y + i); cout << char(187);
		}
		if (i + 1 == h) {
			gotoxy(x, y + i); cout << char(200);
			for (int j = 1; j < w; j++)
			{
				cout << char(205);
			}
			gotoxy(x + w, y + i); cout << char(188);
		}
		if (i > 0 && i < h - 1) {
			gotoxy(x, y + i); cout << char(186);
			for (int j = 1; j < w; j++)
			{
				cout << "";
			}
			gotoxy(x + w, y + i); cout << char(186);
		}
	}
}

void resetInput(int x, int y, int w, int h, int color) {
		SetColor(color);
		rectangle(x, y, w, h, color);
}

void rsRectangle(int x, int y, int w, int h, int color) {
	for (int i = 0; i < h - 2; i++)
	{
		gotoxy(x + 1, y + i + 1);
		for (int j = 0; j < w - 1; j++)
		{
			cout << " ";
		}
	}
}

void themSuaXoa(int x, int y) {
	gotoxy(x, y); cout << "Insert: Them";
	gotoxy(x + 20, y); cout << "F2: Sua";
	gotoxy(x + 35, y); cout << "Delete: Xoa";
	gotoxy(x + 55, y); cout << "Esc: Back";
}

void chuyenTrang(int x, int y) {
	gotoxy(x, y); cout << "PgUp: Trang truoc";
	gotoxy(x + 25, y); cout << "PgDn: Trang sau";
}

void hightlight(int x, int y) {
	gotoxy(x, y - 1); SetBGColor(32); SetColor(15); cout << "    ";
	gotoxy(x, y); SetBGColor(4); SetColor(15); cout << "<===";
	gotoxy(x, y + 1); SetBGColor(32); SetColor(15); cout << "    ";
}

void ketThucThi(int x, int y, string str) {
	SetBGColor(0);
	rectangle(x, y, 40, 8, 12);
	gotoxy(x + 10, y + 2); cout << str;
	SetColor(12);
	gotoxy(x + 10, y + 4); cout << "ENTER de nop bai";
}

void diemThi(float diem, int cauDung, int soCH, int x, int y, int w, int h) {
	system("cls");
	rectangle(x, y, w, h, 15);
	gotoxy(x + w/4 + 5, y + 2); cout << "Ban duoc " << diem << " / 10 diem";
	gotoxy(x + w/4 + 5, y + 4); cout << "So cau dung: " << cauDung << " / " << soCH << " cau";

	rectangle(x + w / 3, y + 6, w / 3, 3, 13);
	gotoxy(x + w / 3 + 5, y + 7); cout << "Xem bai thi";
	rectangle(x + w / 3, y + 9, w / 3, 3, 13);
	gotoxy(x + w / 3 + 5, y + 10); cout << "   Thoat";
}

string toUpCaps(string s) {
	string kq = "";
	int count = s.length();
	for (int i = 0; i < count; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
		kq += s[i];
	}
	return kq;
}

void thongTinThi(string ma, string ho, string ten, string mon, int x, int y) {
	rectangle(x, y, 30, 5, 12);
	SetColor(13);
	gotoxy(x + 2, y + 1); cout << "MON THI: " + toUpCaps(mon);
	gotoxy(x + 2, y + 2); cout << "MSSV: " + ma;
	gotoxy(x + 2, y + 3); cout << "HO TEN: " + toUpCaps(ho) + " " + toUpCaps(ten);	
}

void rsKhungNhapSV(int x, int y, int w) {
	rsRectangle(x + 18, y + 2, w / 2, 3, 13);
	rsRectangle(x + 18, y + 5, w / 2, 3, 13);
	rsRectangle(x + 18, y + 8, w / 2, 3, 13);
	rsRectangle(x + 18, y + 11, 6, 3, 13);
	rsRectangle(x + 18, y + 14, w / 2, 3, 13);
}

void rsKhungNhapLop(int x, int y, int w) {
	rsRectangle(x + 15, y + 2, w / 2, 3, 13);
	rsRectangle(x + 15, y + 6, w / 2, 3, 13);
}

void rsKhungNhapMH(int x, int y, int w) {
	rsRectangle(x + 20, y + 2, w / 2, 3, 13);
	rsRectangle(x + 20, y + 5, w / 2, 3, 13);
}

void giaoDienDiemSV(int x, int y, int w, int h) {
	SetColor(9);
	gotoxy(x + w / 2 - 6, y - 1); cout << "DANH SACH DIEM";
	gotoxy(x + 2, y + 1); cout << "STT";
	gotoxy(x + (w - 5) / 4 + 3, y + 1); cout << "MON HOC";
	gotoxy(x + (w - 5) * 3 / 4 + 3, y + 1); cout << "DIEM";
	SetColor(15);
	rectangle(x, y, w, h, 15);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x + 6, y + i); cout << char(186);
		gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(186);
		if (i == 0) {
			gotoxy(x + 6, y + i); cout << char(203);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(203);
		}
		if (i == 2) {
			for (int j = 0; j < w; j++)
			{
				gotoxy(x + j, y + i);  cout << char(205);
			}
			gotoxy(x, y + i); cout << char(204);
			gotoxy(x + w, y + i); cout << char(185);
			gotoxy(x + 6, y + i); cout << char(206);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(206);
		}
		if (i == h - 1) {
			gotoxy(x + 6, y + i); cout << char(202);
			gotoxy(x + (w - 8) / 2 + 6, y + i); cout << char(202);
		}
	}
	// Chuc nang
	rectangle(x + w / 2 - 25, 30, 50, 3, 10);
	chuyenTrang(x + w / 2 - 21, 31);
}