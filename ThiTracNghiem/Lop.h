#pragma once
#include <conio.h>
#include "khaibao.h"
#include "doc_ghi_file.h"


int timMaLop(string a, DS_LOP ds_lop);
//==========================

//them lop
void themLop(DS_LOP& ds_lop, string& maLop, string& tenLop)
{
	LOP* p = new LOP;
	p->malop = maLop;
	p->tenlop = tenLop;
	ds_lop.ds[ds_lop.sl] = p;
	ds_lop.sl++;
}
//xuat ds lop
void xuatDanhSachLop(DS_LOP& ds_lop, int index, int x, int y)
{
	int dem = 0;
	SetColor(15);
	SetBGColor(32);
	if (ds_lop.sl < 15) {
		for (int i = 0; i < ds_lop.sl; i++)
		{
			gotoxy(x + 2, y + 3 + i); cout << i+ 1;
			gotoxy(x + 15, y + 3 + i); cout << ds_lop.ds[i]->malop;
			gotoxy(x + 45, y + 3 + i); cout << ds_lop.ds[i]->tenlop;
		}
	}
	else
	{
		if (ds_lop.sl - index < 15)
		{
			dem = 0;
			for (int i = index; i < ds_lop.sl; i++)
			{
				gotoxy(x + 2, 10 + dem ); cout << i+1;
				gotoxy(x + 15, 10 + dem ); cout << ds_lop.ds[i]->malop;
				gotoxy(x + 45, 10 + dem ); cout << ds_lop.ds[i]->tenlop;
				dem++;
			}
		} 
		else 
		{
			dem = 0;
			for (int i = index; i < index + 15; i++)
			{
				gotoxy(x + 2, 10 + dem); cout << i + 1;
				gotoxy(x + 15, 10 + dem ); cout << ds_lop.ds[i]->malop;
				gotoxy(x + 45, 10 + dem); cout << ds_lop.ds[i]->tenlop;
				dem++;
			}
		}
		
	}
}
//xoa lop
bool xoaLop(DS_LOP& ds_lop, string& a)
{
	int viTri = timMaLop(a, ds_lop);
	if (viTri == -1)
	{
		return false;
	}
	else if (ds_lop.ds[viTri]->first != NULL)
	{
		return false;
	}
	else
	{
		delete  ds_lop.ds[viTri];
		for (int i = viTri + 1; i < ds_lop.sl; i++) 
		ds_lop.ds[i - 1] = ds_lop.ds[i];
		ds_lop.sl--;
		return true;
	}
}
// chinh sua lop
void hieuChinhLop(DS_LOP& ds_lop, string& a, string& tenLop)
{
	int viTri = timMaLop(a, ds_lop);
	if (viTri == -1)
	{
		return;
	}
	else
	{
		ds_lop.ds[viTri]->tenlop = tenLop;
		return;
	}
}

int timMaLop(string a, DS_LOP ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i]->malop == a)
		{
			return i;
		}
	}
	return -1;
}

bool checkMaLop(string a, DS_LOP ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds[i]->malop == a)
		{
			return true;
		}
	}
	return false;
}

void xoaLop(DS_LOP& ds_lop)
{
	string a;
	cout << "Nhap ma lop: ";
	cin >> a;
	int viTri = timMaLop(a, ds_lop);
	if (viTri == -1)
	{
		cout << "Ma lop khong co trong danh sach" << endl;
		system("pause");
	}
	else if (ds_lop.ds[viTri]->first != NULL)
	{
		cout << "Lop co sinh vien ko duoc xoa" << endl;
		system("pause");
	}
	else
	{
		delete  ds_lop.ds[viTri];
		for (int i = viTri + 1; i < ds_lop.sl; i++)
			ds_lop.ds[i - 1] = ds_lop.ds[i];
		ds_lop.sl--;
		cout << "Xoa thanh cong" << endl;
		system("pause");
	}
}

