#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#include <Windows.h>
#include "TimeCount.h"
#include "mylib.h"
#include "GiaoDien.h"
#include "TextField.h"
#include "const.h"
#include "khaibao.h"
#include "doc_ghi_file.h"
#include "Lop.h"
#include "Student.h"
#include "MonHoc.h"
#include "Diem.h"

using namespace std;

bool loop, loop1, loop2;
string hoSV, tenSV, MSSV;

void chucNangSV(DS_LOP& ds_lop, LOP& lop, NodeMH*& root);
void loadDSLop(DS_LOP& ds_lop, LOP& p, int x, int y, int w, int h, int type);
void chucNangThemLop(int x, int y, int w, int h, DS_LOP& ds_lop);
void chucNangGV(DS_LOP& ds_lop, LOP& lop, NodeMH*& root);
void clearScreen(int x, int y, int w, int h);
void chucNangNhapSV(DS_LOP& ds_lop, LOP& lop, int x, int y, int w, int h);
int chuyenDoiSo(string text);
void chucNangThemMH(int x, int y, int w, int h, NodeMH*& monhoc, ds_lop);
void chucNangCauHoi(NodeMH*& root, int x, int y, int w, int h);
void chucNangThi(DS_LOP& ds_lop, DSCAUHOI* dsch, MonHoc monhoc, int x, int y, int w, int h, int soPhut, int soCH);
string toUpCaps(string s);
void inDSLOP(DS_LOP& ds_lop, int x, int y, int w, int h);
void chucNangXemBaiThi(MonHoc monhoc, CAUHOI cauhoi[], string dapAnChon[], float diem, int cauDung, int soCH, int x, int y, int w, int h);
void thiTracNghiem(DS_LOP& ds_lop, NodeMH*& root, int x, int y, int w, int h);
void inBangDiem(DS_LOP& ds_lop, LOP& lop, NodeMH* root, int x, int y, int w, int h);
void inDiemSV(DS_LOP& ds_lop, string masv, NodeMH*& root, int x, int y, int w, int h);

int checkPass(string account, string password, DS_LOP& ds_lop) {
	SINHVIEN sv;
	if (account == "GV" && password == "GV")
	{
		MSSV = "GV", tenSV = "GV", hoSV = "";
		return 1;
	}
	else if (checkAcc(ds_lop, sv, account, password)) {
		MSSV = sv.masv, tenSV = sv.ten, hoSV = sv.ho;
		return 2;
	}
	return 0;
}

void chucNangDangNhap(int x, int y, int w, int h, DS_LOP& ds_lop, NodeMH*& root) {
	int row = 0;
	string account = "", password = "";
	while (true)
	{
		khungDangNhap(x, y, w, h);
		//char banphim;
		switch (row)
		{
		case 0: {

			inputText(x + 20, y + 2, w / 2, rule_tudo, account, 4, type_input);
			account = text;
			row = dem;
			//if (row < 0) row = 2;
			break;
		}
		case 1: {
			//gotoxy(72, 16); 
			inputText(x + 20, y + 5, w / 2, rule_tudo, password, 4, type_password);
			password = text;
			row = dem;
			//if (row > 2) row = 0;
			break;
		}
		case 2: {
			//gotoxy(72, 16); 
			inputText(x + w / 2 - 6, y + h + 2, 12, rule_cam, "Dang nhap", 4, type_input);
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER && text == "Dang nhap") {
				int who = checkPass(account, password, ds_lop);
				LOP* lop = new LOP;
				switch (who)
				{
				case 0: {
					messeger(x, 30, 25, 3, 12, "Dang nhap that bai !", DELAY);
					row = dem;
					break;
				}
				case 1: {
					messeger(x, 30, 25, 3, 2, "Dang nhap thanh cong !", DELAY);
					chucNangGV(ds_lop, *lop, root);
					row = 0; dem = 0;
					account = "", password = "";
					break;
				}
				case 2: {
					messeger(x, 30, 25, 3, 2, "Dang nhap thanh cong !", DELAY);
					chucNangSV(ds_lop, *lop, root);
					row = 0; dem = 0;
					account = "", password = "";
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 3: {
			inputText(x + w / 2 - 6, y + h + 6, 12, rule_cam, "  Thoat", 4, type_input);
			row = dem;
			if (input == ENTER) {
				return;
			}
		}
		}
		//loop1 = loop;
	}
}

void chucNangGV(DS_LOP& ds_lop, LOP& lop, NodeMH*& root) {
	loop = true;
	while (loop)
	{
		system("cls");
		menuGiangVien();
		char luaChon = _getch();
		switch (luaChon)
		{
		case 49: { // 1
			chucNangThemLop(15, 7, 50, 11, ds_lop);
			break;
		}
		case 50: { // 2
			system("cls");
			inDSLOP(ds_lop, 45, 7, 75, 20);
			break;
		}
		case 51: { //  3
			system("cls");
			chucNangNhapSV(ds_lop, lop, 10, 5, 50, 19);
			break;
		}
		case 52: { //  4
			system("cls");
			chucNangThemMH(15, 7, 50, 10, root, ds_lop);
			break;
		}
		case 53: { //  5
			system("cls");
			chucNangCauHoi(root, 40, 6, 45, 3);
			break;
		}
		case 54: { //  6
			system("cls");
			thiTracNghiem(ds_lop, root, 40, 7, 75, 20);
			break;
		}
		case 55: { //  7
			system("cls");
			inBangDiem(ds_lop, lop, root, 45, 7, 75, 20);
			loop = true;
			break;
		}
		case ESC: {
			system("cls");
			loop = false;
			break;
		}
		default:
			break;
		}
	}
}

void chucNangSV(DS_LOP& ds_lop, LOP& lop, NodeMH*& root) {
	loop = true;
	while (loop)
	{
		system("cls");
		menuSinhVien();
		char luaChon = _getch();
		switch (luaChon)
		{
		case 49: { // 1
			system("cls");
			thiTracNghiem(ds_lop, root, 40, 7, 75, 20);
			break;
		}
		case 50: { // 2
			system("cls");
			inDiemSV(ds_lop, MSSV, root, 45, 7, 75, 20);
			break;
		}
		case ESC: {
			system("cls");
			loop = false;
			break;
		}
		default:
			break;
		}
	}
}

void chucNangThemLop(int x, int y, int w, int h, DS_LOP& ds_lop) {
	system("cls");
	LOP* p = new LOP;
	int row = 0, index = 0;
	giaoDienNhapLop(x, y, w, h);
	loop1 = true;
	dem = 0;
	while (loop1)
	{
		switch (row)
		{
		case 0: {
			dem = 0;
			inputText(x + 15, y + 2, w / 2, rule_masv, p->malop, 5, type_input);
			if (input == ESC) return;
			p->malop = text;
			row = dem;
			break;
		}
		case 1: {
			inputText(x + 15, y + 6, w / 2, rule_tenmh, p->tenlop, 5, type_input);
			if (input == ESC) return;
			p->tenlop = text;
			row = dem;
			break;
		}
		case 2: {
			inputText(x + w / 3, y + h + 2, w / 3, rule_cam, "    Them", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				if (p->malop == "")
				{
					messeger(x, 30, 50, 3, 12, "ma lop khong dc bo trong !", DELAY);
				}
				else if (p->tenlop == "")
				{
					messeger(x, 30, 50, 3, 12, "Ten lop khong duoc bo trong !", DELAY);
				}
				else if (!checkMaLop(p->malop, ds_lop))
				{
					themLop(ds_lop, p->malop, p->tenlop);
					messeger(x, 30, 50, 3, 2, "Them thanh cong !", DELAY);
					rsKhungNhapLop(x, y, w);
					p->malop = ""; p->tenlop = "";
				}
				else {
					messeger(x, 30, 50, 3, 12, "Ma lop ton tai !", DELAY);
				}
			}
			ghiFileDanhSachLop(ds_lop);
			ghiSinhVien(ds_lop);
			break;
		}
		case 3: {
			inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				loadDSLop(ds_lop, *p, x + 20 + w, y, 75, 20, edit);
				rsKhungNhapLop(x, y, w);
				if (!p->malop.length() == 0 && !p->tenlop.length() == 0) {
					SetColor(13);
					gotoxy(x + 17, y + 3); cout << p->malop;
					gotoxy(x + 17, y + 7); cout << p->tenlop;
					dem = 0;
					int a = 0;
					loop2 = true;
					while (loop2)
					{
						switch (a)
						{
						case 0: {
							inputText(x + 15, y + 2, w / 2, rule_cam, p->malop, 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapLop(x, y, w);
								dem = 3;
								loop2 = false;
								p->malop = ""; p->tenlop = "";
							}
							a = dem;
							break;
						}
						case 1: {
							inputText(x + 15, y + 6, w / 2, rule_tenmh, p->tenlop, 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapLop(x, y, w);
								dem = 3;
								loop2 = false;
								p->malop = ""; p->tenlop = "";
							}
							else {
								p->tenlop = text;
								a = dem;
							}
							break;
						}
						case 2: {
							inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapLop(x, y, w);
								dem = 3;
								loop2 = false;
								p->malop = ""; p->tenlop = "";
							}
							if (input == ARROW_DONW || input == ARROW_UP)
							{
								a = dem;
							}
							if (input == ENTER)
							{
								if (p->tenlop == "")
								{
									messeger(x, 30, 50, 3, 12, "Ten lop khong duoc bo trong !", DELAY);
								}
								else {
									hieuChinhLop(ds_lop, p->malop, p->tenlop);
									messeger(x, 30, 50, 3, 2, "Chinh sua lop thanh cong !", DELAY);
									dem = 3;
									loop2 = false;
									ghiFileDanhSachLop(ds_lop);
									rsKhungNhapLop(x, y, w);
									p->malop = ""; p->tenlop = "";
								}
							}
							break;
						}
						default:
							break;
						}
					}
				}
				rsKhungNhapLop(x, y, w);
			}
			break;
		}
		case 4: {
			inputText(x + w / 3, y + h + 8, w / 3, rule_cam, "     Xoa", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				loadDSLop(ds_lop, *p, x + 20 + w, y, 75, 20, edit);
				rsKhungNhapLop(x, y, w);
				if (!p->malop.length() == 0)
				{
					loop2 = true;
					while (loop2)
					{
						rectangle(x, 32, 50, 3, 12);
						gotoxy(x + 2, 33); cout << "Ma lop " + p->malop + " Ban co muon xoa Y/N !";
						char banphim = _getch();
						clearMesseger(x, 32, 50, 3);
						if (banphim == 89 || banphim == 121) {
							clearScreen(80, 5, 85, 35);
							if (!xoaLop(ds_lop, p->malop))
							{
								messeger(x, 32, 50, 3, 12, "Khong the xoa lop nay !", DELAY);
							}
							else {
								messeger(x, 32, 50, 3, 2, "Xoa thanh cong", DELAY);
							}
							loop2 = false;
							p->malop = ""; p->tenlop = "";
							ghiFileDanhSachLop(ds_lop);
							ghiSinhVien(ds_lop);
						}
						else if (banphim == 78 || banphim == 110)
						{
							loop2 = false;
							p->malop = ""; p->tenlop = "";
						} if (banphim == ESC)
						{
							loop2 = false;
							clearScreen(x + 20 + w, y - 5, 75, 35);
							p->malop = ""; p->tenlop = "";
						}
					}
				}
			}
			break;
		}
		}
	}
}

void loadDSLop(DS_LOP& ds_lop, LOP& lop, int x, int y, int w, int h, int type) {
	//system("cls");
	string inputSearch = "";
	search(x, y - 4, 40, 13);
	int count = 0, end = 15, pageindex = 0;
	int soPage = ds_lop.sl / 15;
	giaoDienDSLop(x, y, w, h);
	hightlight(x + w + 1, y + 3);
	xuatDanhSachLop(ds_lop, count, x, y);
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex +1 << "/" << soPage+1;
	loop2 = true;
	while (loop2)
	{
		char banphim = _getch();
		switch (banphim)
		{
		case ARROW_DONW: {
			count++;
			if (pageindex == soPage)
			{
				if (count > ds_lop.sl - soPage * 15 - 1)
				{
					gotoxy(x + w + 1, y + ds_lop.sl - soPage * 15 + 2); cout << "     ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			else
			{
				if (count > 14)
				{
					gotoxy(x + w + 1, y + 2 + count); cout << "    ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case ARROW_UP: {
			count--;
			if (pageindex == soPage)
			{
				if (count < 0) {
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = ds_lop.sl - soPage * 15 - 1;
				}
				hightlight(x + w + 1, y + 3 + count);

			}
			else {
				if (count < 0)
				{
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = 14;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case PgDn: {
			pageindex++;
			if (pageindex <= soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage+1;
			}
			else if (pageindex > soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "     ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = 0;
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 0, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage+1;
			}
			break;
		}
		case PgUp: {
			pageindex--;
			if (pageindex < 0)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = soPage;
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage+1;
			}
			else
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "       ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage+1;
			}
			break;
		}
		case F1: {
			loop2 = true;
			while (loop2)
			{
				rsRectangle(x + 10, y - 5, 40, 3, 13);
				inputText(x + 10, y - 5, 40, rule_masv, inputSearch, 1, type_input);
				if (input == ESC) loop2 = false;
				if (input == ENTER)
				{
					inputSearch = text;
					int temp = timMaLop(inputSearch, ds_lop);
					if (temp != -1)
					{
						gotoxy(x + w + 1, y + 3 + count); cout << "       ";
						count = temp % 15;
						pageindex = temp / 15;
						hightlight(x + w + 1, y + 3 + count);
						xoaBangLop(x, y, w, h);
						xuatDanhSachLop(ds_lop, 15 * pageindex, x, y);
						gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
						loop2 = false;
					}
					else {
						messeger(15, 30, 50, 3, 12, "Ma lop khong ton tai !", DELAY);
					}
				}
			}
			loop2 = true;
			break;
		}
		case ENTER: {
			if (type == edit)
			{
				lop.malop = ds_lop.ds[count + pageindex * 15]->malop;
				lop.tenlop = ds_lop.ds[count + pageindex * 15]->tenlop;
				clearScreen(x, y - 5, w + 10, h + 15);
				loop2 = false;
				return;
			}
			break;
		}
		case ESC: {
			clearScreen(x, y - 5, w + 10, h + 15);
			lop.malop = ""; lop.tenlop = "";
			return;
			break;
		}
		default:
			break;
		}
	}
}

void clearScreen(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			gotoxy(x + j, y + i); cout << " ";
		}
	}
}

void loadDSSVChiTiet(DS_LOP& ds_lop, SINHVIEN& sv, int vitri, int x, int y, int w, int h, int type) {
	mSINHVIEN msv;
	int slsv = demSV(ds_lop.ds[vitri]->first);
	int count = 0, end = 15, pageindex = 0;
	int soPage = slsv / 15;
	string inputSearch = "";
	search(x, y - 4, 40, 13);
	giaoDienDVSVChiTiet(x, y, w, h, 15);
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
	hightlight(x + w + 1, y + 3);
	xuatSVTheoLop(ds_lop, msv, vitri, slsv, count, x, y);
	loop2 = true;
	while (loop2)
	{
		char banphim = _getch();
		switch (banphim)
		{
		case ARROW_DONW: {
			count++;
			if (pageindex == soPage)
			{
				if (count > slsv - soPage * 15 - 1)
				{
					gotoxy(x + w + 1, y + slsv - soPage * 15 + 2); cout << "     ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			else
			{
				if (count > 14)
				{
					gotoxy(x + w + 1, y + 2 + count); cout << "    ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case ARROW_UP: {
			count--;
			if (pageindex == soPage)
			{
				if (count < 0) {
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = slsv - soPage * 15 - 1;
				}
				hightlight(x + w + 1, y + 3 + count);
				xuatSVTheoLop(ds_lop, msv, vitri, slsv, 15 * pageindex, x, y);
			}
			else {
				if (count < 0)
				{
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = 14;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case PgDn: {
			pageindex++;
			if (pageindex <= soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
			}
			else if (pageindex > soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "     ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = 0;
			}
			xoaBangSVChiTiet(x, y, w, h, 15);
			xuatSVTheoLop(ds_lop, msv, vitri, slsv, 15 * pageindex, x, y);
			gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			break;
		}
		case PgUp: {
			pageindex--;
			if (pageindex < 0)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = soPage;
			}
			else
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "       ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
			}
			xoaBangSVChiTiet(x, y, w, h, 15);
			xuatSVTheoLop(ds_lop, msv, vitri, slsv, 15 * pageindex, x, y);
			gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			break;
		}
		case F1: {
			loop2 = true;
			while (loop2)
			{
				rsRectangle(x + 10, y - 5, 40, 3, 13);
				inputText(x + 10, y - 5, 40, rule_masv, inputSearch, 1, type_input);
				if (input == ESC) loop2 = false;
				if (input == ENTER)
				{
					inputSearch = text;
					int tempSV = sttSV(ds_lop, msv, vitri, inputSearch, slsv);
					if (tempSV != -1)
					{
						gotoxy(x + w + 1, y + 3 + count); cout << "       ";
						count = tempSV % 15;
						pageindex = tempSV / 15;
						hightlight(x + w + 1, y + 3 + count);
						xoaBangSVChiTiet(x, y, w, h, 15);
						xuatSVTheoLop(ds_lop, msv, vitri, slsv, 15 * pageindex, x, y);
						gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
						loop2 = false;
					}
					else {
						messeger(15, 35, 50, 3, 12, "Ma sinh vien khong ton tai !", DELAY);
					}
				}
			}
			loop2 = true;
			break;
		}
		case ENTER: {
			if (type == edit)
			{
				int stt = count + pageindex * 15;
				if (stt == -1)
				{
					messeger(15, 35, 50, 3, 12, "Danh sach rong !", DELAY);
					clearScreen(x, y - 5, w + 10, h + 15);
					return;
				}
				sv = timSV(ds_lop, vitri, msv.sv[count + pageindex * 15].masv);
				loop2 = false;
				clearMesseger(x, 32, 50, 3);
				clearScreen(x, y - 5, w + 10, h + 15);
			}
			break;
		}
		case ESC: {
			if (type == show)
			{
				clearMesseger(x, 32, 50, 3);
				clearScreen(x, y - 5, w + 10, h + 15);
				inDSLOP(ds_lop, 45, 7, 75, 20);
				return;
			}
			else {
				clearMesseger(x, 32, 50, 3);
				clearScreen(x, y - 5, w + 10, h + 15);
				return;
			}
			break;
		}
		default:
			break;
		}
	}
}

void chucNangNhapSV(DS_LOP& ds_lop, LOP& lop, int x, int y, int w, int h) {
	system("cls");
	loop1 = true;
	loadDSLop(ds_lop, lop, 10, 7, 75, 20, edit);
	while (loop1)
	{
		if (lop.malop.length() != 0)
		{
			system("cls");
			SINHVIEN sv;
			int vitri = timMaLop(lop.malop, ds_lop);
			int row = 0, index = 0;
			giaoDienNhapSV(x, y, w, h, 15);
			loop1 = true;
			dem = 0;
			while (loop1)
			{
				switch (row)
				{
				case 0: {
					dem = 0;
					inputText(x + 18, y + 2, w / 2, rule_masv, sv.masv, 8, type_input);
					if (input == ESC) {
						chucNangNhapSV(ds_lop, lop, x, y, w, h);
					}
					sv.masv = text;
					row = dem;
					break;
				}
				case 1: {
					inputText(x + 18, y + 5, w / 2, rule_ho, sv.ho, 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					sv.ho = text;
					row = dem;
					break;
				}
				case 2: {
					inputText(x + 18, y + 8, w / 2, rule_ten, sv.ten, 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					sv.ten = text;
					row = dem;
					break;
				}
				case 3: {
					inputText(x + 18, y + 11, 6, rule_cam, sv.phai, 8, type_input);
					if (input == ESC) { chucNangNhapSV(ds_lop, lop, x, y, w, h); }
					if (input == ARROW_DONW || input == ARROW_UP)
					{
						row = dem;
					}
					if (input == ENTER)
					{
						loop2 = true;
						while (loop2)
						{
							char k = _getch();
							if (k == ARROW_LEFT)
							{
								if (sv.phai == "Nam")
								{
									sv.phai = "Nu";
									gotoxy(x + 20, y + 12); cout << "   ";
									gotoxy(x + 20, y + 12); cout << "Nu";
								}
								else {
									sv.phai = "Nam";
									gotoxy(x + 20, y + 12); cout << "Nam";
								}
							}
							else if (k == ARROW_RIGHT)
							{
								if (sv.phai == "Nam")
								{
									sv.phai = "Nu";
									gotoxy(x + 20, y + 12); cout << "   ";
									gotoxy(x + 20, y + 12); cout << "Nu";
								}
								else {
									sv.phai = "Nam";
									gotoxy(x + 20, y + 12); cout << "Nam";
								}
							}
							if (k == ENTER)
							{
								row = dem;
								loop2 = false;
							}
						}
					}

					break;
				}
				case 4: {
					inputText(x + 18, y + 14, w / 2, rule_tudo, sv.password, 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					sv.password = text;
					row = dem;
					break;
				}
				case 5: {
					inputText(x + w / 3, y + h + 2, w / 3, rule_cam, "    Them", 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					if (input == ARROW_DONW || input == ARROW_UP)
					{
						row = dem;
					}
					if (input == ENTER)
					{
						if (sv.masv == "")
						{
							messeger(x, 35, 50, 3, 12, "Ma sinh vien khong dc bo trong !", DELAY);
						}
						else if (sv.ho == "")
						{
							messeger(x, 35, 50, 3, 12, "Ho khong duoc bo trong !", DELAY);
						}
						else if (sv.ten == "")
						{
							messeger(x, 35, 50, 3, 2, "Ten khong duoc bo trong !", DELAY);
						}
						else if (sv.phai == "")
						{
							messeger(x, 35, 50, 3, 2, "Gioi tinh khong duoc bo trong !", DELAY);
						}
						else if (sv.password == "")
						{
							messeger(x, 35, 50, 3, 2, "Password khong duoc bo trong !", DELAY);
						}
						else if (KiemTraTrungSinhVien(ds_lop, sv.masv))
						{
							messeger(x, 35, 50, 3, 2, "Ma sinh vien da ton tai !", DELAY);
						}
						else {
							themSinhVien(ds_lop, sv, vitri);
							messeger(x, 35, 50, 3, 2, "Them sinh vien thanh cong !", DELAY);
							ghiSinhVien(ds_lop);
							rsKhungNhapSV(x, y, w);
							sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
						}
					}
					break;
				}
				case 6: {
					inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					if (input == ARROW_DONW || input == ARROW_UP)
					{
						row = dem;
					}
					if (input == ENTER)
					{
						loadDSSVChiTiet(ds_lop, sv, vitri, x + w + 10, y + 2, 100, 20, edit);
						rsKhungNhapSV(x, y, w);
						if (!sv.masv.length() == 0) {
							SetColor(13);
							gotoxy(x + 20, y + 3); cout << sv.masv;
							gotoxy(x + 20, y + 6); cout << sv.ho;
							gotoxy(x + 20, y + 9); cout << sv.ten;
							gotoxy(x + 20, y + 12); cout << sv.phai;
							gotoxy(x + 20, y + 15); cout << sv.password;
							int a = 0;
							dem = 0;
							loop2 = true;
							while (loop2)
							{
								switch (a)
								{
								case 0: {
									inputText(x + 18, y + 2, w / 2, rule_cam, sv.masv, 6, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "Nam", sv.password = "";
									}
									a = dem;
									break;
								}
								case 1: {
									inputText(x + 18, y + 5, w / 2, rule_ho, sv.ho, 6, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "Nam", sv.password = "";
									}
									else {
										sv.ho = text;
										a = dem;
									}
									break;
								}
								case 2: {
									inputText(x + 18, y + 8, w / 2, rule_ten, sv.ten, 6, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "Nam", sv.password = "";
									}
									else {
										sv.ten = text;
										a = dem;
									}
									break;
								}
								case 3: {
									inputText(x + 18, y + 11, 6, rule_cam, sv.phai, 8, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
									}
									else if (input == ENTER)
									{
										loop2 = true;
										while (loop2)
										{
											char k = _getch();
											if (k == ARROW_LEFT)
											{
												if (sv.phai == "Nam")
												{
													sv.phai = "Nu";
													gotoxy(x + 20, y + 12); cout << "   ";
													gotoxy(x + 20, y + 12); cout << "Nu";
												}
												else {
													sv.phai = "Nam";
													gotoxy(x + 20, y + 12); cout << "Nam";
												}
											}
											else if (k == ARROW_RIGHT)
											{
												if (sv.phai == "Nam")
												{
													sv.phai = "Nu";
													gotoxy(x + 20, y + 12); cout << "   ";
													gotoxy(x + 20, y + 12); cout << "Nu";
												}
												else {
													sv.phai = "Nam";
													gotoxy(x + 20, y + 12); cout << "Nam";
												}
											}
											if (k == ENTER)
											{
												loop2 = false;
											}
										}
									}
									a = dem;
									loop2 = true;
									break;
								}
								case 4: {
									inputText(x + 18, y + 14, w / 2, rule_tudo, sv.password, 6, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
									}
									else {
										sv.password = text;
										a = dem;
									}
									break;
								}
								case 5: {
									inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 6, type_input);
									if (input == ESC)
									{
										rsKhungNhapSV(x, y, w);
										dem = 6;
										loop2 = false;
										sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
									}
									if (input == ARROW_DONW || input == ARROW_UP)
									{
										a = dem;
									}
									if (input == ENTER)
									{
										if (sv.ho == "")
										{
											messeger(x, 35, 50, 3, 12, "Ho khong duoc bo trong !", DELAY);
										}
										else if (sv.ten == "")
										{
											messeger(x, 35, 50, 3, 12, "Ten khong duoc bo trong !", DELAY);
										}
										else if (sv.password == "")
										{
											messeger(x, 35, 50, 3, 12, "Password khong duoc bo trong !", DELAY);
										}
										else {
											hieuChinhSinhVien(ds_lop, vitri, sv.masv, sv);
											sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
											messeger(x, 35, 50, 3, 2, "Chinh sua sinh vien thanh cong !", DELAY);
											dem = 6;
											loop2 = false;
											ghiSinhVien(ds_lop);
											rsKhungNhapSV(x, y, w);
										}
									}
									break;
								}
								default:
									break;
								}
							}
						}
					}
					row = dem;
					break;
				}
				case 7: {
					inputText(x + w / 3, y + h + 8, w / 3, rule_cam, "     Xoa", 8, type_input);
					if (input == ESC) chucNangNhapSV(ds_lop, lop, x, y, w, h);
					if (input == ARROW_DONW || input == ARROW_UP)
					{
						row = dem;
					}
					if (input == ENTER)
					{
						loadDSSVChiTiet(ds_lop, sv, vitri, x + w + 10, y + 2, 100, 20, edit);
						rsKhungNhapSV(x, y, w);
						if (!sv.masv.length() == 0)
						{
							loop2 = true;
							while (loop2)
							{
								rectangle(x, 35, 50, 3, 2);
								gotoxy(x + 3, 36);  cout << "Xoa sinh vien co ma " + sv.masv + " ? Y/N";
								char banphim = _getch();
								if (banphim == 89 || banphim == 121) {
									clearMesseger(x, 35, 50, 3);
									if (CheckDiemSV(ds_lop, sv.masv))
									{
										messeger(x, 35, 50, 3, 12, "Khong the xoa sinh vien nay!", DELAY);
									}
									else {
										if (xoaSinhVien(ds_lop, vitri, sv.masv))
										{
											messeger(x, 35, 50, 3, 2, "Xoa thanh cong", DELAY);
											ghiSinhVien(ds_lop);
										}
										else {
											messeger(x, 35, 50, 3, 12, "Xoa that bai", DELAY);
										}
									}
									loop2 = false;
									sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "", sv.password = "";
								}
								else if (banphim == 78 || banphim == 110)
								{
									clearMesseger(x, 35, 50, 3);
									loop2 = false;
								}
								else if (banphim == ESC)
								{
									loop2 = false;
									sv.masv = "", sv.ho = "", sv.ten = "", sv.phai = "Nam", sv.password = "";
									clearMesseger(x, 35, 50, 3);
								}
							}
						}
					}
					break;
				}
				}
			}
		}
		loop1 = false;
	}
}

void loadDSMonHoc(NodeMH*& root, MonHoc& monhoc, int x, int y, int w, int h) {
	//system("cls");
	MonHoc* dsmh[500];
	int nmh = 0;
	tree_to_array(root, dsmh, nmh);
	int slmh = countMonHoc(root);
	int count = 0, end = 15, pageindex = 0;
	int soPage = slmh / 15;
	string inputSearch = "";
	search(x, y - 4, 40, 13);
	giaoDienDSMH(x, y, w, h, 15);
	hightlight(x + w + 1, y + 3);
	xuatDSMH(root, dsmh, nmh, count, x, y);
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
	loop2 = true;
	while (loop2)
	{
		char banphim = _getch();
		switch (banphim)
		{
		case ARROW_DONW: {
			count++;
			if (pageindex == soPage)
			{
				if (count > slmh - soPage * 15 - 1)
				{
					gotoxy(x + w + 1, y + slmh - soPage * 15 + 2); cout << "     ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			else
			{
				if (count > 14)
				{
					gotoxy(x + w + 1, y + 2 + count); cout << "    ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case ARROW_UP: {
			count--;
			if (pageindex == soPage)
			{
				if (count < 0) {
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = slmh - soPage * 15 - 1;
				}
				hightlight(x + w + 1, y + 3 + count);

			}
			else {
				if (count < 0)
				{
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = 14;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case PgDn: {
			pageindex++;
			if (pageindex <= soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				xoaBangLop(x, y, w, h);
				xuatDSMH(root, dsmh, nmh, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			}
			else if (pageindex > soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "     ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = 0;
				xoaBangLop(x, y, w, h);
				xuatDSMH(root, dsmh, nmh, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			}
			break;
		}
		case PgUp: {
			pageindex--;
			if (pageindex < 0)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = soPage;
				xoaBangLop(x, y, w, h);
				xuatDSMH(root, dsmh, nmh, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			}
			else
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "       ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				xoaBangLop(x, y, w, h);
				xuatDSMH(root, dsmh, nmh, 15 * pageindex, x, y);
				gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			}
			break;
		}
		case F1: {
			loop2 = true;
			while (loop2)
			{
				rsRectangle(x + 10, y - 5, 40, 3, 13);
				inputText(x + 10, y - 5, 40, rule_mamh, inputSearch, 1, type_input);
				if (input == ESC) loop2 = false;
				if (input == ENTER)
				{
					inputSearch = text;
					MonHoc* temp = Search(root, inputSearch);
					if (temp->mamh.length() != 0)
					{
						gotoxy(x + w + 1, y + 3 + count); cout << "       ";
						for (int i = 0; i < slmh; i++)
						{
							if (dsmh[i]->mamh.compare(temp->mamh))
							{
								count = i + 1;
								pageindex = i / 15;
							}
						}
						hightlight(x + w + 1, y + 3 + count);
						xoaBangLop(x, y, w, h);
						xuatDSMH(root, dsmh, nmh, 15 * pageindex, x, y);
						gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
						loop2 = false;
					}
					else {
						messeger(15, 30, 50, 3, 12, "Ma mon hoc khong ton tai !", DELAY);
					}
				}
			}
			loop2 = true;
			break;
		}
		case ENTER: {
			monhoc.mamh = dsmh[count + pageindex * 15]->mamh;
			monhoc.tenmh = dsmh[count + pageindex * 15]->tenmh;
			clearMesseger(x, 30, 50, 3);
			clearScreen(x, y - 5, w + 10, h + 15);
			loop2 = false;
			break;
		}
		case ESC: {
			clearMesseger(x, 30, 50, 3);
			clearScreen(x, y - 5, w + 10, h + 15);
			monhoc.mamh = "";
			monhoc.tenmh = "";
			return;
		}
		default:
			break;
		}
	}
}

void chucNangThemMH(int x, int y, int w, int h, NodeMH*& root, DS_LOP ds_lop) {
	MonHoc mh;
	int row = 0, index = 0;
	giaoDienNhapMonHoc(x, y, w, h, 15);
	loop1 = true;
	dem = 0;
	while (loop1)
	{
		switch (row)
		{
		case 0: {
			dem = 0;
			inputText(x + 20, y + 2, w / 2, rule_mamh, mh.mamh, 5, type_input);
			if (input == ESC) return;
			mh.mamh = text;
			row = dem;
			break;
		}
		case 1: {
			inputText(x + 20, y + 5, w / 2, rule_tenmh, mh.tenmh, 5, type_input);
			if (input == ESC) return;
			mh.tenmh = text;
			row = dem;
			break;
		}
		case 2: {
			inputText(x + w / 3, y + h + 2, w / 3, rule_cam, "    Them", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				if (mh.mamh == "")
				{
					messeger(x, 30, 50, 3, 12, "Ma mon hoc khong dc bo trong !", DELAY);
				}
				else if (mh.tenmh == "")
				{
					messeger(x, 30, 50, 3, 12, "Ten mon hoc khong duoc bo trong !", DELAY);
				}
				else 
				{
					MonHoc* ktra = Search(root, mh.mamh);
					if (ktra != null)
					{
						messeger(x, 30, 50, 3, 12, "Ma mon hoc da ton tai!", DELAY);
					}
					else {
						NodeMH* temp = new NodeMH;
						temp = taoNodeMonHoc(mh);
						themMonHoc(root, temp);
						messeger(x, 30, 50, 3, 2, "Them thanh cong !", DELAY);
						rsKhungNhapMH(x, y, w);
						mh.mamh = ""; mh.tenmh = "";
					}
				}
					
			}
			ghiFileDanhSachMonHoc(root);
			ghiFileDSCauHoi(root);
			break;
		}
		case 3: {
			inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				loadDSMonHoc(root, mh, x + 20 + w, y, 75, 20);
				rsKhungNhapMH(x, y, w);
				if (!mh.mamh.length() == 0 && !mh.tenmh.length() == 0) {
					SetColor(13);
					gotoxy(x +22, y + 3); cout << mh.mamh;
					gotoxy(x + 22, y + 6); cout << mh.tenmh;
					dem = 0;
					int a = 0;
					loop2 = true;
					while (loop2)
					{
						switch (a)
						{
						case 0: {
							inputText(x + 20, y + 2, w / 2, rule_cam, mh.mamh, 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapMH(x, y, w);
								dem = 3;
								loop2 = false;
								mh.mamh = ""; mh.tenmh = "";
							}
							a = dem;
							break;
						}
						case 1: {
							inputText(x + 20, y + 5, w / 2, rule_tenmh, mh.tenmh, 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapMH(x, y, w);
								dem = 3;
								loop2 = false;
								mh.mamh = ""; mh.tenmh = "";
							}
							else {
								mh.tenmh = text;
								a = dem;
							}
							break;
						}
						case 2: {
							inputText(x + w / 3, y + h + 5, w / 3, rule_cam, "     Sua", 3, type_input);
							if (input == ESC)
							{
								rsKhungNhapMH(x, y, w);
								dem = 3;
								loop2 = false;
								mh.mamh = ""; mh.tenmh = "";
							}
							if (input == ARROW_DONW || input == ARROW_UP)
							{
								a = dem;
							}
							if (input == ENTER)
							{
								if (mh.tenmh == "")
								{
									messeger(x, 30, 50, 3, 12, "Ten mon hoc khong duoc bo trong !", DELAY);
								}
								else {
									NodeMH* temp = new NodeMH;
									temp = taoNodeMonHoc(mh);
									hieuChinhMonHoc(root, temp);
									mh.mamh = ""; mh.tenmh = "";
									messeger(x, 30, 50, 3, 2, "Chinh sua lop thanh cong !", DELAY);
									dem = 3;
									loop2 = false;
									ghiFileDanhSachMonHoc(root);
									rsKhungNhapMH(x, y, w);
								}
							}
							break;
						}
						default:
							break;
						}
					}
				}
			}
			break;
		}
		case 4: {
			inputText(x + w / 3, y + h + 8, w / 3, rule_cam, "     Xoa", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				loadDSMonHoc(root, mh, x + 20 + w, y, 75, 20);
				rsKhungNhapMH(x, y, w);
				if (!mh.mamh.length() == 0)
				{
					loop2 = true;
					while (loop2)
					{
						rectangle(x, 30, 50, 3, 12);
						gotoxy(x + 2, 31); cout << "Mon hoc co ma " + mh.mamh + " Ban co muon xoa Y/N !";
						char banphim = _getch();
						if (banphim == 89 || banphim == 121) {
							clearMesseger(x, 30, 50, 3);
							if (!camXoa(ds_lop, mh.mamh))
							{
								xoaMonHoc(root, mh.mamh);
							}
							else {
								messeger(x, 30, 50, 3, 12, "Khong the xoa mon hoc nay!", DELAY);
							}
							loop2 = false;
							mh.mamh = ""; mh.tenmh = "";
							ghiFileDanhSachMonHoc(root);
							ghiFileDSCauHoi(root);
						}
						else if (banphim == 78 || banphim == 110)
						{
							clearMesseger(x, 30, 50, 3);
							loop2 = false;
						} 
						if (banphim == ESC)
						{
							clearMesseger(x, 30, 50, 3);
							loop2 = false;
						}
					}
				}
			}
			break;
		}
		}
	}
}

int chuyenDoiSo(string text) {
	int so = 0;
	for (int i = 0; i < text.length(); i++) {
		so = so * 10 + (text[i] - 48);
	}
	return so;
}


void chucNangCauHoi(NodeMH*& root, int x, int y, int w, int h){
	MonHoc monhoc;
	while (true)
	{
		system("cls");
		loadDSMonHoc(root, monhoc, 10, 7, 78, 20);
		if (monhoc.mamh.length() == 0)
		{
			return;
		}
		else
		{
			CAUHOI cauhoi;
			MonHoc* dsmh[500];
			int nmh = 0;
			tree_to_array(root, dsmh, nmh);
			int row = 0, index = 0, i = 0;
			string DA[4] = { "A", "B", "C", "D" };
			giaoDienNhapCauHoi(monhoc.tenmh, x, y, w, h, 13);
			dem = 0;
			loop1 = true;
			while (loop1)
			{
				switch (row)
				{
				case 0: {
					inputText(x + 10, y + 1, w, rule_tudo, cauhoi.noiDung, 7, type_input);
					if (input == ESC) loop1 = false;
					cauhoi.noiDung = text;
					row = dem;
					break;
				}
				case 1: {
					inputText(x + 10, y + h + 2, w, rule_tudo, cauhoi.dapAnA, 7, type_input);
					if (input == ESC) loop1 = false;
					cauhoi.dapAnA = text;
					row = dem;
					break;
				}
				case 2: {
					inputText(x + 10, y + 2 * h + 3, w, rule_tudo, cauhoi.dapAnB, 7, type_input);
					if (input == ESC) loop1 = false;
					cauhoi.dapAnB = text;
					row = dem;
					break;
				}
				case 3: {
					inputText(x + 10, y + 3 * h + 4, w, rule_tudo, cauhoi.dapAnC, 7, type_input);
					if (input == ESC) loop1 = false;
					cauhoi.dapAnC = text;
					row = dem;
					break;
				}
				case 4: {
					inputText(x + 10, y + 4 * h + 5, w, rule_tudo, cauhoi.dapAnD, 7, type_input);
					if (input == ESC) loop1 = false;
					cauhoi.dapAnD = text;
					row = dem;
					break;
				}
				case 5: {
					inputText(x + w / 2 + 1, y + 6 * h + 4, 14, rule_cam, "     " + DA[i], 7, type_input);
					if (input == ESC) loop1 = false;
					row = dem;
					if (input == ENTER)
					{
						loop2 = true;
						while (loop2)
						{
							char k = _getch();
							if (k == ARROW_LEFT)
							{
								i--;
								if (i >= 0)
								{
									gotoxy(x + w / 2 + 8, y + 6 * h + 5); cout << DA[i];
								}
								else if (i < 0)
								{
									i = 3;
									gotoxy(x + w / 2 + 8, y + 6 * h + 5); cout << DA[i];
								}
							}
							else if (k == ARROW_RIGHT)
							{
								i++;
								if (i < 4)
								{
									gotoxy(x + w / 2 + 8, y + 6 * h + 5); cout << DA[i];
								}
								else if (i == 4)
								{
									i = 0;
									gotoxy(x + w / 2 + 8, y + 6 * h + 5); cout << DA[i];
								}
							}
							if (k == ENTER)
							{
								row = dem;
								loop2 = false;
							}
						}
					}
					cauhoi.dapAnDung = DA[i];
					break;
				}
				case 6: {
					inputText(x + w / 2 + 1, y + 8 * h + 4, 14, rule_cam, "   Them", 7, type_input);
					if (input == ESC) loop1 = false;
					if (input == ARROW_DONW || input == ARROW_UP)
					{
						row = dem;
					}
					if (input == ENTER)
					{
						if (cauhoi.noiDung == "" || cauhoi.dapAnA == "" || cauhoi.dapAnB == "" || cauhoi.dapAnC == "" || cauhoi.dapAnD == "" || cauhoi.dapAnDung == "")
						{
							messeger(x, 37, 50, 3, 12, "Thong tin khong duoc bo trong !", DELAY);
						}
						else {
							cauhoi.dapAnA = "A. " + cauhoi.dapAnA;
							cauhoi.dapAnB = "B. " + cauhoi.dapAnB;
							cauhoi.dapAnC = "C. " + cauhoi.dapAnC;
							cauhoi.dapAnD = "D. " + cauhoi.dapAnD;
							duyetDeThemCauHoi(root, monhoc.mamh, cauhoi);
							messeger(x, 37, 50, 3, 2, "Them thanh cong", DELAY);
							ghiFileDSCauHoi(root);
							cauhoi.noiDung = ""; cauhoi.dapAnA = ""; cauhoi.dapAnB = ""; cauhoi.dapAnC = ""; cauhoi.dapAnD = ""; cauhoi.dapAnDung = "";
							i = 0;
							resetNhapCauHoi(x, y, w, h, 13);
						}
					}
					break;
				}
				}
			}
		}
	}
	
}

void chucNangChonDe(DS_LOP& ds_lop, NodeMH* root, MonHoc& monhoc, int x, int y, int w, int h){
	system("cls");
	giaoDienChonDeThi(monhoc.tenmh, x, y, w, h, 15);
	int row = 0, index = 0;
	string phut = "", cauHoi = "";
	int soPhut = 0, soCauHoi = 0;
	dem = 0;
	loop1 = true;
	while (loop1)
	{
		switch (row)
		{
		case 0: {
			dem = 0;
			inputText(x + 20, y + 2, w / 2, rule_so, phut , 3, type_input);
			if (input == ESC) loop1 = false;
			phut = text;
			soPhut = chuyenDoiSo(phut);
			row = dem;
			break;
		}
		case 1: {
			inputText(x + 20, y + 6, w / 2, rule_so, cauHoi, 3, type_input);
			if (input == ESC) loop1 = false;
			cauHoi = text;
			soCauHoi = chuyenDoiSo(cauHoi);
			row = dem;
			break;
		}
		case 2: {
			inputText(x + w / 3, y + h + 2, w / 3, rule_cam, " Bat dau thi", 3, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER)
			{
				if (phut == "", cauHoi == "")
				{
					messeger(x, 30, 40, 3, 12, "THONG TIN KHONG DUOC BO TRONG!", DELAY);
				}
				else 
				{ 
					DSCAUHOI* dsch = new DSCAUHOI;
					layCauHoiMH(root, dsch, monhoc.mamh);
					if (soCauHoi <= dsch->sl)
					{
						chucNangThi(ds_lop, dsch, monhoc, 45, 2, 85, 6, soPhut, soCauHoi);
					}
					else {
						messeger(40, 30, 50, 3, 12, "Danh sach co " + to_string(dsch->sl) + " cau hoi !", DELAY);
					}
				}
			}
			break;
		}
		}
	}
	loop1 = true;
	monhoc.mamh = ""; monhoc.tenmh = "";
}

void chucNangThi(DS_LOP& ds_lop, DSCAUHOI* dsch, MonHoc monhoc, int x, int y, int w, int h, int soPhut, int soCH) {
	system("cls");
	int arr[MAXCAUHOI];
	CAUHOI test[MAXCAUHOI];
	dayNgauNhien(arr, dsch->sl);
	for (int i = 0; i < soCH; i++)
	{
		test[i] = dsch->ds[arr[i]];
	}
	thread timer;
	timer = thread(startTimerJob, soPhut * 60 );
	int CHCurrent = 0;
	giaoDienkhungCauHoi(x, y, w, h);
	thongTinThi(MSSV, hoSV, tenSV, monhoc.tenmh, x, y-1);
	thongTinCauHoi(test[CHCurrent],x, y, w, h);
	SetColor(2);
	gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
	string DA[4] = { "A", "B", "C", "D" };
	int count = -1;
	string dapAnChon[MAXCAUHOI];
	int stt = 0;
	SetColor(2);
	
	loop1 = true;
	while (loop1)
	{
		char banPhim = _getch();
		switch (banPhim)
		{
		case ARROW_LEFT: {
			count--;
			if (count < 0)
			{
				count = 3;
			}
			gotoxy(x + 43, y + 27); cout << DA[count];
			dapAnChon[CHCurrent] = DA[count];
			break;
		}
		case ARROW_RIGHT: {
			count++;
			if (count == 4)
			{
				count = 0;
			}
			gotoxy(x + 43, y + 27); cout << DA[count];
			dapAnChon[CHCurrent] = DA[count];
			break;
		}
		case PgDn: {
			CHCurrent++;
			count = -1;
			xoaKhungCauHoi(x, y, w, h);
			if (CHCurrent > soCH -1)
			{
				CHCurrent = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				if (dapAnChon[CHCurrent] == DA[i]) {
					gotoxy(x + 43, y + 27); cout << DA[i];
					count = i;
				}
			}
			SetColor(2);
			thongTinCauHoi(test[CHCurrent], x, y, w, h);
			gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
			break;
		}
		case PgUp: {
			CHCurrent--;
			count = -1;
			xoaKhungCauHoi(x, y, w, h);
			if (CHCurrent < 0)
			{
				CHCurrent = soCH - 1;
			}
			for (int i = 0; i < 4; i++)
			{
				if (dapAnChon[CHCurrent] == DA[i]) {
					gotoxy(x + 43, y + 27); cout << DA[i];
					count = i;
				}
			}
			SetColor(2);
			thongTinCauHoi(test[CHCurrent], x, y, w, h);
			gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
			break;
		}
		case ENTER: {
			stop = 1;
			int cauDung = 0;
			float diem = 0;
			for (int i = 0; i < soCH; i++)
			{
				if (dapAnChon[i] == test[i].dapAnDung)
				{
					cauDung++;
				}
			}
			if (cauDung == soCH)
			{
				diem = 10;
			}
			else {
				diem = 10.0f / soCH * cauDung;
			}
			DIEM diemMH;
			diemMH.maMh = monhoc.mamh;
			diemMH.diem_thi = diem;
			themDiemSV(ds_lop, MSSV, diemMH);
			ghiFileDiem(ds_lop);
			chucNangXemBaiThi(monhoc,test, dapAnChon,diem, cauDung, soCH, 45, 2, 85, 6);
			loop1 = false;
			break;
		}
		default:
			break;
		}
	}
	timer.join();
	stop = 0;
}

void thiTracNghiem(DS_LOP& ds_lop, NodeMH*& root, int x, int y, int w, int h) {
	MonHoc monhoc;
	while (true)
	{
		system("cls");
		loadDSMonHoc(root, monhoc, x, y, w, h);
		if (monhoc.mamh.length() != 0) {
			if (!camThi(ds_lop, MSSV, monhoc.mamh))
			{
				chucNangChonDe(ds_lop, root, monhoc, 50, 7, 50, 12);
			}
			else {
				messeger(x, 30, 40, 3, 12, "BAN DA THI MON NAY ROI!", DELAY);
			}
		} else{
			return;
		}
	}
	
}

void inDSLOP(DS_LOP& ds_lop, int x, int y, int w, int h) {
	LOP lop;
	loadDSLop(ds_lop, lop, x, y, w, h, edit);
	SINHVIEN sinhvien;
	int vitri = timMaLop(lop.malop, ds_lop);
	if (vitri != -1)
	{
		loadDSSVChiTiet(ds_lop, sinhvien, vitri, x, y, 100, 19, show);
	}
}

void chucNangXemBaiThi(MonHoc monhoc, CAUHOI cauhoi[], string dapAnChon[], float diem, int cauDung, int soCH, int x, int y, int w, int h) {
	int row = 0;
	diemThi(diem,cauDung, soCH, 60, 10, 60, 15);
	loop1 = true;
	while (loop1)
	{
		switch (row)
		{
		case 0: {
			dem = 0;
			inputText(80, 16, 20, rule_cam, "   Xem bai thi", 2, type_input);
			if (input == ESC) return;
			if (input == ENTER)
			{
				system("cls");
				int CHCurrent = 0;
				giaoDienkhungCauHoi(x, y, w, h);
				thongTinThi(MSSV, hoSV, tenSV, monhoc.tenmh, x, y - 1);
				thongTinCauHoi(cauhoi[CHCurrent], x, y, w, h);
				hightlightCH(cauhoi, CHCurrent, x, y, h);
				SetColor(2);
				gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
				string DA[4] = { "A", "B", "C", "D" };
				int count = -1;
				int stt = 0;
				SetColor(2);
				loop1 = true;
				while (loop1)
				{
					char banPhim = _getch();
					switch (banPhim)
					{
					case PgDn: {
						CHCurrent++;
						count = -1;
						xoaKhungCauHoi(x, y, w, h);
						if (CHCurrent > soCH - 1)
						{
							CHCurrent = 0;
						}
						for (int i = 0; i < 4; i++)
						{
							if (dapAnChon[CHCurrent] == DA[i]) {
								gotoxy(x + 43, y + 27); cout << DA[i];
								count = i;
							}
						}
						hightlightCH(cauhoi, CHCurrent, x, y, h);
						SetColor(2);
						thongTinCauHoi(cauhoi[CHCurrent], x, y, w, h);
						gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
						break;
					}
					case PgUp: {
						CHCurrent--;
						count = -1;
						xoaKhungCauHoi(x, y, w, h);
						if (CHCurrent < 0)
						{
							CHCurrent = soCH - 1;
						}
						for (int i = 0; i < 4; i++)
						{
							if (dapAnChon[CHCurrent] == DA[i]) {
								gotoxy(x + 43, y + 27); cout << DA[i];
								count = i;
							}
						}
						hightlightCH(cauhoi, CHCurrent, x, y, h);
						SetColor(2);
						thongTinCauHoi(cauhoi[CHCurrent], x, y, w, h);
						gotoxy(x + 37, y + 30); cout << "Cau hoi " << CHCurrent + 1 << "/" << soCH << " ";
						break;
					}
					case ESC: {
						loop1 = false;
						break;
					}
					default:
						break;
					}
				}
			}
			row = dem;
			break;
		}
		case 1: {
			inputText(80, 19, 20, rule_cam, "      Thoat", 2, type_input);
			if (input == ESC) return;
			if (input == ENTER) return;
			row = dem;
			break;
		}
		}
	}
}

void inBangDiem(DS_LOP& ds_lop, LOP& lop, NodeMH* root, int x, int y, int w, int h) {
	MonHoc monhoc;
	loop = true;
	while (loop)
	{
		loadDSLop(ds_lop, lop, x, y, w, h, edit);
		if (lop.malop.length() != 0)
		{
			loop1 = true;
			while (loop1)
			{
				loadDSMonHoc(root, monhoc, x, y, w, h);
				if (monhoc.mamh.length() != 0)
				{
					bangDiemTheoLop(lop.tenlop, monhoc.tenmh, x, y, w, h, 15);
					mSINHVIEN msv;
					int vitri = timMaLop(lop.malop, ds_lop);
					int slsv = demSV(ds_lop.ds[vitri]->first);
					int count = 0, end = 15, pageindex = 0;
					int soPage = slsv / 15;
					gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
					hightlight(x + w + 1, y + 3);
					xuatDSDiem(ds_lop, msv, monhoc.mamh, vitri, slsv, count, x, y);
					loop2 = true;
					while (loop2)
					{
						char banphim = _getch();
						switch (banphim)
						{
						case ARROW_DONW: {
							count++;
							if (pageindex == soPage)
							{
								if (count > slsv - soPage * 15 - 1)
								{
									gotoxy(x + w + 1, y + slsv - soPage * 15 + 2); cout << "     ";
									count = 0;
								}
								hightlight(x + w + 1, y + 3 + count);
							}
							else
							{
								if (count > 14)
								{
									gotoxy(x + w + 1, y + 2 + count); cout << "    ";
									count = 0;
								}
								hightlight(x + w + 1, y + 3 + count);
							}
							break;
						}
						case ARROW_UP: {
							count--;
							if (pageindex == soPage)
							{
								if (count < 0) {
									gotoxy(x + w + 1, y + 4 + count); cout << "      ";
									count = slsv - soPage * 15 - 1;
								}
								hightlight(x + w + 1, y + 3 + count);
							}
							else {
								if (count < 0)
								{
									gotoxy(x + w + 1, y + 4 + count); cout << "      ";
									count = 14;
								}
								hightlight(x + w + 1, y + 3 + count);
							}
							break;
						}
						case PgDn: {
							pageindex++;
							if (pageindex <= soPage)
							{
								gotoxy(x + w + 1, y + 3 + count); cout << "      ";
								count = 0;
								hightlight(x + w + 1, y + 3 + count);
							}
							else if (pageindex > soPage)
							{
								gotoxy(x + w + 1, y + 3 + count); cout << "     ";
								count = 0;
								hightlight(x + w + 1, y + 3 + count);
								pageindex = 0;
							}
							xoaBangLop(x, y, w, h);
							xuatDSDiem(ds_lop, msv, monhoc.mamh, vitri, slsv, 15 * pageindex, x, y);
							gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
							break;
						}
						case PgUp: {
							pageindex--;
							if (pageindex < 0)
							{
								gotoxy(x + w + 1, y + 3 + count); cout << "      ";
								count = 0;
								hightlight(x + w + 1, y + 3 + count);
								pageindex = soPage;
							}
							else
							{
								gotoxy(x + w + 1, y + 3 + count); cout << "       ";
								count = 0;
								hightlight(x + w + 1, y + 3 + count);
							}
							xoaBangLop(x, y, w, h);
							xuatDSDiem(ds_lop, msv, monhoc.mamh, vitri, slsv, 15 * pageindex, x, y);
							gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
							break;
						}
						case ENTER: {
							break;
						}
						case ESC: {
							loop2 = false;
							system("cls");
							break;
						}
						default:
							break;
						}
					}
				} 
				else{
					loop1 = false;
				}
			}
		}
		else {
			loop = false;
		}
	}
}

void inDiemSV(DS_LOP& ds_lop, string masv, NodeMH*& root, int x, int y, int w, int h) {
	MonHoc* dsmh[100];
	int nmh = 0;
	tree_to_array(root, dsmh, nmh);
	int count = 0, end = 15, pageindex = 0;
	int soPage = nmh / 15;
	giaoDienDiemSV(x, y, w, h);
	hightlight(x + w + 1, y + 3);
	xuatDiemSV(ds_lop, MSSV, dsmh, nmh, count, x, y);
	gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
	loop2 = true;
	while (loop2)
	{
		char banphim = _getch();
		switch (banphim)
		{
		case ARROW_DONW: {
			count++;
			if (pageindex == soPage)
			{
				if (count > nmh - soPage * 15 - 1)
				{
					gotoxy(x + w + 1, y + nmh - soPage * 15 + 2); cout << "      ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			else
			{
				if (count > 14)
				{
					gotoxy(x + w + 1, y + 2 + count); cout << "    ";
					count = 0;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case ARROW_UP: {
			count--;
			if (pageindex == soPage)
			{
				if (count < 0) {
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = nmh - soPage * 15 - 1;
				}
				hightlight(x + w + 1, y + 3 + count);

			}
			else {
				if (count < 0)
				{
					gotoxy(x + w + 1, y + 4 + count); cout << "      ";
					count = 14;
				}
				hightlight(x + w + 1, y + 3 + count);
			}
			break;
		}
		case PgDn: {
			pageindex++;
			if (pageindex <= soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
			}
			else if (pageindex > soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "     ";
				pageindex = 0;
			}
			count = 0;
			hightlight(x + w + 1, y + 3 + count);
			xoaBangLop(x, y, w, h);
			xuatDiemSV(ds_lop, MSSV, dsmh, nmh, 15 * pageindex, x, y);
			gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			break;
		}
		case PgUp: {
			pageindex--;
			if (pageindex < 0)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "      ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = soPage;
			}
			else
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "       ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
			}
			xoaBangLop(x, y, w, h);
			xuatDiemSV(ds_lop, MSSV, dsmh, nmh, 15 * pageindex, x, y);
			gotoxy(x + w / 2 - 5, y + h + 1); cout << "Trang " << pageindex + 1 << "/" << soPage + 1;
			break;
		}
		case ENTER: {
			break;
		}
		case ESC: {
			return;
			break;
		}
		default:
			break;
		}
	}
}