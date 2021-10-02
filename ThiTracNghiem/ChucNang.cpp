#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "mylib.h"
#include "GiaoDien.h"
#include "textField.cpp"
#include "const.h"
#include "khaibao.h"
#include "doc_ghi_file.h"
#include "Lop.h"

#define GV 1
#define SV 2


bool loop, loop1, loop2;
string maLopTemp, tenLopTemp;

void loadDSLop(DS_LOP& ds_lop, int x, int y, int w, int h);
void chucNangGV(DS_LOP& ds_lop, ofstream& fileout);
void clearScreeen(int x, int y, int w, int h);

int checkPass(string account, string password) {
	if (account == "GV" && password == "GV")
	{
		return 1;
	}
	else if (account == "" || password == "") {
		return 2;
	}
	return 0;
}

void chucNangDangNhap(int x, int y, int w, int h, DS_LOP& ds_lop, ofstream& fileout) {
	khungDangNhap(x, y, w, h);
	int row = 0, dn = 0;
	string account = "", password = "";
	loop = true;
	while (loop)
	{
		//char banphim;
		switch (row)
		{
		case 0: {

			inputText(x + 20, y + 2, w / 2, rule_tudo, account, 3, type_input);
			account = text;
			row = dem;
			//if (row < 0) row = 2;
			break;
		}
		case 1: {
			//gotoxy(72, 16); 
			inputText(x + 20, y + 5, w / 2, rule_tudo, password, 3, type_password);
			password = text;
			row = dem;
			//if (row > 2) row = 0;
			break;
		}
		case 2: {
			//gotoxy(72, 16); 
			inputText(x + w / 2 - 6, y + h + 2, 12, rule_cam, "Dang nhap", 3, type_input);
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER && text == "Dang nhap") {
				int who = checkPass(account, password);
				switch (who)
				{
				case 0: {
					messeger(x, 30, 25, 3, 12, "Dang nhap that bai");
					row = dem;
					break;
				}
				case 1: {
					messeger(x, 30, 25, 3, 12, "Dang nhap thanh cong");
					Sleep(1000);
					chucNangGV(ds_lop, fileout);
					loop = false;
					break;
				}
				case 2: {
					messeger(x, 30, 25, 3, 12, "Dang nhap thanh cong");
					Sleep(1000);
					menuSinhVien();
					loop = false;
					break;
				}
				default:
					break;
				}
			}
			break; 
		}
		}
		//loop1 = loop;
	}
}

void chucNangThemLop(int x, int y, int w, int h, DS_LOP& ds_lop, ofstream& fileout) {
	system("cls");
	int row = 0, index = 0;
	string maLop = "", tenLop = "";
	giaoDienNhapLop(x, y, w, h);
	//giaoDienDSLop(x + w + 15, y, 3 * w / 2, 20);
	loop1 = true;
	dem = 0;
	while (loop1)
	{
		switch (row)
		{
		case 0: {
			dem = 0;
			inputText(x + 15, y + 2, w / 2, rule_masv, maLop, 5, type_input);
			if (input == ESC) return;
			maLop = text;
			row = dem;
			break;
		}
		case 1: {
			inputText(x + 15, y + 6, w / 2, rule_tenmh, tenLop, 5, type_input);
			if (input == ESC) return;
			tenLop = text;
			row = dem;
			break;
		}
		case 2: {
			inputText(x, y + h + 2, 10, rule_cam, "Them", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER && text == "Them")
			{
				if (maLop == "")
				{
					messeger(x, 30, 50, 3, 2, "ma lop khong dc bo trong");
					Sleep(1500);
					clearMesseger(x, 30, 50, 3);
				}
				else if (tenLop == "")
				{
					messeger(x, 30, 50, 3, 2, "Ten lop khong duoc bo trong");
					Sleep(1500);
					clearMesseger(x, 30, 50, 3);
				}
				else if (!checkMaLop(maLop, ds_lop))
				{
					themLop(ds_lop, maLop, tenLop);
					messeger(x, 30, 50, 3, 2, "Them thanh cong!");
					Sleep(2000);
					clearMesseger(x, 30, 50, 3);
					maLop = ""; tenLop = "";
				}
				else {
					messeger(x, 30, 50, 3, 2, "Ma lop ton tai!");
					Sleep(2000);
					clearMesseger(x, 30, 50, 3);
				}
			}
			ghiFileDanhSachLop(ds_lop, fileout);
			break;
		}
		case 3: {
			inputText(x + w / 2 - 5, y + h + 2, 10, rule_cam, "Sua", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER && text == "Sua")
			{
				loadDSLop(ds_lop, 80, 7, 75, 20);
				if(!maLopTemp.length() ==0 && !tenLopTemp.length() == 0){
					maLop = maLopTemp;
					tenLop = tenLopTemp;
					SetColor(13);
					gotoxy(x + 17, y + 3); cout << maLop;
					gotoxy(x + 17, y + 7); cout << tenLop;
					dem = 0;
					int a = 0;		
					loop2 = true;
					while (loop2)
					{
						switch (a)
						{
						case 0: {
							inputText(x + 15, y + 2, w / 2, rule_cam, maLop, 3, type_input);
							if (input == ESC)
							{
								gotoxy(x + 17, y + 3); cout << "                       ";
								gotoxy(x + 17, y + 7); cout << "                       ";
								dem = 3;
								loop2 = false;
								maLop = ""; tenLop = "";
							}
							a = dem;
							break;
						}
						case 1: {
							inputText(x + 15, y + 6, w / 2, rule_tenmh, tenLop, 3, type_input);
							if (input == ESC)
							{
								gotoxy(x + 17, y + 3); cout << "                       ";
								gotoxy(x + 17, y + 7); cout << "                       ";
								dem = 3;
								loop2 = false;
								maLop = ""; tenLop = "";
							}
							else {
								tenLop = text;
								a = dem;
							}
							break;
						}
						case 2: {
							inputText(x + w / 2 - 5, y + h + 2, 10, rule_cam, "Sua", 3, type_input);
							if (input == ESC)
							{ 
								gotoxy(x + 17, y + 3); cout << "                       ";
								gotoxy(x + 17, y + 7); cout << "                       ";
								dem = 3;
								loop2 = false;
								maLop = ""; tenLop = "";
							}
							if (input == ARROW_DONW || input == ARROW_UP)
							{
								a = dem;
							}
							if (input == ENTER && text == "Sua")
							{
								if (tenLop == "")
								{
									messeger(x, 30, 50, 3, 2, "Ten lop khong duoc bo trong");
									Sleep(1500);
									clearMesseger(x, 30, 50, 3);
								}
								else {
									hieuChinhLop(ds_lop, maLop, tenLop);
									maLop = ""; tenLop = "";
									messeger(x, 30, 50, 3, 2, "Chinh sua lop thanh cong");
									Sleep(1500);
									clearMesseger(x, 30, 50, 3);
									dem = 3;
									loop2 = false;
									ghiFileDanhSachLop(ds_lop, fileout); 
									gotoxy(x + 17, y + 3); cout << "                       ";
									gotoxy(x + 17, y + 7); cout << "                       ";
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
			inputText(x + w - 10, y + h + 2, 10, rule_cam, "Xoa", 5, type_input);
			if (input == ESC) return;
			if (input == ARROW_DONW || input == ARROW_UP)
			{
				row = dem;
			}
			if (input == ENTER && text == "Xoa")
			{
				maLopTemp = "";
				loadDSLop(ds_lop, 80, 7, 75, 20);
				if (!maLopTemp.length() == 0)
				{
					loop2 = true;
					while (loop2)
					{
						messeger(x, 32, 50, 3, 12, maLopTemp);
						char banphim = _getch();
						clearMesseger(x, 32, 50, 3);
						if (banphim == 89 || banphim == 121) {
							clearScreeen(80, 5, 85, 35);
							xoaLop(ds_lop, maLopTemp);
							clearMesseger(x, 32, 50, 3);
							messeger(x, 32, 50, 3, 2, "Xoa thanh cong");
							Sleep(1000);
							clearMesseger(x, 32, 50, 3);
							loop2 = false;
							tenLop = ""; maLop = "";
							ghiFileDanhSachLop(ds_lop, fileout);
						}
						else if (banphim == 78 || banphim == 110)
						{
							loop2 = false;
						} if (banphim == ESC)
						{
							loop2 = false;
							clearMesseger(x, 32, 50, 3);
							clearScreeen(80, 5, 85, 35);
						}
					}
				}
			}
			break;
		}
		}
	}
}

void chucNangGV(DS_LOP& ds_lop, ofstream& fileout) {
	loop = true;
	while (loop)
	{
		system("cls");
		menuGiangVien();
		char luaChon = _getch();
		switch (luaChon)
		{
		case 49: { // 1
			chucNangThemLop(15, 7, 50, 11, ds_lop, fileout);
			break;
		}
		case 50: { // 2
			system("cls");
			loadDSLop(ds_lop, 45, 7, 75, 20);
			break;
		}
		case 51: { //  3

			loop1 = true;
			while (loop1)
			{
				char banphim = _getch();
				switch (banphim)
				{
				case 45: { // Insert

					break;
				}
				case 75: { // F2 Sua

					break;
				}
				case 46: { // delete

					break;
				}
				case 33: { // PgUp

					break;
				}
				case 34: {// PgDn

					break;
				}
				case 27: { // Esc
					loop1 = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 52: { //  4

			loop1 = true;
			while (loop1)
			{
				char temp = _getch();
				switch (temp)
				{
				case 13: { // Enter
					loop2 = true;
					while (loop2)
					{

						char banphim = _getch();
						switch (banphim)
						{
						case 27: { // Esc
							loop2 = false;
							loop1 = false;
							break;
						}
						default:
							break;
						}
					}
					break;
				}
				case 27: { // Esc
					loop1 = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 53: { //  5

			loop1 = true;
			while (loop1)
			{
				char temp = _getch();
				switch (temp)
				{
				case 13: {
					loop2 = true;
					while (loop2)
					{

						char banphim = _getch();
						switch (banphim)
						{
						case 27: { // Esc
							loop2 = false;
							loop1 = false;
							break;
						}
						default:
							break;
						}
					}
					break;
				}
				case 27: { // Esc
					loop1 = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 54: { //  6
			loop1 = true;
			while (loop1)
			{

				char banphim = _getch();
				switch (banphim)
				{
				case 13: {
					loop2 = true;
					while (loop2)
					{

						char temp = _getch();
						if (temp == 27) {
							loop1 = false;
							loop2 = false;
						}
					}
					break;
				}
				case 27: { // Esc
					loop1 = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 55: { //  7
			loop1 = true;
			while (loop1)
			{

				char banphim = _getch();
				switch (banphim)
				{
				case 13: {
					loop2 = true;
					while (loop2)
					{

						char temp = _getch();
						if (temp == 27)
						{
							loop1 = false;
							loop2 = false;
						}
					}
					break;
				}
				case 27: { // Esc
					loop1 = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		default:
			break;
		}
		if (luaChon == 27) {
			system("cls");
			chucNangDangNhap(50, 10, 60, 10, ds_lop, fileout);
		}
	}
}

void loadDSLop(DS_LOP& ds_lop, int x, int y, int w, int h) {
	//system("cls");
	int count = 0, end = 15, pageindex = 0;
	int soPage = ds_lop.sl / 15;
	giaoDienDSLop(x, y, w, h);
	hightlight(x + w + 1, y + 3);
	xuatDanhSachLop(ds_lop, count, x, y);
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
				xuatDanhSachLop(ds_lop, 15 * pageindex, x ,y);
			}
			else if (pageindex > soPage)
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "     ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				pageindex = 0;
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 0, x , y);
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
				xuatDanhSachLop(ds_lop, 15 * pageindex, x , y);
			}
			else
			{
				gotoxy(x + w + 1, y + 3 + count); cout << "       ";
				count = 0;
				hightlight(x + w + 1, y + 3 + count);
				xoaBangLop(x, y, w, h);
				xuatDanhSachLop(ds_lop, 15 * pageindex, x ,y);
			}
			break;
		}
		case ENTER: {
			maLopTemp = ds_lop.ds[count + pageindex * 15]->malop;
			tenLopTemp = ds_lop.ds[count + pageindex * 15]->tenlop;
			loop2 = false;
		}
		case ESC: {
			clearMesseger(x, 32, 50, 3);
			clearScreeen(x, y - 2, w + 10, h + 10);
			return;
		}
		default:
			break;
		}
	}
}

void clearScreeen(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			gotoxy(x + j, y + i); cout << " ";
		}
	}
}

//void xuLyChuongTrinh() {
//
//	int quyen(GV);
//	switch (quyen) {
//	case GV: {
//		loop = true;
//		while (loop)
//		{
//			menuGiangVien();
//			char luaChon = _getch();
//			switch (luaChon)
//			{
//			case 49: { // 1
//				system("cls");
//				loop1 = true;
//				while (loop1)
//				{
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 45: { // Insert
//
//						break;
//					}
//					case 75: { // F2 Sua
//
//						break;
//					}
//					case 46: { // delete
//
//						break;
//					}
//					case 33: { // PgUp
//
//						break;
//					}
//					case 34: {// PgDn
//
//						break;
//					}
//
//					case 27: {
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 50: { // 2
//
//				loop1 = true;
//				while (loop1)
//				{
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 45: { // Insert
//
//						break;
//					}
//					case 75: { // F2 Sua
//
//						break;
//					}
//					case 46: { // delete
//
//						break;
//					}
//					case 33: { // PgUp
//
//						break;
//					}
//					case 34: {// PgDn
//
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 51: { //  3
//
//				loop1 = true;
//				while (loop1)
//				{
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 45: { // Insert
//
//						break;
//					}
//					case 75: { // F2 Sua
//
//						break;
//					}
//					case 46: { // delete
//
//						break;
//					}
//					case 33: { // PgUp
//
//						break;
//					}
//					case 34: {// PgDn
//
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 52: { //  4
//
//				loop1 = true;
//				while (loop1)
//				{
//					char temp = _getch();
//					switch (temp)
//					{
//					case 13: { // Enter
//						loop2 = true;
//						while (loop2)
//						{
//
//							char banphim = _getch();
//							switch (banphim)
//							{
//							case 27: { // Esc
//								loop2 = false;
//								loop1 = false;
//								break;
//							}
//							default:
//								break;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 53: { //  5
//
//				loop1 = true;
//				while (loop1)
//				{
//					char temp = _getch();
//					switch (temp)
//					{
//					case 13: {
//						loop2 = true;
//						while (loop2)
//						{
//
//							char banphim = _getch();
//							switch (banphim)
//							{
//							case 27: { // Esc
//								loop2 = false;
//								loop1 = false;
//								break;
//							}
//							default:
//								break;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 54: { //  6
//				loop1 = true;
//				while (loop1)
//				{
//
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 13: {
//						loop2 = true;
//						while (loop2)
//						{
//
//							char temp = _getch();
//							if (temp == 27) {
//								loop1 = false;
//								loop2 = false;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 55: { //  7
//				loop1 = true;
//				while (loop1)
//				{
//
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 13: {
//						loop2 = true;
//						while (loop2)
//						{
//
//							char temp = _getch();
//							if (temp == 27)
//							{
//								loop1 = false;
//								loop2 = false;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			default:
//				break;
//			}
//			if (luaChon == 27) {
//				return;
//			}
//		}
//		break;
//	}
//	case SV: {
//		loop = true;
//		while (loop)
//		{
//			menuSinhVien();
//			char luaChon = _getch();
//			switch (luaChon)
//			{
//			case 49: { // 1
//
//				loop1 = true;
//				while (loop1)
//				{
//					char temp = _getch();
//					switch (temp)
//					{
//					case 13: {
//						loop2 = true;
//						while (loop2)
//						{
//
//							char banphim = _getch();
//							switch (banphim)
//							{
//							case 27: { // Esc
//								loop2 = false;
//								loop1 = false;
//								break;
//							}
//							default:
//								break;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			case 50: { // 2
//				loop1 = true;
//				while (loop1)
//				{
//
//					char banphim = _getch();
//					switch (banphim)
//					{
//					case 13: {
//						loop2 = true;
//						while (loop2)
//						{
//
//							char temp = _getch();
//							if (temp == 27) {
//								loop1 = false;
//								loop2 = false;
//							}
//						}
//						break;
//					}
//					case 27: { // Esc
//						loop1 = false;
//						break;
//					}
//					default:
//						break;
//					}
//				}
//				break;
//			}
//			default:
//				break;
//			}
//			if (luaChon == 27) {
//				return;
//			}
//		}
//		break;
//	}
//	}
//}